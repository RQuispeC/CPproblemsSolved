#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
string x;
int ver(int center, bool isPos,int k)
{
	int i, j;
	if(isPos)
		i=center, j=center;
	else
		i=center+1, j=center;
	while(k>=0)
	{
		if(i-1>=0 && j+1 < (int)x.size())
		{
			if(x[i-1] != x[j+1])
			{
				if(k-1>=0)
				{
					i--, j++;
				}
				k--;
			}
			else
				i--, j++;	
		}	
		else break;
	}
	return j-i+1;
	
}
int sol(int k)
{
	int ans=1;
	for(int i=0;i<x.size();i++)
	{
		ans=max(ans, ver(i,1, k));
	}
	for(int i=0;i+1<x.size();i++)
	{
		ans=max(ans, ver(i,0, k));
	}
	return ans;
}
int main()
{
	int test;
	scanf("%d",&test );
	while(test--)
	{
		string s;
		int k;
		cin>>x>>k;
		cout<<sol(k)<<endl;
	}
}

