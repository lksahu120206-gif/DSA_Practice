#include <iostream>
using namespace std;
bool isPal(int n){
    int rev=0,temp=n;
    while(temp>0){
        rev=rev*10+temp%10;
        temp/=10;
    }
    if(rev==n)
    return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter a number: "<<"\n";
    cin>>n;
    if(isPal(n)){
        cout<<"Number entered is a palindrome."<<"\n";
    }
    else{
        cout<<"Number entered is not a palindrome."<<"\n";
    }
    return 0;
}