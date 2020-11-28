#include<iostream>
#include<math.h>
#include<algorithm>
#include<iomanip> 
#define ll long long int
using namespace std;
struct point{
    int x;//hoanh do
    int y;//tung do
};
point *p;

bool Comp_X(point a,point b){
    return (a.x<b.x); 
}
bool Comp_Y(point a,point b){
    return (a.y<b.y); 
}
double min(double x, double y){
    return (x<y)? x:y;
}
// ham tinh khoang cach giua 2 diem
double Distance(point a, point b){
    double temp=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    return temp;
}

// tinh moi khoang cach 2 diem trong p[]
// tra ve khoang cach nho nhat
double MinDistance(point p[],int n){
    double min=__DBL_MAX__;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            double k=Distance(p[i],p[j]);
            if(k<min) min=k;
        }
    }
    return min;
}
// ham de tinh khoang canh gan nhat trong strip[]
double strip_ClosetDist(point s[],int size, double d){
    double min=d; // dat d la kc min
    // sap xep lai cac diem trong strip[] 
    // theo tung do tu nho den lon
    sort(s,s+size,Comp_Y);
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j <size && s[j].y-s[i].y<min; j++)
        {
            double k=Distance(s[i],s[j]);
            if(k<min) min=k;
        }
        
    }
    return min;
}
double FindClosetDist(point p[],int n){
    // khi ma chi con lai 2-3 diem 
    if(n<=3) return MinDistance(p,n);
    // tim diem nam giua 
    int mid=n/2;
    point mid_p=p[mid];
    // sau khi chia doi bang 1 duong doc qua diem giua
    // duoc 2 ben mang trai-phai
    double dl=FindClosetDist(p,mid);
    double dr=FindClosetDist(p+mid,n-mid);
    double d=min(dl,dr);

    // tao 1 mang strip[] chua cac diem nam cach
    // duong chia 2 ben ma <d 
    point strip[n];
    int j=0;
    for(int i=0;i<n;++i){
        if(abs(p[i].x-mid_p.x)<d){
            strip[j]=p[i];
            ++j;
        }
    }
    // tim kc nho nhat voi strip[]
    return min(d,strip_ClosetDist(strip,j,d));
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        p=new point[n];
        for (int i = 0; i < n; i++)
        {
            cin>>p[i].x>>p[i].y;

        }
        sort(p,p+n,Comp_X);//sap xep cac diem theo hoanh do
        cout<<fixed;
        cout<<setprecision(6);
        cout<<FindClosetDist(p,n)<<endl;
    }
    
}