
#include<bits/stdc++.h>

using namespace std;
int *note;
int counts=0;
int min_value=INT_MAX;

void least_MoneyChange(int i,int n,int s){
    for(int j=1;j>=0;--j){
        if(s>=j*note[i]){
            s-=j*note[i];
            counts+=j;
            if(s==0) min_value=counts;
            else if(i<n && counts+1<min_value) least_MoneyChange(i+1,n,s);
            s+=j*note[i];
            counts-=j;
        }
    }
}


int main(){
    int n,s;
    cin>>n>>s;
    note=new int[n];
    for(int i=0;i<n;++i){
        cin>>note[i];
    }
    sort(note,note+n,greater<int>());
    least_MoneyChange(0,n,s);
    if(min_value!=INT_MAX) cout<<min_value<<endl;
    else cout<<-1<<endl;
    return 0;
}