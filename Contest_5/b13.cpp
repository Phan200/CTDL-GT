#include<iostream>
#define ll long long int
using namespace std;

ll u[10001];
void UglyNumber(){
    u[1]=1;
    int i=1,j=1,k=1;
    int mul2=2, mul3=3,mul5=5;
    for(int n=2;n<=10000;++n){
        u[n]=min(mul2,min(mul3,mul5));
        if(u[n]==mul2) {
            ++i;
            mul2=u[i]*2;
        }
        if(u[n]==mul3) {
            ++j;
            mul3= u[j]*3;
        }
        if(u[n]%5==0) {
            ++k;
            mul5=u[k]*5;
        }
    }
}
int main(){
    UglyNumber();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<u[n]<<endl;
    }
    
}