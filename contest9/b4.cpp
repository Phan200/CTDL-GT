#include<iostream>
#include<cstring>
#include<sstream> 
#include<string>

using namespace std;
using std::istringstream; 
using std::string; 
using std::cout; 

int g[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cin.ignore();
    
    
    memset(g,0,sizeof(g));
    string s;
    for (int i=0;i<n;++i){
        getline(cin,s);
        istringstream my_str(s);
        int so;
        while(my_str){
            my_str>>so;
            g[i][so-1]=1;
        }
    }
    
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}