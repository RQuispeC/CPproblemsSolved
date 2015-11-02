
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(i=0;i<(N);i++)
using namespace std;
int main()
{
    map<string,int> mymap;
    string s;
    int a,i=1;
    FOR(a,26)
    {
        s="";
        s.push_back(a+'a');
        mymap[s]=i++;
    }
    FOR(a,26)
    for(int b=a+1;b<26;b++)
    {
        s="";
        s.push_back(a+'a');
        s.push_back(b+'a');
        mymap[s]=i++;
    }
    FOR(a,26)
    for(int b=a+1;b<26;b++)
    {
        for(int c=b+1;c<26;c++)
        {
            s="";
            s.push_back(a+'a');
            s.push_back(b+'a');
            s.push_back(c+'a');
            mymap[s]=i++;
        }
    }
    FOR(a,26)
    for(int b=a+1;b<26;b++)
    {
        for(int c=b+1;c<26;c++)
        {
            for(int d=c+1;d<26;d++)
            {
                s="";
                s.push_back(a+'a');
                s.push_back(b+'a');
                s.push_back(c+'a');
                s.push_back(d+'a');
                mymap[s]=i++;
            }
        }
    }
    FOR(a,26)
    for(int b=a+1;b<26;b++)
    {
        for(int c=b+1;c<26;c++)
        {
            for(int d=c+1;d<26;d++)
            {
                for(int e=d+1;e<26;e++)
                {
                    s="";
                    s.push_back(a+'a');
                    s.push_back(b+'a');
                    s.push_back(c+'a');
                    s.push_back(d+'a');
                    s.push_back(e+'a');
                    mymap[s]=i++;
                }
            }
        }
    }
    //cout<<i<<endl;
    while(cin>>s)
    {
        cout<<mymap[s]<<endl;
    }
}
