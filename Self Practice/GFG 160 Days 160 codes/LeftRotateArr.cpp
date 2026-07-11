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
void LRot(vector<int> &v,int d,int n){
    d%=n;
    rev(v,0,d-1);
    rev(v,d,n-1);
    rev(v,0,n-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,3,4,5};
    int n=v.size();
    LRot(v,54,n);
    for(const int &n: v){
        cout<<n<<" ";
    }
    return 0;
}