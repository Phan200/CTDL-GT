#include<iostream>
#include<cstring>
using namespace std;

int main(){
      int n,s;
        cin>>n>>s;
        int f[s+1];
        memset(f,0,sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin>>a;
            f[a]=1;
            // su dung 1 mang ghi nhan cac so nhap vao va =1
            // lan luot kiem tra xem co so nao cong voi so
            // da nhap ra tong bang j, roi de f[j]=1
            for(int j=s;j>=a;--j){
                if(f[j-a]==1&&a*2!=j) {f[j]=1;}
            }
            
        }
        if(f[s]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    return 0;
}
