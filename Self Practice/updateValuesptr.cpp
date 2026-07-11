#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cout<<"Input two numbers: ";
    int a,b;
    cin>>a>>b;
    cout<<"Before swapping, a="<<a<<" and b= "<<b<<"\n";
    swap(a,b);
    cout<<"After swapping, a= "<<a<<" and b= "<<b<<"\n";
    return 0;
}