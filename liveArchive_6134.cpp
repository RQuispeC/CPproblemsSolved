#include <iostream>
#include <cstring>
#include <vector>
#define MAX 5002
using namespace std;
int f(int n)
{
    vector  <int > a ;
    a.clear();
    int dig=0;
    while(n>0)
    {
      a.push_back(n%10);
      n/=10;
      dig++;
    }
    if(dig==1 ) return 1;
    else if(dig==2)
         if(a[0]==a[1])  return 0;
         else return 1;
    else if(dig==3)
         if(a[0]==a[1] || a[0]==a[2] || a[1]==a[2]) return 0;
         else return 1;
    else if(dig==4)
          if(a[0]==a[1] || a[0]==a[2] || a[0]==a[3] || a[1]==a[2] || a[1]==a[3] || a[2]==a[3]) return 0;
          else return 1;
                 
}
int main()
{ 
    int n,m;
    int ans[MAX];
    memset(ans,0,sizeof(ans));
    ans[0]=0;
    for(int i=1;i<MAX;i++)
    {
        ans[i]=ans[i-1]+f(i);
    } 
    while(cin>>n>>m)
    {
            cout<<ans[m]-ans[n-1]<<endl;   
    }
    return 0;
}

