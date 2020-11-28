#include<iostream>
#define ll long long int
using namespace std;

const ll mod=1e9+7;
ll **a,**c;
int n;
void Mul(ll **x,ll **y){
    ll temp[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            temp[i][j]=0;
            for(int k=0;k<n;++k){
                temp[i][j]+=x[i][k]*y[k][j]%mod;
                temp[i][j]%=mod;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            a[i][j]=temp[i][j];
        }
    }
}
void Power(ll **a,ll **c,int k){
    if(k<=1) return;
    Power(a,c,k/2);
    Mul(a,a);
    if(k&1) Mul(a,c);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll k;
        cin>>n>>k;
        
        a=new ll *[n];
        c=new ll *[n];
        for(int i=0;i<n;++i){
            a[i]=new ll [n];
            c[i]=new ll [n];
            for(int j=0;j<n;++j){
                cin>>a[i][j];
                c[i][j]=a[i][j];
            }
        }
        Power(a,c,k);
        for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        }
    }

    delete[] a,c;
}