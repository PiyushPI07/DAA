#include <bits/stdc++.h>
using namespace std;

void find(int a[],int l,int h){
	if(l<h){
		int m=(l+h)/2;
		cout<<l<<", "<<h<<endl;
		if(a[m]==m)
			cout<<a[m]<<endl;
		else if(a[m]<m)
			find(a,m+1,h);
		else
			find(a,l,m);
	}
}

int main(){
	int n,l,h;
	cout<<"Enter limit: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	find(a,0,n);
}
