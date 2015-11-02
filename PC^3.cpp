#include<bits/stdc++.h>
#define MAX
using namespace std;
int n, p[305], submited[305][15], sub, prob, teams, ans[305];
int main()
{
	while(cin>>n>>prob>>teams>>sub)
	{
		if(n==0 && prob==0 && teams==0 && sub==0) break;
		memset(submited, 0 ,sizeof submited);
		memset(ans, 0, sizeof ans);
		for(int i=0;i<prob;i++)
			scanf("%d", &p[i]);
		for(int i=0;i<sub;i++)
		{
			int numT,numPro, time, jud;
			scanf("%d %d %d %d", &numT, &numPro, &time, &jud);
			numT--, numPro--;
			if(!submited[numT][numPro] && !jud)
			{
				ans[numT]+=p[numPro];
				submited[numT][numPro]=1;
			}
		}	
		int maxi=0;
		for(int i=0;i<teams;i++)
		{
			maxi=max(maxi, ans[i]);
		}
		vector < int  > winner;
		winner.clear();
		for(int i=0;i<teams;i++)
		{
			if(ans[i] == maxi)
				winner.push_back(i+1);
		}
		sort(winner.begin(), winner.end());
		cout<<"Contest "<<n<<" Winner: ";
		bool f=0;
		for(int i=0;i<winner.size();i++)
		{
			if(f) cout<<" and ";
			f=1;
			cout<<"Team "<<winner[i];
		}
		cout<<endl;
	}
}

