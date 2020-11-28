#include<iostream>
#include<vector>

using namespace std;
void Bracket(string s){
    // luu giu vi tri cua dau [
    vector<int> pos;
    for(int i=0;i<s.length();++i){
        if(s[i]=='[') pos.push_back(i);
    }
    int c=0;//dem so lan [ xh
    int p=0;// kiem tra vi tri cua [ tiep theo
    int sum=0;// dem so lan doi cho
    for(int i=0;i<s.length();++i){
        if(s[i]=='['){
            ++c; ++p;
        } else if(s[i]==']'){
            --c;
        }
        // khi gap dau sai
        if(c<0){
            sum+=pos[p]-i;
            swap(s[i],s[pos[p]]);
            ++p;
            c=1;
        }
    }
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Bracket(s);
    }
}