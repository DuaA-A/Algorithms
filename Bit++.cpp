#include<iostream>
#include<cmath>
#include<algorithm>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef double dbl;

int main(){
    FAST;
    int n, ei=0, oi=0;
    cin>>n;
    ll ar[100005];
    ll e[100005/2];
    ll o[100005/2];

    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]%2)
            o[oi++]=ar[i];
        else
            e[ei++]=ar[i];
    }
    
    sort(e, e+(n/2));
    sort(o, o+(n/2));
    
    ei=0, oi=0;
    for(int i=0;i<n;i++){
        if(i%2)
            cout<<o[oi++]<<" ";
        else
            cout<<e[ei++]<<" ";
    }
    return 0;
}