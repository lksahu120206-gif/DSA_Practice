#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter 2 numbers: "<<endl;
    cin>>a>>b;
    cout<<"Numbers before swapping: a="<<a<<" b= "<<b<<endl;
    int temp=a;
    a=b;
    b=temp;
    cout<<"Numbers after swapping: a="<<a<<" b= "<<b;
    return 0;
}