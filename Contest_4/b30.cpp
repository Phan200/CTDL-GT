#include<bits/stdc++.h>
using namespace std;
long long p=1e9+7;

void tao(long long F[2][2],long long M[2][2]) 
{ 
  long long x =  ((F[0][0]%p*M[0][0]%p)%p + (F[0][1]%p*M[1][0]%p)%p)%p; 
  long long y =  ((F[0][0]%p*M[0][1]%p)%p + (F[0][1]%p*M[1][1]%p)%p)%p; 
  long long z =  ((F[1][0]%p*M[0][0]%p)%p + (F[1][1]%p*M[1][0]%p)%p)%p; 
  long long w =  ((F[1][0]%p*M[0][1]%p)%p + (F[1][1]%p*M[1][1]%p)%p)%p; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
  void Power(long long F[2][2], long long n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  long long M[2][2] = {{1,1},{1,0}}; 
  
  Power(F, n/2); 
  tao(F, F); 
  
  if (n%2 != 0) 
     tao(F, M); 
} 
  
long long fib(long long n) 
{ 
  long long F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  Power(F, n-1); 
  return F[0][0]; 
} 


  
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout<<fib(n)<<"\n";
	}
}