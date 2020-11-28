#include<iostream>
#include<string>

using namespace std;
string DoiSo(string x,int i,int j){
    int k=0;
    while(k!=x.size()){
        if(x[k]==(i+'0')) x[k]=j+'0';
        k++;
    }
    return x;
}
void Tong(string a, string b,int i,int j){
    string x=DoiSo(a,i,j);
    string y=DoiSo(b,i,j);
    while(x.length()<y.length()) x="0"+x;
    while(x.length()>y.length()) y="0"+y;
    int k=x.length()-1;
    int nho=0;
    string res="";
    for(int l=k;l>=0;--l){
        int cong=int(x[l]-'0')+int(y[l]-'0')+nho;
        res=char(cong%10+'0')+res;
        nho=cong/10;
    }
    if(nho>0) cout<<(char(nho+'0')+res)<<" ";
    else cout<<res<<" ";
}
int main(){
    string a,b;
    cin>>a;
    cin.ignore();
    cin>>b;
    Tong(a,b,6,5);
    Tong(a,b,5,6);
    return 0;
}