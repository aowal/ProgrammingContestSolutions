//
// Created by Abdul Aowal on 7/24/17.
//

#include<iostream>
using namespace std;

template<class T> string fromDecimal(T n, int b) {
    string chars="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result="";
    while(n>0) {
        result=chars[n%b] + result;
        n/=b;
    }
    return result;
}

long long toDecimal(string n,long long b) {
    long long result=0;
    long long multiplier=1;
    for(int i=(n.size())-1; i>=0; i--) {
        result+=(long long)(n[i]-'0') * multiplier;
        multiplier*=b;
    }
    return result;
}


class ConsecutiveOnes
{
public:

    long get(long n, int k){
        string bign;
        bign = fromDecimal(n, 2);
        bool flag = true;
        int p = bign.size();
        int t = p - 1;
        for(int i=0; i + k < p; i++){
            if(bign.substr(i, k) == string(k, '1')){
                return n;
            }
        }
        if(p <= k)
            return toDecimal(string(k,'1'),2);
        for (int i = p - 1; i >= 0 || k >= 1; i--, k--)
        {
            if(k < 1 && bign[i] == '0')
                flag = false;
            if(k < 1 && bign[i] == '1' && flag && toDecimal(bign,2) > n)
                bign[t--] = '0';
            if(i >= 0 && k >= 1)
                bign[i] = '1';
        }
        return toDecimal(bign, 2);
    }
};

int main(){
    long long a = 710467578737954;
    int b = 3;
    ConsecutiveOnes c;
    cout<<fromDecimal(a, 2)<<endl;
    cout<<c.get(a,b);
    return 0;
}