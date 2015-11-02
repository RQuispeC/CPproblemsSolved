#include<bits/stdc++.h>
#define MAX 25
using namespace std;
int n,  p[MAX], c[MAX], f[MAX], acuP[MAX], acuC[MAX], acuF[MAX];
int pn, cn, fn;
bool sol(int pos, int prot, int carb, int fat)
{
	if(prot==0 && carb==0 && fat==0) return 1;
	if(pos==n) return 0;
	if(acuP[pos] < prot || acuC[pos] < carb  || acuF[pos] < fat)
		return 0;
	if(prot < p[pos] || carb <c[pos] || fat<f[pos])
		return sol(pos+1, prot, carb, fat);
	else
		return 	sol(pos+1, prot, carb, fat) or sol(pos+1, prot - p[pos], carb -c[pos], fat -f[pos]);
	
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int te=1;te<=test;te++)
	{
		scanf("%d %d %d", &pn, &cn, &fn);
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d %d %d", &p[i], &c[i], &f[i]);
					
		for(int i=n-1;i>=0 ;i--)
			if(i==n-1)
			{
				acuP[i]=p[i];
				acuC[i]=c[i];
				acuF[i]=f[i];
			}
			else
			{
				acuP[i]=p[i] + acuP[i+1];
				acuC[i]=c[i] + acuC[i+1];
				acuF[i]=f[i] + acuF[i+1];
			}
			
		bool ans = sol(0,pn, cn, fn);
			
		if(ans)
			printf("Case #%d: yes\n", te);
		else
			printf("Case #%d: no\n", te);
	}
}

