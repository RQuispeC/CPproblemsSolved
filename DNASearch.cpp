#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
map < string , int   > m;
vector < int  >  a[1000005];
string s;
void precalc()
{
	int k=1;
	for(int i=0;i+8<s.size();i++)
	{
		string d=s.substr(i,9);
		if(m[d]==0)
		{
			m[d]=k;
			a[k].push_back(i);
			k++;
		}
		else
		{
			a[m[d]].push_back(i);
		}
	}	
}
int main()
{
	int tested;
	cin>>tested;
	bool b=0;
	int query;
	while(tested--)
	{
		if(b) cout<<endl;
		b=1;
		cin>>s>>query;
		m.clear();
		for(int i=1;i<s.size();i++)
			a[i].clear();	
		precalc();		
		for(int i=0;i<query;i++)
		{
			string q;
			cin>>q;
			int pos=m[q];
			if(pos==0)
				printf("No occurrences found.\n");
			else
			{
				for(int j=0;j<a[pos].size();j++)
				{
					printf("%d",a[pos][j] );
					if(j+1<a[pos].size())
						printf(" ");
				}
				printf("\n");
			}	
		}
	}
}

