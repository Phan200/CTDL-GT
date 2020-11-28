#include<iostream>

using namespace std;
#define ll long long int
const ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int a,b;
        for(int i=0;i<n;++i){
            cin>>a;
            if(a==k) b=i+1;
        }
        cout<<b<<endl;
    }
    
}