#include <bits/stdc++.h>
using namespace std;

void max(int a[],int l,int h){
	if(l<h){
		int m=(l+h)/2;
		if (a[m]>a[l])
			max(a,m,h);
		else
			max(a,l,m);
	}
    if (l==h)
        cout<<endl<<a[l];

}

int main(){
	int n,l,h;
	cout<<"Enter limit: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	max(a,0,n-1);
}
