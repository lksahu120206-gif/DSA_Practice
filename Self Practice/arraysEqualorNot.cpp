#include <bits/stdc++.h>
using namespace std;

bool checkArrays(int arr1[],int arr2[],int n,int m){
    if(n!=m){
        return false;
    }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr1[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp.find(arr2[i])==mp.end())
        return false;
        if(mp[arr2[i]]==0)
        return false;
        mp[arr2[i]]--;
    }
    return true;
}

int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={5,3,4,2,1};
    int N=sizeof(arr1)/sizeof(arr1[0]);
    int M=sizeof(arr2)/sizeof(arr2[0]);
    if(checkArrays(arr1,arr2,N,M)){
        cout<<"Equal";
    }
    else{
        cout<<"Not equal";
    }
    return 0;
}