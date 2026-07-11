#include <bits/stdc++.h>
using namespace std;

int MP1(vector<int> v,int n){
    int mini=v.at(0),res=0;
    for(int i=1;i<n;i++){
        mini=min(mini,v.at(i));
        res=max(res,v.at(i)-mini);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,3,4,5};
    int mp=MP1(v,v.size());
    cout<<"Max profit is: "<<mp<<"\n";
    return 0;
}