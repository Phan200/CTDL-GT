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
        int n;
        cin>>n;
        int a,b=-1;
        for(int i=1;i<n;++i){
            cin>>a;
            if(a!=i&&b==-1) b=a-1;
        }
        cout<<b<<endl;
    }
    
}