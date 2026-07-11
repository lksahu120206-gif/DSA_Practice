#include <iostream>
#include <climits>
using namespace std;

int findMin(int arr[],int n){
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
int findMax(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if (max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int min=findMin(arr,size);
    int max=findMax(arr,size);
    cout<<"Min value= "<<min<<"\nMax value= "<<max<<"\n";
    return 0;
}