#include<bits/stdc++.h>

using namespace std;
int s,d;
string n;
string stop;
int res;
void init(){
    n.assign(d-1,'0');n="1"+n; 
    stop.assign(d,'9'); 
}
int Count(string s){
    int res=0;
    for(int i=0;i<s.length();++i){
        res+=s[i]-'0';
    }
    return res;
}
void Smallest_Number(int k){

    int c=Count(n);
    if(c==s){
        res=0;
        cout<<n<<endl;
        return;
    }
    if(n.compare(stop)!=0){
        if(k<d-1){
            n[d-1-k]='9';
            int g=Count(n);
            if(g>s){
                int temp= 9-(g-s);
                n[d-1-k]=temp+'0';
                Smallest_Number(k+1);
            } else Smallest_Number(k+1);
        }
        if(k==d-1){
            int t=(n[0]-'0')+1;
            n[0]=t+'0';
            Smallest_Number(k);
        }
    }
    if(n.compare(stop)==0&&res==1){cout<<"-1"<<endl;res=0; }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s>>d;
        n="";
        stop="";
        res=1;
        init();
        Smallest_Number(0);
    }
    return 0;
}