#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void multiply(long long int F[2][2],long long int M[2][2]);
 
void power(long long int F[2][2], long long int n);
 

long long int fib(long long int n)   // Function to find Fibonacci of a number
{
  long long int x=0;
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  else
     x = n+2;
  power(F, x-1);
  return F[0][0]%mod;
}
 

void power(long long int F[2][2],long long int n)   // Function to calculate power
{
  if( n == 0 || n == 1)
      return;
 long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long int F[2][2],long long int M[2][2]) // helper function for multiplication
{
 long long int x =  ((F[0][0]*M[0][0]%mod) + (F[0][1]*M[1][0]%mod))%mod;
 long long int y =  ((F[0][0]*M[0][1]%mod) + (F[0][1]*M[1][1]%mod))%mod;
 long long int z =  ((F[1][0]*M[0][0]%mod) + (F[1][1]*M[1][0]%mod))%mod;
 long long int w =  ((F[1][0]*M[0][1]%mod) + (F[1][1]*M[1][1]%mod))%mod;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
	  long long int n;
	  cin >> n;
	  long long int ans = fib(n);
	  cout << ans << endl;
  }
  return 0;
}

