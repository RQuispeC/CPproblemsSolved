#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef vector < vi > vvi;
int n, a[MAX], b[MAX], strong , weak;
vvi f1()
{
	vvi ans (9, vi());
	for(int i=0;i<n;i++)
		ans[a[i]-1].push_back(i);
	return ans;
}
vvi f2()
{
	vvi ans (9, vi());
	for(int i=0;i<n;i++)
		ans[b[i]-1].push_back(i);
	return ans;	
}
void solve(vvi x, vvi y)
{
	for(int k=0;k<9;k++)
	{
		int cont=0;
		for(int i=0;i<y[k].size();i++)
		{
			if(binary_search(x[k].begin(), x[k].end(), y[k][i]))
			{
				cont++;
			}	
		}
		weak+=(min(x[k].size(), y[k].size()) - cont);
		strong+=cont;
	}
}
int main()
{
	int t=1;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		vvi pat= f1();	
		vector < pair < int , int > > ans;
		ans.clear();
		while(1)
		{
			bool fl=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d", &b[i]);
				if(b[i] != 0 ) fl=1;
			}
			if(!fl) break;
			vvi bus=f2();
			strong=0, weak=0;
			solve(pat, bus);
			ans.push_back(make_pair(strong, weak));
		}
		cout<<"Game "<<t++<<":"<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<"    ("<<ans[i].first<<","<<ans[i].second<<")"<<endl;
	}
}

