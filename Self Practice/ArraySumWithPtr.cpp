#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={1,5,10,15,20};
    int *ptr=arr;
    int n=sizeof(arr)/sizeof(arr[0]),sum=0;
    for(int i=0;i<n;i++){
        sum+=*(ptr+i);
    }
    cout<<"Sum of all the elemenets= "<<sum<<"\n";
    return 0;
}