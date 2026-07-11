#include <bits/stdc++.h>
using namespace std;
int Slar(vector<int> v){
    int lar=INT_MIN,slar=INT_MIN;
    for(int i=0;i<v.size()-1;i++){
        if(v.at(i)>lar){
            slar=lar;
            lar=v.at(i);
        }
        else if(v.at(i)>slar&&v.at(i)<lar){
            slar=v.at(i);
        }
    }
    if(slar==INT_MIN){
        return -1;
    }
    return slar;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v={1,3,2,4,22,2,55,12};
    int sl=Slar(v);
    cout<<sl<<"\n";
    return 0;
}