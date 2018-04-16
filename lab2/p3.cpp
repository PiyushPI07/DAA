#include <bits/stdc++.h>
using namespace std;
int *a;
int split(int low,int mid,int high){
	int x[mid-low],y[high-mid],i;
	int X=mid-low;
	int Y=high-mid;
	for(i=0;i<X;i++){
		x[i]=a[i+low];
	}
	for(i=0;i<Y;i++){
		y[i]=a[i+mid];
	}
	int l=0,r=0,c=0;
	i=low;
	while(l<X && r<Y){
		if(x[l]>y[r]){
			a[i]=y[r];
			r++;
			c=c+X-l;
		}
		else{
			a[i]=x[l];
			l++;
		}
		i++;
		
	}
	while(l<X){
		a[i]=x[l];
		l++;
		i++;

	}
	while(r<Y){
		a[i]=y[r];
		r++;
		i++;
	}
	return c;
}

int inversion(int l,int h){
	if(l<h-1){
		int m=(l+h)/2;
		int i1=inversion(l,m);
		int i2=inversion(m,h);
		int i3=split(l,m,h);
		return i1+i2+i3;
	}
	else return 0;
}

main(){
	int n;
	cout<<"Enter limit: ";
	cin>>n;
	a=new int[n];
	
	cout<<"Enter numbers: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Total inversions are: "<<inversion(0,n)<<endl;
}