#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char word[]="CODE";
    char *ptr=&word[0];
    ptr+=2;
    cout<<*ptr<<"\n";
    return 0;
}