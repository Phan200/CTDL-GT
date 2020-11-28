#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int c,r;
        cin>>r>>c;
        int a[r+1][c+1];
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                cin>>a[i][j];
            }
        }
    }
    
}