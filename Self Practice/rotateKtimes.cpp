#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void reverse(int arr [],int low,int high){
    while(low<high){
        swap(arr,low++,high--);
    }
}

void rotate(int arr [],int d,int n){
    d%=n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<"How many times do you want to rotate?:"<<" ";
    int d;
    cin>>d;
    int size=sizeof(arr)/sizeof(arr[0]);
    rotate(arr,d,size);
    cout<<"After rotating array: ";
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}