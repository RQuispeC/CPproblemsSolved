#include<bits/stdc++.h>
using namespace std;
typedef pair < int  , int > pii;
vector < string > grip;
int ans,n , m ,d;
pii pos;
char face;
bool validate(pii x)
{
	return x.first>=0 && x.second>=0 && x.first<n && x.second<m && grip[x.first][x.second] != '#';
}
void run(char op)
{
	if(op=='F')
	{
		bool change=false;
		if(face=='N')
		{
			pii np= pii(pos.first - 1, pos.second);
			if(validate(np))
				pos=np, change=1;
		}
		else if(face=='S')
		{
			pii np= pii(pos.first + 1, pos.second);
			if(validate(np))
				pos=np, change=1;
		}
		else if(face=='W')
		{
			pii np= pii(pos.first , pos.second -1);
			if(validate(np))
				pos=np, change=1;	
		}
		else if(face=='E')
		{
			pii np= pii(pos.first , pos.second +1);
			if(validate(np))
				pos=np, change=1;	
		}
		if(change && grip[pos.first][pos.second]=='*')
			ans++, grip[pos.first][pos.second]='.';
		//cout<<"-->"<<ans<<endl;	
	}
	else if (op=='D')
	{
		if(face=='N')
		{
			face='E';
		}
		else if(face=='S')
		{
			face='W';
		}
		else if(face=='W')
		{
			face='N';
		}
		else if(face=='E')
		{
			face='S';
		}
	}
	else if (op=='E')
	{
		if(face=='N')
		{
			face='W';
		}
		else if(face=='S')
		{
			face='E';
		}
		else if(face=='W')
		{
			face='S';
		}
		else if(face=='E')
		{
			face='N';
		}
	}	
}
int main()
{
	while(scanf("%d %d %d", &n,&m, &d ))
	{
		if(n<=0  && m<=0 && d<=0  ) break;
		grip.clear();
		for(int i=0;i<n;i++)
		{
			string a;
			cin>>a;
			grip.push_back(a);
			for(int j=0;j<a.size();j++)
			{
				if(a[j]=='N') 
				{
					face='N';
					pos=pii(i,j);
					grip[i][j]='.';
				}
				else if (a[j]=='S') 
				{
					face='S';
					pos=pii(i,j);
					grip[i][j]='.';
				}
				else if (a[j]=='L') 
				{
					face='E';
					pos=pii(i,j);
					grip[i][j]='.';
				}
				else if (a[j]=='O') 
				{
					face='W';
					pos=pii(i,j);					
					grip[i][j]='.';
				}								
			}	
		}
		//cout<<pos.first<<"  "<<pos.second<<" -- >"<<face<<endl;
		string dir;
		cin>>dir;
		ans=0;
		for(int i=0;i<d;i++)
		{
			run(dir[i]);
			//cout<<dir[i]<<endl;
			//cout<<pos.first<<"  "<<pos.second<<" -- >"<<face<<endl;
		}	
		cout<<ans<<endl;
		//cout<<"-----------------"<<endl;	
	}
}

