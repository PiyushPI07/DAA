#include <iostream>
using namespace std;
main(){
	int n=3,i,j,k,cp,np,mc=0;
	int mf[n]={-1,-1,-1},wf[n]={-1,-1,-1},p[n][n]={};
	for(i=0;i<n;i++){
		cout<<"("<<i<<","<<mf[i]<<") ";
	}
	int mp[n][n]={	0,2,1,
					1,0,2,
					1,2,0};
	int wp[n][n]={	1,0,2,
					1,2,0,
					0,1,2};
	// cout<<"Enter preferences of men";
	// for(int i=0;i<n;i++){
	// 	cout<<"Man "<<i;
	// 	for(int j=0;j<n;j++)
	// 		cin>>mp[i][j];
	// }
	// 	cout<<endl;
	// cout<<"Enter preferences of women";
	// for(int i=0;i<n;i++)
	// 	{cout<<"Woman "<<i;
	// 	for(int j=0;j<n;j++)
	// 		cin>>wp[i][j];
	// 	cout<<endl;}
	i=0;
	while(mc!=3){
		if(mf[i]==-1){
			for(j=0;j<n;j++)
				if (p[i][mp[i][j]]==0) break;				//1st unproposed woman in pref 
			j=mp[i][j];
			p[i][j]=1;
			if (wf[j]==-1){									//women free
				mf[i]=j;
				wf[j]=i;
				cout<<endl<<"("<<i<<","<<j<<")";
				mc++;
			}
			else{
				for(k=0;k<n;k++){
					if(wp[j][k]==wf[j]) break;				//current partner
				}
				cp=k;
				for(k=0;k<n;k++){
					if(wp[j][k]==i) break;					//new partner
				}
				np=k;
				if(np<cp){									//prefers new partner
					mf[cp]=-1;
					mf[np]=j;
					wf[j]=i;
					cout<<endl<<"("<<i<<","<<j<<")";
				}
				else	continue;
			}
		}
		i=(i+1)%3;
	}
	cout<<endl<<"The pairs are: ";
	for(i=0;i<n;i++){
		cout<<"("<<i<<","<<mf[i]<<") ";
	}
}
