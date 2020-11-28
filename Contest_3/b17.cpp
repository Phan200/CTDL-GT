#include<bits/stdc++.h>


using namespace std;
int k;
string str;
int freq[300];

void Frequency(){
    for(int i=0;i<str.length();++i){
        ++freq[str[i]];
    }
    priority_queue<int> q;
    for(int i=0;i<str.length();++i){
        if(freq[str[i]]>0){
            q.push(freq[str[i]]);
            freq[str[i]]=0;
        }
    }
    while(k--){
        int t=q.top()-1; q.pop();
        q.push(t);
    }
    long long res=0;
    while(!q.empty()){
        int temp=q.top();q.pop();
        res+=pow(temp,2);
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>k;
        str="";
        cin>>str;
        memset(freq,0,sizeof(freq));
        Frequency();
    }
}