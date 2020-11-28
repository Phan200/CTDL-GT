#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
long long *a;
int n,k;
void init(){
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
}

void Hieu_2_MangCon(){
    sort(a,a+n);
    int *sub_a=new int[k];
    int sum1=0,sum2=0;
    if(k<=n/2){
        for(int i=0;i<k;++i){
            sub_a[i]=a[i];
            sum1+=a[i];
        }
        for(int i=k;i<n;++i){
            sum2+=a[i];
        }
    } else{
        for(int i=0;i<n-k;++i){
            sub_a[i]=a[i];
            sum1+=a[i];
        }
        for(int i=n-k;i<n;++i){
            sum2+=a[i];
        }
    }
    cout<<abs(sum1-sum2)<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        a=new long long[n];
        init();
        Hieu_2_MangCon();
    }
    
}