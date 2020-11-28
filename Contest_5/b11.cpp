#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
string dp[200];
string Add(string a,string b){
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    int l1=a.length();
    string str="";
    int c=0;
    for(int i=l1-1;i>=0;--i){
        int sum=(a[i]-'0')+(b[i]-'0')+c;
        str=char(sum%10+'0')+str;
        c=sum/10;
    }
    if(c>0) str=char(c+'0')+str;
    
    return str;
}
string Mul(string a,string b){
    int l1=a.length();
    int l2=b.length();
    vector<int> res(l1+l2,0);

    int i_1=0;
    int i_2=0;
    for(int i=l1-1;i>=0;--i){
        int c=0;// so nho
        int n1=a[i]-'0';
        i_2=0;
        for(int j=l2-1;j>=0;--j){
            int n2=b[j]-'0';
            int sum=n1*n2+res[i_1+i_2]+c;
            c=sum/10;
            res[i_1+i_2]=sum%10;
            i_2++;
        }
        if(c>0) res[i_1+i_2]+=c;
        ++i_1;
    }
    int i=res.size()-1;
    while(i>=0&&res[i]==0){
        i--;
    }
    if(i==-1) return "0";
    string s="";
    while(i>=0){
        s+=to_string(res[i--]);
    }
    return s;
}
void Create(){
    dp[0]=dp[1]="1";
    for(int i=2;i<=100;++i){
        dp[i]="";
        for(int k=0;k<i;++k){
            dp[i]=Add(dp[i],Mul(dp[k],dp[i-k-1]));
        }
        
    }
}
int main(){
    Create();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    
}