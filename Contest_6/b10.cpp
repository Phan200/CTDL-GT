#include<iostream>
#include<vector>
#define ll long long int

using namespace std;


void Solve(string a,int *res){
    int l=a.length()-1;
    while(l>=0){
        if(res[a[l]-'0']==0){
            res[a[l]-'0']++;
        }
        --l;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        int res[10]={0};
        cin>>n;
        string a[n];
        for(int i=0;i<n;++i) {
            cin>>a[i];
            Solve(a[i],res);
        }
        for(int i=0;i<=9;++i){
            if(res[i]) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}