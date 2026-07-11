#include <iostream>
using namespace std;

int main(){
    char c;
    cout<<"Enter any character: ";
    cin>>c;
    cout<<static_cast<int>(c)<<" is the ASCII value of the character you entered";
    return 0;
}