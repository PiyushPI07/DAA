// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


void solveHanoi(int n,char S,char I,char T){
	if(n==0) return;
	solveHanoi(n-1,S,T,I);
	cout<<"Move disc "<<n<<" from "<<S<<" to "<<T<<endl;
	solveHanoi(n-1,S,T,I);

}

int main(){
	cout<<"Enter n.\n";
	int n;
	cin>>n;
	char S='S';
	char I='I';
	char T='T';
	
	solveHanoi(n,S,I,T);
}