#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
vector < vi > lista;
int n , m;
unsigned long long cero =0;
struct mask
{
	unsigned long long left, right, one;
	mask()
	{
		left = right =0;
		one=1;
	}
	void set(int lim)
	{
		if(lim<64)
		{
			if(lim==63)
			{
				for(int i=0;i<lim;i++)
					right |= one<<i;
			}
			else
				right = (1ll<<lim) - 1ll;	
		}	
		else
		{
			for(int i=0;i<64;i++)
				right |= one<<i;
			lim-=64;
			left=(1ll<<lim) - 1ll;
		}
	};
	void showLeft()
	{
		string ans="";
		for(int i=0;i<64;i++)
			(left & one<<i)?ans+='1' : ans+='0';
		cout<<ans<<endl;	
	}
	void showRight()
	{
		string ans="";
		for(int i=0;i<64;i++)
			(right & one<<i)?ans+='1' : ans+='0';
		cout<<ans<<endl;
	}
	int bitAt(int pos)
	{
		if(pos<64)
			return right & one<<pos;
		pos-=64;
		return left & 1ll<<pos;
	}
	void setAt(int pos)
	{
		if(pos<64)
			right = right | one<<pos;
		else
		{	
			pos-=64;
			left = left | one<<pos;
		}
	}
	void clearAt(int pos)
	{
		if(pos<64)
		{
			if(right & one<<pos)
				right-= one<<pos;
		}	
		else
		{	
			pos-=64;
			if(left & one<<pos)
				left-= one<<pos;	
		}
	}
	bool operator == (mask other) const
	{
		return left==other.left && right==other.right;
	}
	bool operator < (mask other) const
	{
		return __builtin_popcountll(left) + __builtin_popcountll(right)  < __builtin_popcountll(other.left) + __builtin_popcountll(other.right);
	}
};
void show(mask used, string x)
{
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(i==64) ans+='|';
		(1ll<<i & used.right)? ans+='1':ans+='0';
	}	
	cout<<x<<" "<<ans<<endl;
}
map < mask, int > memo;
mask erase(int cur, mask used)
{
	used.clearAt(cur);
	for(int i=0;i<lista[cur].size();i++)
		used.clearAt(lista[cur][i]);
	return used;
}
bool isEmpty(mask used)
{
	return  used.left==cero && used.right == cero;
}
int f(mask used)
{
	if(used.right != 0ll)
	{
		int u;
		for(u=0;u<min(64, n);u++)
			if(used.one<<u & used.right) break;
		//return memoF[used] = u;
		return u;
	}
	else
	{
		int u;
		for(u=0;u<min(64, n - 64);u++)
			if(used.one<<u & used.left) break;
		return u+64;
	}
}
int cnt=0;
int sol(mask used)
{
	if(isEmpty(used))  return 0;
	if(memo.count(used)) return memo[used];
	int  u = f(used);
	int  ans=0;
	mask tmp= mask();
	tmp.left = used.left;
	tmp.right = used.right;
	tmp.clearAt(u);
	ans = max(1+sol(erase(u, used)), sol(tmp));
	return memo[used] = ans;
}
vi v;
void getSol(mask used)
{
	if(isEmpty(used)) return;
	int  u = f(used);
	mask op1=erase(u, used);
	mask op2= mask();
	op2.left = used.left;
	op2.right = used.right;
	op2.clearAt(u);
	if(sol(op1)+ 1 > sol(op2))
	{
		v.push_back(u);
		getSol(op1);
	}
	else
		getSol(op2);
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)	
	{
		scanf("%d %d", &n, &m);
		lista.assign(n, vi());
		for(int i=0;i<m;i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			lista[x].push_back(y);
			lista[y].push_back(x);
		}
		
		memo.clear();
		mask used=mask();
		used.set(n);
		v.clear();
		
		getSol(used);

		printf("%d\n", (int)v.size());
		for(int i=0;i<v.size();i++)
		{
			printf("%d", v[i] + 1 );
			if(i+1< v.size()) printf(" ");
		}	
		printf("\n");
		//cout<<cnt<<endl;
	}
}
