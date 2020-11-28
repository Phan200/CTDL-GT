#include<iostream>

using namespace std;
#define ll long long
void Phan_So(ll tu,ll mau){
    while(1)
    {if(mau%tu==0){
        cout<<"1/"<<mau/tu<<"\n";
        break;
    } else{
        int res=mau/tu+1;
        cout<<"1/"<<res<<" + ";
        tu=tu*res-mau;
        mau=mau*res;
    }}
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll p,q;
        cin>>p>>q;
        Phan_So(p,q);

    }
}