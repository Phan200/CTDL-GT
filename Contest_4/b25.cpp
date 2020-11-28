// mang f[] chua do dai cua chuoi thu i=so fibonacci thu i
// 1 1 2 3 5 8 13 21 34 ...
//   b  bab bababbab  
// a  ab  abbab abbabbababbab
#include<bits/stdc++.h>
using namespace std;
long long F[100];
void  Fibonacci(int &n,long long &i)
{
     if(n>2)
     {
		 // neu vi tri i lon hon f[n-2]
		 // thi ki tu i-th se nam o f[n-1]
     	if(i<=F[n-2]) Fibonacci(n-=2,i);
     	else // nguoc lai
     		Fibonacci(n-=1,i-=F[n-2]);
	 } 
 
}
int main()
{
    F[1]=F[2]=1;
	for(int i=3;i<92;i++)
		F[i]=F[i-2]+F[i-1];
	int t; 
	cin>>t;
	while(t--)
	{
		int n; 
		long long i; 
		cin>>n>>i;
		Fibonacci(n,i); 
		if(n==1) cout<<'A'<<endl;
	    else cout<<'B'<<endl;
	}
}