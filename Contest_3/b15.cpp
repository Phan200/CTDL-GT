#include<iostream>

using namespace std;
int n,s,m;
void Survival_Day(){
    // so luong thuc mua trong 1 ngay 
    //khong du cho lt can thiet trong 1ng
    if(n<m||n*6<m*7&&s>6) cout<<-1<<endl;
    else{
        int day=(m*s)/n;
        if((m*s)%n!=0) ++day;
        cout<<day<<endl;
    }

}
int main(){
    int t;
    cin >>t;
    while (t--)
    {
        cin>>n>>s>>m;
        Survival_Day();
    }
    
}