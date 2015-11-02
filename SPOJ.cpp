#include<bits/stdc++.h>
#define MAX 10
using namespace std;
typedef vector < int > vi;
typedef pair  < int, int > pii; 
typedef vector < pii > vii;
int n;
bool ans;
vi v;
vector < string >  a;
int numDig (int x)
{
	int ans=1;
	while(x>0)
	{
		x/=10;
		ans++;
	}	
	return ans;
}
string reverse(string x)
{
	string ans="";
	for(int i=x.size()-1;i>=0;i--)
		ans+=x[i];
	return ans;	
}
string normal(int x, int l)
{
	string ans="";
	int lim=numDig(x)-1;
	for(int i=0;i<lim;i++)
	{
		ans+=(char(x%10) + '0');
		x/=10;
	}
	//cout<<"ne"<<endl;
	ans=reverse(ans);
	//cout<<"ne"<<endl;
	char  f = (char)('a'-1);
	for(int i=ans.size();i<l;i++)
		ans+=f;
	//cout<<"ne"<<endl;	
	return ans;	
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d",&n);
		v.clear();
		int maxL=-1;
		for(int i=0;i<n;i++)
		{
			int s;
			maxL=max(maxL, s);
			scanf("%d", &s);
			v.push_back(s);
		}
		maxL=numDig(maxL);
		sort(v.begin(), v.end());
		cout<<"pas"<<endl;
		for(int i=0;i<n;i++)
		{
			
			a.push_back(normal(v[i],maxL));
			//cout<<"as"<<endl;
			cout<<v[i]<<" :  "<<a[i]<<endl;
		}	
		cout<<maxL<<endl;	
	}
}

