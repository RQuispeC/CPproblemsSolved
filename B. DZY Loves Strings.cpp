#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
int main()
{
	int a[30],b[30], k;
	string s;
	cin>>s>>k;
	for(int i=0;i<26;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+26);
	reverse(a,a+26);
	long long ans=0ll;
	for(int i=0;i<s.size();i++)
	{
		ans+=(long long)((i+1)*(b[s[i]-'a']));
		//cout<<(i+1)<<": "<<b[s[i]-'a']<<endl; 
	}	
	
	for(int i=1;i<=k;i++)
	{
		ans+=(long long)((i+s.size())*a[0]);
		//cout<<(i+s.size())<<": "<<a[0]<<endl;
	}	
	cout<<ans<<endl;	
		
}

