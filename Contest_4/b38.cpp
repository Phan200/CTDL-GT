#include<iostream>
#define ll long long int
using namespace std;

int MergeSort(int a[],int b[],int temp[], int n,int m,int p){
    int i=0,j=0,k=0;// index bat dau cua mang 
    while (i<n&&j<m)
    {
        if(a[i]<=b[j]) temp[k++]=a[i++];
        else{
            temp[k++]=b[j++];
        }
    }
    while(i<n) temp[k++]=a[i++];
    while(j<m) temp[k++]=b[j++];
    return temp[p];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>b[i];
        }
        int temp[n+m];
        cout<<MergeSort(a,b,temp,n,m,k-1)<<endl;
    }
    
}