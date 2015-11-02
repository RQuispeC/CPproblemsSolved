#include<bits/stdc++.h>
#define MAX 1000005
#define MAXn (long long) 1000000000000
using namespace std;
typedef long long ll;
typedef vector < int > vi;
bool isP[MAX];
vi  p;
vector < ll > almPrim;
void criba()
{
	memset (isP, true, sizeof isP);
	isP[0] = isP[1] = false;
	for (int i = 2; i * i < MAX; i==2?i++:i+=2)
	if (isP[i])
	for (int j = i * i; j < MAX; j += i) isP[j] = false;
}
void precal()
{
	p.clear();
	almPrim.clear();
	criba();
	for(int i=2;i<MAX;i++)
		if(isP[i])
		{
			p.push_back(i);
		}	
	//get all almost primes
	for(int i=0;i<p.size();i++)
	{
		ll fact=ll(p[i]);
		ll num=fact*fact;
		while(num<=MAXn)
		{
			almPrim.push_back(num);
			num*=fact;
		}
	}
	sort(almPrim.begin(), almPrim.end());
}
int main()
{
	precal();
	int test;
	scanf("%d", &test);
	while(test--)
	{
		ll l,r;
		cin>>l>>r;
		int posL=upper_bound(almPrim.begin(), almPrim.end(), l-1) - almPrim.begin();
		int posH=upper_bound(almPrim.begin(), almPrim.end(), r) - almPrim.begin();
		printf("%d\n", posH - posL);
	}
}

