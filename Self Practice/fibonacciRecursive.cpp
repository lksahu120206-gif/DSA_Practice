#include <iostream>
using namespace std;

int fib(int n){
    if(n==1){
        return 0;
    }
    return fib(n-2)+fib(n-1);
}

int main(){
    cout<<"Which term do you want?:"<<" ";
    int n;
    cin>>n;
    int nthTerm=fib(n);
    cout<<nthTerm<<"\n";
    return 0;
}