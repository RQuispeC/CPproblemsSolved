#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1010
using namespace std;
int n;
vector < string > a;
int main()
{
	cin>>n;
	int ans=0;
	bool coder=true;
	a.clear();
	if(n%2!=0)
	{
		for(int i=0;i<n;i++)
		{
			string line="";
			for(int j=0;j<n;j++)
			{
				if(coder)
				{
					ans++;
					line+="C";
				}
				else line+=".";
				coder=!coder;
			}
			a.push_back(line);	
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			string line="";
			for(int j=0;j<n;j++)
			{
				if(coder)
				{
					ans++;
					line+="C";
				}
				else line+=".";
				coder=!coder;
			}
			coder=!coder;
			a.push_back(line);	
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}
