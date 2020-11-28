#include<bits/stdc++.h>
#define ll long long int

using namespace std; 
vector<string> vect;

void Generate(){
    vect.push_back("0");
    queue<string> q;
    q.push("9");
    for(int i=0;i<=10000;++i){
        string s1=q.front();
        q.pop();
        vect.push_back(s1);

        string s2=s1;
        q.push(s1.append("0"));
        q.push(s2.append("9"));
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    Generate();
    while(t--){
        int n;
        cin>>n;
        for(int i=1;;i++){
            if(stoi(vect[i])%n==0){
                cout<<vect[i];
                break;
            }
        }
        cout<<endl;
    }
}
