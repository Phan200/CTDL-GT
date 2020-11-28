#include<iostream>
#include<algorithm>

#define ll long long int
using namespace std;

void Min_Subarray(ll a[],int n){
    int s,e;
    ll min_numb,max_numb;
    // tim a[i]>a[i+1] va dat khoi diem tai index i
    for(int i=0;i<n-1;++i){
        if(a[i]>a[i+1]){
            s=i;
            break;
        }
    }
    // tim a[i]<a[i-1] theo chieu nguoc lai va dat diem cuoi 
    // cua day con tai index i
    for(int j=n-1;j>0;--j){
        if(a[j]<a[j-1]){
            e=j;
            break;
        }
    }
    // tim min max trong day con [s,e]
    for(int i=s;i<e;++i){
        min_numb=min(min_numb,min(a[i],a[i+1]));
        max_numb=max(max_numb,max(a[i],a[i+1]));
    }
    //trong day ben trai cua day con dang tim
    // co a[i]>min cua day con thi dat khoi diem tai index i
    for(int i=0;i<s;++i){
        if(a[i]>min_numb) s=i;
    }
    //trong day ben phai cua day con dang tim
    // co a[i]<max cua day con thi dat diem cuoi e tai index i
    for(int i=e+1;i<n;++i){
        if(a[i]<max_numb) e=i;
    }
    cout<<s+1<<" "<<e+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;++i) {
            cin>>a[i];
        }
        Min_Subarray(a,n);
    }
    return 0;
}