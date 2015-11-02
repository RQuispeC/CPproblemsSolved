#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
int n , m;
vector < string > grip;
bool validate (int i, int j)
{
	return i>=0 && j>=0 && i<n && j<m;
}
int main()
{
	bool col=0;
	char  c [111][111];
	for(int i=0;i<111;i++)
    {
    	for(int j=0;j<111;j++)
    	{
    		if(col==0)
					c[i][j]='B';
				else
					c[i][j]='W';
			col = not col;	
    	}
    }	
	grip.clear();
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	string a;
    	cin>>a;
    	grip.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(grip[i][j]=='.')
    		{
				//cout<<i<<"  : "<<j<<" __ "<<con1<<" __ "<<con2<<endl;
				
				grip[i][j]=c[i][j];
			}
    	}
    }	
    for(int i=0;i<n;i++)
    {
		cout<<grip[i]<<endl;	
    }	
}

