#include<iostream>
#define ll unsigned long long int
using namespace std;
ll *a;

ll Merge(ll *a,ll *temp, int l, int mid, int r){
    ll inv_c=0;
    int i=l;// index bat dau cua mang trai
    int j=mid;// index bat dau cua mang phai
    int k=l;// index bat dau cua mang ket_qua_sau_sort()
    while (i<mid&&j<=r)
    {
        if(a[i]<=a[j]) {
            // chuyen a[i] vao mang temp[]
            // tang ++i de cet tiep a[i]>a[j] ko
            temp[k++]=a[i++];
        }
        else{
            // chuyen a[j] vao trong mang temp[]
            // tang ++j de xet tiep a[i]>a[j] ko
            temp[k++]=a[j++];
            // vi mang da duoc sap xep tu nho den lon
            // nen neu a[i]>a[j]
            // thi tat ca cac so dang sau a[i] dau lon hon a[j]
            // nen dem inv_c+=mid-i
            inv_c+=mid-i;
        }
    }
    // day het cac so con lai trong mang trai vao temp[]
    while (i<mid)
    {
        temp[k++]=a[i++];
    }
    // day het cac so con lai trong mang phai vao temp[]
    while (j<=r)
    {
        temp[k++]=a[j++];
    }
    // chuyen mang da sap xep theo thu tu nho den lon 
    // lai vao a[]
    for(i=l;i<=r;++i){
        a[i]=temp[i];
    }
    return inv_c;
}
ll _MSort(ll *a,ll *temp, int l, int r){
    int mid;
    ll inv_c=0;
    if(r>l){
        // chia doi mang a[] 
        // va tinh so inv_c o moi mang
        mid= (r+l)/2;
        
        inv_c+=_MSort(a,temp,l,mid);
        inv_c+= _MSort(a,temp,mid+1,r);

        inv_c+=Merge(a,temp,l,mid+1,r);
    }
    return inv_c;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        a=new ll[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        ll *temp=new ll[n];
        ll k=_MSort(a,temp,0,n-1);
        cout<<k<<endl;
        delete[] a,temp;
    }
    
}