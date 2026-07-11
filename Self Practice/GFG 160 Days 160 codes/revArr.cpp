#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &v,int i,int j){
    int temp=v.at(i);
    v.at(i)=v.at(j);
    v.at(j)=temp;
}

void rev(vector<int> &v,int low,int high){
    while(low<high){
        swap(v,low++,high--);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,3,4,5};
    rev(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    } 
    return 0;
}