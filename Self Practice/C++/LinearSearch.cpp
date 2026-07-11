#include <bits/stdc++.h>
using namespace std;

bool LinSearch(int arr[],int n,int key){
    bool flag=false;
    for (int i=0;i<n;i++){
        if(arr[i]==key){
            flag=true;
            break;
        }
    }
    return flag;
}

int main(){
    int arr[]={1,2,3,4,5};
    int key=6;
    int size=sizeof(arr)/sizeof(arr[0]);
    bool found=LinSearch(arr,size,key);
    if(found){
        cout<<"Element present."<<"\n";
    }
    else{
        cout<<"Element not found."<<"\n";
    }
    return 0;
}