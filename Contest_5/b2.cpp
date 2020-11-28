#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

int main(){
        int n;
        cin>>n;
        int a[n+2];
        int l[n+2];
        a[0]=0;a[n+1]=1001;// 2 phan tu nho nhat va lon nhat dau cuoi moi day
        //memset(l,0, sizeof(l));
        l[n+1]=1;// dien co so quy hoach dong
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        int j_max;
        int res=0;
        for(int i=n;i>=0;--i){
            // chon trong cac chi so j dung sau i thoa man
            // a[j]>a[i] ra chi so j_max co l[j_max] lon nhat
            j_max=n+1;
            for(int j=i+1;j<=n+1;++j){
                if(a[j]>a[i]&&l[j]>l[j_max]) j_max=j;
            }
            l[i]=l[j_max]+1;
            res=max(res,l[i]);
        }
        cout<<res-2<<endl;
    return 0;
}