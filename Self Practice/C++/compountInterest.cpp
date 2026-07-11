#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout<<"Enter principal amount, rate of interest and time period:\n";
    double p,r,t;
    cin>>p>>r>>t;
    double ci=p+p*(pow((1+r/100),t));
    cout<<"The amount returned after added interest compounded anually is: "<<ci;
    return 0;
}