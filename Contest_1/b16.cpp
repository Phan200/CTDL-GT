#include<iostream>

using namespace std;
int arr[11][11],k,n;
int pos[11];
int count=0;
int mem[11][11];// ghi nho vi tri

bool finalPos(){
    for(int i=1;i<=n;++i){
        if(pos[i]!=n-i+1) return false;
    }
    return true;
}
void next_permutation_Pos(){
    int i=n-1;
    while(pos[i]>pos[i+1]) --i;
    if(i>0){
        int j=n;
        while(pos[i]>pos[j]) --j;
        swap(pos[i],pos[j]);
        int s=i+1,t=n;
        while(s<t){
            swap(pos[s],pos[t]);
            ++s;--t;
        }
    }
}

void getPosition(){
    int sum;
    while(!finalPos()){
        sum=0;
        for(int i=1;i<=n;++i){
            sum+=arr[i][pos[i]];
        }
        if(sum==k){
            ++count;
            for(int i=1;i<=n;++i){
                mem[count][i]=pos[i];
            }
        }
        next_permutation_Pos();
    }
        sum=0;
        for(int i=1;i<=n;++i){
            sum+=arr[i][pos[i]];
        }
        if(sum==k){
            ++count;
            for(int i=1;i<=n;++i){
                mem[count][i]=pos[i];
            }
        }

}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        pos[i]=i;
        for(int j=1;j<=n;++j){
            cin>>arr[i][j];
        }
    }
    getPosition();
    cout<<count<<endl;
    for(int i=1;i<=count;++i){
        for(int j=1;j<=n;++j){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}