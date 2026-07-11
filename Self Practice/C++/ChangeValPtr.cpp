#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number=50;
    cout<<"Number before change: "<<number<<"\n";
    int *num_ptr=&number;
    *num_ptr=99;
    cout<<"Number after change: "<<number<<"\n";
    return 0;
}