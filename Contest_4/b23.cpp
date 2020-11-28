// voi so 1: =2^0 +i, i={1,2...n}
// 2: =2^1*i ,3: =2^2*i, 4:=2^3*i; 5=2^4*i; ... voi i={1,2...n}
#include<iostream>

#define ll unsigned long long int
using namespace std;

ll k_thNumber(ll k){
    int ans=0;
    while(k%2==0){
        k/=2;
        ++ans;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        if(n==1||k%2!=0) cout<<1<<endl;
        else{
            int p=k_thNumber(k);
            cout<<p+1<<endl;
        }
    }
    
}