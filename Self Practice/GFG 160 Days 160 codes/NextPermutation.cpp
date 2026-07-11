#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &v,int i,int j){
    int temp=v.at(i);
    v.at(i)=v.at(j);
    v.at(j)=temp;
}

void reverse(vector<int> &v,int low,int high){
    while(low<high){
        swap(v,low++,high--);
    }
}

void nextPermutation(vector<int> &v,int n){
    int pivot=-1;
    for(int i=n-1;i>0;i--){
        if(v.at(i)>v.at(i-1)){
            pivot=i-1;
            break;
        }
    }
    if(pivot==-1){
        reverse(v,0,n-1);
        return;
    }
    for(int i=n-1;i>pivot;i--){
        if(v.at(i)>v.at(pivot)){
            swap(v,i,pivot);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,3,4,5};
    int n=v.size();
    nextPermutation(v,n);
    for(const int &n: v){
        cout<<n<<" ";
    } 
    return 0;
}