#include <bits/stdc++.h>
using namespace std;

vector<int> MajEle(vector<int> &arr,int n){
    int ele1=-1,ele2=-1,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        int ele=arr.at(i);
        if(ele1==ele){
            cnt1++;
        }
        else if(ele2==ele){
            cnt2++;
        }
        else if(cnt1==0){
            ele1=ele;
            cnt1++;
        }
        else if(cnt2==0){
            ele2=ele;
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0,cnt2=0;
    for(int x:arr){
        if(x==ele1) cnt1++;
        else if(x==ele2) cnt2++;
    }
    vector<int> res;
    if(cnt1>n/3){
        res.push_back(ele1);
    }
    if(cnt2>n/3){
        res.push_back(ele2);
    }
    if(res.size()>1&&res.at(0)>res.at(1)){
        std::swap(res.at(0),res.at(1));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,2,1,2,1,2,1,2,3,3,3,3,3,3,3,2,1,1,1,2,2,2,3,3,3,3};
    int n=v.size();
    vector<int> majEles=MajEle(v,n);
    int rn=majEles.size();
    if(rn!=0){
        for(const int &x:majEles){
        cout<<x<<" ";
    }
    }
    else{
        cout<<"No majority element"<<"\n";
    }
    return 0;
}