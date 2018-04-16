#include <bits/stdc++.h>
using namespace std;

const int n=6;
list <int> a[n];
list <int> l;
list <int> l1;
int prereq[n]={};
int discovered[n]={};

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

void DFS(int i){
	if(discovered[i]==0){
		discovered[i]=1;
		list <int> :: iterator it;
		for(it = a[i].begin(); it != a[i].end(); ++it){
			prereq[*it]++;
			DFS(*it);
		}
		if(prereq[i]==0){
			l.push_back(i);
		}
		
	}
}

int main(){
	a[0].push_back(1);
	a[0].push_back(4);

	a[1].push_back(2);
	a[1].push_back(3);
	
	a[5].push_back(2);
		
	
	for(int i=0;i<n;i++)
		DFS(i);

	int k=0;
	while(l.size()!=0){
		l1.clear();
		for(int i=0;i<l.size();i++){
			l1.push_back(l.front());
			l.pop_front();
		}
		l.clear();
		list <int> :: iterator i1,i2;
		for(i1 = l1.begin(); i1 != l1.end(); ++i1){
			for(i2 = a[*i1].begin(); i2 != a[*i1].end(); ++i2){
				prereq[*i2]--;
				if(prereq[*i2]==0)
					l.push_back(*i2);
			}
		}
		k++;
	}
	cout<<"No. of semesters needed = "<<k<<endl;
}