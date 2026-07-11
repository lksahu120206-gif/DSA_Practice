#include <bits/stdc++.h>
using namespace std;

void increment_value(int *n){
    if(n!=nullptr)
    *n+=10;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=10;
    int *ptr=&n;
    cout<<n<<"\n";
    increment_value(ptr);
    cout<<n<<"\n";
    return 0;
}
