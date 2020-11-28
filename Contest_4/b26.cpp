// vd 8 1347 223

#include<iostream>

using namespace std;

int main(){

        int k;
        string a,b;
        cin>>k>>a>>b;
        while(a.size()<b.size()) a="0"+a;
        while(b.size()<a.size()) b="0"+b;
        int l=a.size();
        string res="";
        int nho=0;
        for (int i = l-1; i>=0;--i)
        {
            int numb=(a[i]-'0')+(b[i]-'0')+nho;// 7+3
            res=char(numb%k+'0')+res;// 10%8=2
            nho=numb/k; // 10/8=1, nho=1
        }
        if(nho>0) res=char(nho+'0')+res;
        cout<<res<<endl; 
}