#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];
        sort(a,a+n);
        int k=0;
        int res=0;
        while(k<n-1){
            if(a[k+1]!=a[k]+1){
                res+=(a[k+1]-a[k])-1;
            }
            k++;
        }
        cout<<res<<endl;
    }
}