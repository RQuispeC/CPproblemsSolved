#include<iostream>
#define MAX 5010
using namespace std;
int ini[MAX];//inicio de intervalos
int fin[MAX];//fin de intervalos	
int main()
{
	string st;
	cin>>st;
	if(st.size()>=3)
	{
		int n=0;
		for(int i=0 ; i<st.size()-3 ;i++)
		{
			int j=i+3;
			if(st[i]=='b' && st[i+1]=='e' && st[i+2]=='a' && st[i+3]=='r')
			{
				ini[n]=i;
				fin[n]=j;
				n++;
			}
		}
		int k=0;
		long long ans=0;
		for(int i=0; i<st.size()-3;i++)
		{
			if(i>ini[k]) k++;
			if(k>=n) break;
			int j=i+3;
			int tot=st.size()-j;
			tot-=fin[k]-j;
			ans+=tot;
		}
		cout<<ans<<endl;
	}
	else
		cout<<0<<endl;
}
