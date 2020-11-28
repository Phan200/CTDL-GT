#include<iostream>
#include<algorithm>

using namespace std;
string str;
int d;

void Frequency(int *freq){
    int l=str.length();
    for(int i=0;i<l;++i){
        ++freq[str[i]-'A'];
    }
}
bool Sap_Dat(){
    int l=str.length();
    int *freq=new int [26];
    for(int i=0;i<26;++i){
        freq[i]=0;
    }
    Frequency(freq);
    sort(freq,freq+26,greater<int>());
    int i=0,count=0;
    while(freq[i]!=0){
        int p=freq[i];
        for(int j=0;j<p;++j){
            if(i+(j*d)>l) return false;// khong co loi giai
        }
        i++;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>d;
        cin>>str;
        if (Sap_Dat()) cout<<1;
        else cout<<-1;
        cout<<endl;
    }
}
