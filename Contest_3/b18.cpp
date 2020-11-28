#include<iostream>

using namespace std;
void Lucky_Number(int n){
    int a=0,b=0;//a- so lan lap 4;b- so lan lap 7
    while(n>0){
        if(n%7==0){
            ++b;
            n-=7;
        } else if(n%4==0){
            ++a;
            n-=4;
        } else{
            ++a;
            n-=4;
        }
    }
    if(n<0){ cout<<-1;return;}
    for(int i=1;i<=a;++i){
        cout<<4;
    }
    for(int i=1;i<=b;++i){
        cout<<7;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        Lucky_Number(n);
    }
    
}