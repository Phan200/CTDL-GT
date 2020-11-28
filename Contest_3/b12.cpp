#include<iostream>

using namespace std;
string str;

void Frequency(){
    int l=str.length();
    int freq[26]={0};
    for(int i=0;i<l;++i){
        ++freq[str[i]-'a'];
    }
    int Largest_Freq=0;
    for(int i=0;i<l;++i){
        Largest_Freq=max(Largest_Freq,freq[str[i]-'a']);
    }
    if(l-Largest_Freq>0&&Largest_Freq<=l-Largest_Freq) cout<<1;
    else if(l-Largest_Freq>0&&Largest_Freq-1<=l-Largest_Freq) cout<<1;
    else cout<<-1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        Frequency();
        cout<<endl;
    }
}
