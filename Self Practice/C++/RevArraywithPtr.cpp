#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numbers[]={1,2,3,4,5};
    int *arr_ptr=numbers;
    int n=sizeof(numbers)/sizeof(numbers[0]);
    for(int i=n-1;i>=0;i--){
        cout<<*(arr_ptr+i)<<" ";
    }
    return 0;
}