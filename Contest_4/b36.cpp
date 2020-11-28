#include<iostream>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s1="",s2="";
        cin>>s1>>s2;
        ll a=0,b=0;
        ll p=1;
        for(int i=s1.length()-1;i>=0;--i){
            a+=(s1[i]-'0')*p;
            p*=2;
        }
        
        p=1;
        for(int i=s2.length()-1;i>=0;--i){
            b+=(s2[i]-'0')*p;
            p*=2;
        }
        
        cout<<a*b<<endl;
    }
    
}