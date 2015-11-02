#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
struct par
{
	int a, b;
	par(){}
	par(int A, int B)
	{
		a=A, b=B;
	}
	bool operator < (par x) const
	{
		return (a-b) < (x.a -x.b);
	}
};
par fin[MAX];
int n, num[MAX];
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d", &num[i]);
		}
		sort(num, num+n);
		reverse(num, num+n);
		int sum1=0, sum2=0, k=0;
		for(int i=0;i<n;i+=2)
		{
			sum1+=num[i];
			sum2+=num[i+1];
			fin[k++]=par(num[i], num[i+1]);
		}
		//cout<<sum1<<" - "<<sum2<<endl;
		if(sum2>=sum1)
		{
			cout<<-1<<endl;
			continue;
		}
		n/=2;
		sort(fin, fin+n);
		//for(int i=0;i<n;i++)
			//cout<<fin[i].a<<" : "<<fin[i].b<<" --> "<<fin[i].a - fin[i].b<<endl;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int dif=fin[i].a - fin[i].b;
			if((sum1 - dif ) > (sum2 + dif) )
			{
				ans++;
				sum1-=dif;
				sum2+=dif;
			}
			else
				break;
		}	
		cout<<ans<<endl;
	}
}

