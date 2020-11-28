#include<iostream>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        int c=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]==0) ++c;
        }
        cout<<c<<endl;
    }
    
}