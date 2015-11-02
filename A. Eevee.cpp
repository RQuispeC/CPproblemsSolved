#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	string pok[8]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
	int n ;
	string s;
	cin>>n>>s;
	int pos=-1, pamax=0;
	for(int i=0;i<8;i++)
	{
		if(pok[i].size()==n)
		{
			int pa=0;
			for(int j=0;j<n;j++)
				if(pok[i][j]==s[j])
					pa++;
			if(pa>=pamax)
			{
				pos=i;		
				pamax=pa;
			}	
			//cout<<pok[i]<<" : "	<<pa<<endl;
		}
	}
	cout<<pok[pos]<<endl;
		
}

