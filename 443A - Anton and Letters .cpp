#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
int main()
{
    string s;
    getline(cin , s);
    if(s.size()>2)
    {
		int a[30];
		memset(a, 0, sizeof a);
		for(int i=1;i<s.size();i+=3)
		{
			a[s[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<30;i++)
			if(a[i]>0) ans++;
		cout<<ans<<endl;	
    }
    else
    	cout<<0<<endl;
}

