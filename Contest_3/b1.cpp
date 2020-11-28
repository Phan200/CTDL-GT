#include<iostream>

using namespace std;
int note[]={1,2,5,10,20,50,100,200,500,1000};

int ChangeMoney(int n,int count){
    int k=sizeof(note)/sizeof(note[0]);
    for(int i=k-1;i>=0;--i){
        while(n>=note[i]){
            ++count;
            n-=note[i];
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ChangeMoney(n,0)<<endl;
    }
}