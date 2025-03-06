#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, anton=0, danik=0;
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='A')
            anton++;
        else if(c=='D')
            danik++;
    }
    if(anton>danik)
        cout<<"Anton\n";
    else if(anton<danik)
        cout<<"Danik\n";
    else
        cout<<"Friendship\n";
    return 0;
}