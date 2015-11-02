#include<iostream>
#include<cmath>
using namespace std;
int f(long long n)
{
  long long k=(long long )((long long) sqrt(2*n+0.5) - 0.5);
  if((k+1)*(k+2)<=2*n) k++;
  return k;
    
}
int main()
{
  long long n, tested;
  cin>>tested;
  while(tested--)
  {
    cin>>n;
    cout<<f(n)<<endl;
  }
  return 0;
}

