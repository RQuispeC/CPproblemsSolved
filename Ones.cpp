#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long Ones(int input)
{
    long long N=1;
    int one=1,k;
    while(1)
    {
        if(N<input)
        {
            N=N*10+1;
            ++one;
        }
        k=N%input;
        if(k==0)
            break;
        else
            N=k;
    }
    return one;
}
int main()
{
    int N;
    while(cin>>N)
        cout<<Ones(N)<<endl;
    return 0;
}
