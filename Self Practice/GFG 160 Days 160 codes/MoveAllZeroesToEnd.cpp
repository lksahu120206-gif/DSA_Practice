#include <bits/stdc++.h>
using namespace std;

void move(vector<int> &v,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v.at(i)!=0){
            v.at(cnt++)=v.at(i);
        }
    }
    for(int i=cnt;i<n;i++){
        v.at(i)=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,0,2,0,3};
    move(v,v.size());
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    return 0;
}