#include<iostream>
#include<algorithm>

using namespace std;
int n;
struct Job{
    int id,ddline,pro;
};
Job *cv;

void Init(){
    cv=new Job[n];
    for(int i=0;i<n;++i){
        cin>>cv[i].id>>cv[i].ddline>>cv[i].pro;
    }
}
bool SoSanh(Job a,Job b){
    return (a.pro>b.pro);
}
void CongViec(){
    sort(cv,cv+n,SoSanh);
    bool check[n];
    int dem=0;
    int Profit=0;
    for (int i = 0; i < n; i++)
    {
        check[i]=true;
    }
    for(int i=0;i<n;++i){
        // dat j=min(n,cv[i].ddline)
        // de neu deadline>n thi co the ghi nhan 
        // dc tat ca cong viec ddc hoan thanh
        for(int j=min(n,cv[i].ddline)-1;j>=0;--j){
            if(check[j]){
                check[j]=false;// danh dau tai thoi diem j da co cong viec phai lam
                ++dem;
                Profit+=cv[i].pro;
                break;// ghi nhan cong viec i da hoan thanh
            }
        }
    }
    cout<<dem<<" "<<Profit<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Init();
        CongViec();
    }
}