#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(s.size()>10)
		{
			cout<<s[0]<<s.size()-2<<s[s.size() -1 ]<<endl;
		}
		else
			cout<<s<<endl;
	}	
}

