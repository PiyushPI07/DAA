#include <bits/stdc++.h>
using namespace std;

struct Interval{
	int start;
	int end;
};

bool compareInterval(Interval i1, Interval i2)
{
	if(i1.end==i2.end)
		return (i1.start<i2.start);
    return (i1.end < i2.end);
}

int main(){
	cout<<"Enter no. of intervals:";
	int i,n;
	cin>>n;
	Interval I[n];
	vector<Interval> Int;
	vector<Interval> Resource;
	Interval interval;
	for(i=0;i<n;i++){
		cin>>I[i].start>>I[i].end;
	}
	sort(I,I+n,compareInterval);
	int c=0,j=1;
	while(c!=n){
		int t=0;
		for(i=0;i<n;i++){
			if(I[i].start!=-1 && t<=I[i].start){
				Int.push_back(I[i]);
				t=I[i].end;
				I[i].start=-1;
				c++;
			}
		}
		cout<<"Resource "<<j<<": " ;
		for(i=0;i<Int.size();i++){
			cout<<"["<<Int[i].start<<", "<<Int[i].end<<"], ";
		}
		cout<<endl;
		j++;
		Int.clear();
	}
}