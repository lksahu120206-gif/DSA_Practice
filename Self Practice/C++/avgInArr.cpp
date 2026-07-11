#include <iostream>
using namespace std;

double avg(int arr[],int size){
    double cnt=0,sum=0;
    for (int i=0;i<size;i++){
        sum+=arr[i];
        cnt++;
    }
    double avg=sum/cnt;
    return avg;
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    double average=avg(arr,size);
    cout<<"Average of the elements in the array = "<<average<<"\n";
    return 0;
}