#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter 3 numbers: "<<"\n";
    cin>>a>>b>>c;
    if(a>b&&a>c)
    cout<<a<<" is the greatest number."<<"\n";
    else if (b>a&&b>c)
    {
        cout<<b<<" is the greatest number."<<"\n";
    }
    else
    cout<<c<<" is the greatest number."<<"\n";
    
}