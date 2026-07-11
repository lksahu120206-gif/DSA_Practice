#include <bits/stdc++.h>
using namespace std;

int MP(vector<int> v,int n){
    int res=0;
    for(int i=0;i<n-1;i++){
        if(v.at(i)<v.at(i+1)){
            res+=v.at(i+1)-v.at(i);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,3,4,5};
    int mp=MP(v,v.size());
    cout<<"Max profit is: "<<mp<<"\n";
    return 0;
}