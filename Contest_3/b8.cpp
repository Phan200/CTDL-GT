#include<iostream>
#include<algorithm>

using namespace std;
int n;

struct Job
{
    int start,finish;
};
Job *cv;

void Init(){
    cv=new Job[n];
    for(int i=0;i<n;++i){
        cin>>cv[i].start;
    }
    for(int i=0;i<n;++i){
        cin>>cv[i].finish;
    }
}
// Su dung de so sanh trong struct
bool SoSanh(Job a,Job b){
    return (a.finish<b.finish);
}
void CongViec(){
    sort(cv,cv+n,SoSanh);
    int job=1;
    int f=cv[0].finish;
    int i=1;
    while(i<n){
        if(cv[i].start>=f){
            ++job;
            f=cv[i].finish;
        }
        ++i;
    }
    cout<<job<<endl;
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