#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

struct Count{
    int val,count=0;
    bool operator<(const Count &c) const{
        return (count>c.count);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        Count dem[100000];
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            dem[a[i]].val=a[i];
            dem[a[i]].count++;
        }
        sort(dem,dem+100000);
        for(int i=0;;++i){
            if(dem[i].count==0) break;
            else{
                for(int j=1;j<=dem[i].count;++j) cout<<dem[i].val<<" ";
            }
        }
        cout<<endl;
    }
}