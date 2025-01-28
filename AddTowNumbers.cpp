#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int convertToDecimal(string x) {
    int decimal=0;
    int base=1;
    for (int i=x.size()-1;i>=0;i--) {
        if (x[i]=='1')
            decimal += base;
        base*=2;
    }
    return decimal;
}

string convertToBinary(int x){
    string bin="";
    while (x>0){
        bin+=(x%2==0?"0":"1");
        x/=2;
    }
    reverse(bin.begin(), bin.end()); 
    return bin.empty()?"0":bin;
}

string addNumbers(int a,int b) {
    string a_s, b_s, ans="";
    int bit1,bit2, sum;
    a_s = convertToBinary(a);
    b_s = convertToBinary(b);
    bool carry = 0;
    while (a_s.size() < b_s.size()) 
        a_s='0'+a_s;
    while (b_s.size() < a_s.size()) 
        b_s='0'+b_s;
    for (int i=a_s.size()-1;i>=0;i--) {
        sum=(a_s[i]-'0')+(b_s[i]-'0')+carry;
        ans=char((sum%2)+'0')+ans;
        carry=(sum>=2); 
    }
    if (carry) 
        ans='1'+ans;
    return ans;
}

int main() {
    int a, b;
    cout<<"enter 2 numbers to add them: ";
    cin>>a>>b;
    string b_sum=addNumbers(a,b);
    cout<<"sum: "<<convertToDecimal(b_sum)<<endl;
    return 0;
}
