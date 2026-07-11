#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int *safe_ptr=nullptr;
    if(safe_ptr==NULL){
        cout<<"Pointer is null, cannot dereference"<<"\n";
    }
    int valid_data=77;
    safe_ptr=&valid_data;
    if(safe_ptr!=nullptr){
        cout<<"Pointer is now valid. Dereferenced value: "<<*safe_ptr<<"\n";
    }
    return 0;
}