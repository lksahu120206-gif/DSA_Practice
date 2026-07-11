#include <iostream>
using namespace std;

int main(){
    cout<<"Enter any year: "<<"\n";
    int y;
    cin>>y;
    if(y%100==0&&y%400==0)
    cout<<"leap year"<<"\n";
    else if(y%4==0&&y%100!=0)
    cout<<"leap year"<<"\n";
    else
    cout<<"not leap year"<<"\n";
}