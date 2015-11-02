#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector < ll > ans;
void generate()
{
	
	set < ll > aux;
	aux.clear();
	for(int a=0;a<=30;a++)
	{
		for(int b=0;b<=20;b++)
		{
			for(int c=0;c<=14;c++)
			{
				for(int d=0;d<=11;d++)
				{
					ll prod=(ll)pow(2,a)* (ll)pow(3,b) * (ll)pow(5,c) *(ll)pow(7,d);		
					if(prod>=0 && prod<=2ll*(ll)1e9)
						aux.insert(prod);
					if(aux.size()==5842)	goto conti;
				}
			}	
		}		
	}
conti:
	ans = vector < ll >  (aux.begin(),aux.end());
}
string f(int n)
{
	if(n%100== 11 || n%100== 12 || n%100== 13)
		return "th";
	if(n%10 ==1)
		return "st";
	if(n%10==2)
		return "nd";
	if(n%10==3)
		return "rd";
	return "th";
}
int main()
{
	generate();
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		cout<<"The "<<n<<f(n)<<" humble number is "<<ans[n-1]<<"."<<endl;
	}	
}

