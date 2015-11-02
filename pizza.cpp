#include<bits/stdc++.h>
using namespace std;
int main()
{
    int numTest;
    cin>>numTest;
    while(numTest--)
    {
        int n, m;
        cin>>n>>m;
        if(n<m)
            cout<<"<"<<endl;
        if(n>m)
            cout<<">"<<endl;
        if(n==m)
            cout<<"="<<endl;        
    }    
}

