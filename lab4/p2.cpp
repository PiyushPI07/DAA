#include <bits/stdc++.h>
using namespace std;

int findMajority(int arr[],int low,int high)
{
    int mid = (low + high) / 2;

    if(high == low)
        return arr[low];

    int a1 = findMajority(arr, low, mid);
    int a2 = findMajority(arr,mid+1, high);

    int l = mid - low;
    int k = high - mid;

    int c1 = 0, c2 = 0, i;
    for(i = 0;i < high-low;i++)
    {
        if(arr[i] == a1)
            c1++;
    }

    for(i = 0;i < high - low;i++)
    {
        if(arr[i] == a2)
            c2++;
    }
  
    if(c1 >= (high - low) / 2)
        return a1;
    else if(c2 >= (high - low) / 2)
        return a2;
    else
        return -1;
}

int main()
{
    int n,i,j,k;
    cout<<"Enter Size : ";
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++)
        cin>>arr[i];
    cout<<findMajority(arr,0, n);
}