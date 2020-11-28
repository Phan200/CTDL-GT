#include<iostream>

using namespace std;
int binary_Search(long a[],long s,long e, long k){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==k) return mid+1;
        else if(a[mid]<k) s=mid+1;
        else if(a[mid]>k) e=mid-1;
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long n,k;
        long *a;
        cin>>n>>k;
        a=new long [n];
        for(int i=0;i<n;++i) cin>>a[i];
        long res=binary_Search(a,0,n-1,k);
        if(res==-1) cout<<"NO"<<endl;
        else cout<<res<<endl;
    }
    
}