#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	int n;
	string ini;
	cin>>n>>ini;
	string ans="";
	int carry=1;
	for(int i=0;i<n;i++)
	{
		if(carry==0 && ini[i]=='0')
		{
			ans+="0";
			carry=0;
		}
		else if(carry==0 && ini[i]=='1')
		{
			ans+="1";
			carry=0;			
		}
		else if(carry==1 && ini[i]=='0')
		{
			ans+="1";
			carry=0;		
		}
		else 
		{
			ans+="0";
			carry=1;		
		}	
	}
	//cout<<ans<<endl;
	int cont=0;
	for(int i=0;i<n;i++)
		if(ans[i]!=ini[i])
			cont++;
	cout<<cont<<endl;		
}	

