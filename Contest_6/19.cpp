#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int a[1001];
bool check[1001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(check,1,sizeof(check));
        int L=INT_MIN,R=INT_MAX;
        for(int i=0;i<n;++i){
            cin>>a[i];
            check[a[i]]=false;
            L=max(L,a[i]);
            R=min(R,a[i]);
        }
        int res=0;
        for(int i=R;i<=L;++i){
            if(check[i]) ++res;
        }
        cout<<res<<endl;
    }
}