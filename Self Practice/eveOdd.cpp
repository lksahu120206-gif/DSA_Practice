#include <iostream>
using namespace std;

int main(){
    cout<<"Enter a number: "<<"\n";
    int n;
    cin>>n;
    if(n&1==1){
        cout<<"Number entered is odd."<<"\n";
    }
    else
    cout<<"Number entered is even."<<"\n";
    return 0;
}