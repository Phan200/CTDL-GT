#include<iostream>
#include<algorithm>

using namespace std;
const unsigned long long mod=1e18+7;
int n;
long long *a,*b;
void Init(){
    a=new long long[n];
    b=new long long [n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
}
void Tinh_Tong(){
    sort(a,a+n);
    sort(b,b+n,greater<long long>());
    long long sum=0;
    for(int i=0;i<n;++i){
        sum+=a[i]*b[i];
        sum=sum%mod;
    }
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Init();
        Tinh_Tong();
    }
}