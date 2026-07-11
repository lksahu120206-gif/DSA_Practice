#include <iostream>
using namespace std;

int main(){
    cout<<"Enter 2 numbers: "<<"\n";
    double a,b;
    int ip;
    cin>>a>>b;
    cout<<"Enter 1 to add them\nEnter 2 to subtract them\nEnter 3 to multiply them\nEnter 4 to divide them"<<"\n";
    cin>>ip;
    switch(ip){
        case 1:
        cout<<a+b<<"\n";
        break;
        case 2:
        cout<<a-b<<"\n";
        break;
        case 3:
        cout<<a*b<<"\n";
        break;
        case 4:
        if(b==0){
            cout<<"Division by 0 not possible."<<"\n";
        }
        cout<<a/b<<"\n";
    }
    return 0;
}