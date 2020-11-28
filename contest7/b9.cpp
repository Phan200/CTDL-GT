#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>


using namespace std;
struct data{
    int b,e;
};
string str;
string res;
vector<data> v;
vector<string> ans;
int check[100];
bool ok;

bool compare(data a, data b){
    return a.b<b.b;
}
// ham xoa lan luot tung ngoac tu trong ra ngoai
// su dung de quy
// 
void Try(int k,int n){
    for(int i=0;i<=1;++i){
        check[k]=i;
        if(k==n-1){
            int t=k;
            ok=0;
            while(t>=0){
                if(check[t]==1){
                    res[v[t].b]=res[v[t].e]=' ';
                    ok=1;
                }
                --t;
            }
            if(ok){
                res.erase(remove(res.begin(),res.end(),' '),res.end());
                ans.push_back(res);
                res=str;
            }

        } else Try(k+1,n);
    }

}
bool test(string s){
    for(int i=0;i<s.size()-1;++i){
        if(s[i]=='/'&&s[i+1]=='0') return false;
    }
    return true;
}
int main(){
    cin>>str;
    stack<int> s;
    for(int i=0;i<str.length();++i){
        if(str[i]=='('){
            s.push(i);
        } else if(str[i]==')'){
            data temp;
            temp.e=i;
            temp.b=s.top();
            s.pop();
            v.push_back(temp);
        }
    }
    sort(v.begin(),v.end(),compare);
    // for(int i=0;i<v.size();++i){
    //     cout<<v[i].b<<" "<<v[i].e<<endl;
    // }
    res=str;
    Try(0,v.size());
    for(int i=0;i<ans.size();++i){
            cout<<ans[i]<<endl;
    }
}