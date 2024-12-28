// Question 2 (Dynamic Programming)
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <cstring>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dbl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll MOD=1000000007;
    string s;cin>>s;
    vector<ll>dp(s.size()+1);
    if(s.find("m")==-1&&s.find("w")==-1){
            dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=s.size();i++){
            dp[i]=dp[i-1];
            if((s[i-2]=='n'&&s[i-1]=='n')||(s[i-2]=='u'&&s[i-1]=='u'))
                dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        cout<<dp[s.size()]<<"\n";
    }
    else cout<<0<<"\n";
    return 0;
}
