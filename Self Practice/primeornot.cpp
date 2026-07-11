#include <iostream>
using namespace std;

int main(){
    int n;
    bool div=false;
    cout<<"Enter any natural number"<<"\n";
    cin>>n;
    if(n<=0){
        cout<<"Enter a valid number."<<"\n";
    }
    else if(n==1){
        cout<<"Neither prime nor composite"<<"\n";
    }
    else if(n==2||n==3){
        cout<<"Prime"<<"\n";
    }
    else if(n%2==0||n%3==0){
        cout<<"Composite"<<"\n";
    }
    else{
        for(int i=5;i*i<n;i+=6){
            if(n%i==0){
                div=true;
                cout<<"Composite"<<"\n";
                break;
            }
        }
        if(div==false)
        cout<<"Prime"<<"\n";
    }
    return 0;
}