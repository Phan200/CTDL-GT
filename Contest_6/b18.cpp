#include<algorithm>
#include <iostream>
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,i,j,k;
        cin>>n>>m;
        ll a[n],b[m],c[m+n];
        for( i=0;i<n;++i) cin>>a[i];
        for( i=0;i<m;++i) cin>>b[i];
        sort(a,a+n);
        sort(b,b+m);
        i=0,j=0,k=0;
        while(i<n&&j<m){
            if(a[i]<b[j]){
                c[k]=a[i];
                ++i;
            } else if(a[i]>b[j]){
                c[k]=b[j];
                ++j;
            } else if(a[i]==b[j]){
                c[k++]=a[i];
                c[k]=b[j];
                ++i;++j;
            }
            ++k;
        }
        while(i<n){
            c[k]=a[i++];
            ++k;
        }

        while(j<m){
            c[k]=b[j++];
            ++k;
        }
        for(i=0;i<k;++i) cout<<c[i]<<" ";
        cout<<endl;
    }
    
}