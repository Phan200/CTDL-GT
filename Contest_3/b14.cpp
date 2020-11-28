#include<iostream>
#include<string.h>
#include<cmath>
#include<vector>

#define ll unsigned long long int
const unsigned long long int mod=1e18+7;
using namespace std;
ll n;
vector<string> cube;

void init(){
    for(int i=1;i<=1000000;++i){
        ll temp=pow(i,3);
        string str=to_string(temp);
        cube.push_back(str);
    }
}

void Find_Cube(){
    string s=to_string(n);
    int temp=cbrt(n);// Chon lay so lap phuong lon nhat co the
    for(int i=temp-1;i>=0;--i){
        string k=cube[i];
        int l=k.length();
        int ind=0;
        for(int j=0;j<s.length();++j){
            // kiem tra xem k va s co cac so trung nhau khong
            if(s[j]==k[ind]) ++ind;
            if(ind==l) {cout<<k<<endl;return;}
        }
    }
    cout<<"-1"<<endl;
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Find_Cube();
    }
}