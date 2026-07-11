#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int scores[]={85,90,78,95,88};
    int *score_ptr=&scores[0];
    score_ptr+=2;
    cout<<*score_ptr<<"\n";
    return 0;
}