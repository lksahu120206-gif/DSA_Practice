#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c=42;
    int *p1=&c;
    int **p2=&p1;
    cout<<**p2<<"\n";
    return 0;
}