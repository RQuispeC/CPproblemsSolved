#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 50005
#define foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair < int64, int64 > pll;
map < pii, int  > frec;
string  a[15];
int n, k;
vii  v[15];
void getV(int ind)
{
	cout<<ind<<" --> "<<endl;
	v[ind].clear();
	stack < pii > q;
	for(int i=0;i<n;i++)
	{
		if(q.empty())
			q.push(pii(a[ind][i],i));
		else
		{
			if(a[ind][i]=='(')
				q.push(pii(a[ind][i],i));
			else
			{
				if(q.top().first=='(')
				{
					v[ind].push_back(pii(q.top().second, i));
					cout<<q.top().second<<" : "<<i<<endl;
					frec[pii(q.top().second, i)]++;
					q.pop();
				}	
				else	
					q.push(pii(a[ind][i], i));
			}	
		}	
	}
}
int main()
{
	//freopen("cbs.in", "r", stdin);
	//freopen("cbs.out", "w", stdout);
	
	scanf("%d %d", &k, &n);
	for(int i=0;i<k;i++)
		cin>>a[i];
		
	frec.clear();
	for(int i=0;i<k;i++)
		getV(i);
	
	int ans=0;
	foreach(frec, it)
		if(it->second == k)
			ans++;
	cout<<ans<<endl;	
}

