#include<iostream>

using namespace std;


int BiggestSum(int a[],int n){
    int Tap_Tang[n+1];
    int Tap_Giam[n+1];
    for(int i=1;i<=n;++i){
        Tap_Tang[i]=a[i];
        Tap_Giam[i]=a[i];
    }
    
    int res=-1;
    // Theo chieu tang dan
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(a[j]<a[i]&&Tap_Tang[i]<Tap_Tang[j]+a[i]){
                Tap_Tang[i]=Tap_Tang[j]+a[i];
            }
        }
    }
    //theo chieu giam dan
    for(int i=n;i>=0;--i){
        for(int j=n;j>i;--j){
            if(a[j]<a[i]&&Tap_Giam[i]<Tap_Giam[j]+a[i]){
                Tap_Giam[i]=Tap_Giam[j]+a[i];
            }
        }
    }
    for(int i=1;i<=n;++i){
        res=max(res,Tap_Giam[i]+Tap_Tang[i]-a[i]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        cout<<BiggestSum(a,n)<<"\n";
    }
    
}