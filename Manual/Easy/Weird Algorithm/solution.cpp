#include <iostream>
using namespace std;
 
void change(long long &n){
    while(n!=1){
        if(n%2==0){
        n/=2;
        cout<<n<<" ";
    }
    else if(n%2==1){
        n=n*3+1;
        cout<<n<<" ";
    }
    else if(n==1){
        return;
    }
    }
}
 
int main(){
    long long n;
    cin>>n;
    cout<<n<<" ";
    change(n);
    return 0;
}