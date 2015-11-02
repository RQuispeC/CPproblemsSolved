#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
struct point
{
	 int x, y, z;
	 point(){}
	 point(int X,int Y, int Z)
	 {
		x=X;
		y=Y;
		z=Z;
	 }
	 bool operator < (point p) const
	 {
	 	long long n1=x*x + y*y +z*z;
	 	long long n2=p.x*p.x + p.y*p.y +p.z*p.z;
	 	return n1<n2;
	 }
	 bool operator == (point p) const
	 {	
	 	return x==p.x && y==p.y && z==p.z;
	 }
	 point operator - ( point p) const
	 {
	 	return  point(x-p.x, y-p.y, z-p.z);
	 }
};
point  a[8];
vector < point > posi[8];
map < long long , int > m;
vector < long long > ve;
vector < point > permu(point p)
{
	vector < point  > per ,ans;
	per.clear();
	ans.clear();
	per.push_back(point(p.x, p.y, p.z));
	per.push_back(point(p.x, p.z, p.y));
	per.push_back(point(p.y, p.x, p.z));
	per.push_back(point(p.y, p.z, p.x));
	per.push_back(point(p.z, p.x, p.y));
	per.push_back(point(p.z, p.y, p.x));
	bool use[6];
	memset(use, 0, sizeof use);
	for(int i=0;i<6;i++)
	{
		if(!use[i])
		{
			for(int j=i+1;j<6;j++)
				if(per[i]==per[j])
				{
					use[i]=use[j]=1;
				}
			ans.push_back(per[i]);
		}	
	}
	return ans;
}
long long dist(point x, point y)
{
	
	return ll(x.x-y.x)*ll(x.x-y.x) + ll(x.y-y.y)*ll(x.y-y.y) + ll(x.z-y.z)*ll(x.z-y.z);
}
bool esCubo(point c[8])
{
	int cont=0;
	for(int i=0;i<8 ;i++)
	{
		bool f=0;
		m.clear(), ve.clear();
		for(int j=0;j<8 ;j++)
		{
			if(i!=j)
			{
				long long d=dist(c[i], c[j]);
				if(m[d] == 0)
					ve.push_back(d);
				m[d]++;		
			}
		}
		sort(ve.begin(), ve.end());
		f |= (2*ve[0]==ve[1] && 3*ve[0]==ve[2] && m[ve[0]]==3 && m[ve[1]]==3 && m[ve[2]]==1);
		if(f) cont++;
	}
	return cont==8;
}
bool genera(point c[8], int pos)
{	
	for(int i=0;i<pos;i++)
	{
		m.clear(), ve.clear();
		for(int j=0;j<pos ;j++)
		{
			if(i!=j)
			{
				long long d=dist(c[i], c[j]);
				if(!m.count(d))
					ve.push_back(d);
				m[d]++;
			}
		}
		sort(ve.begin(), ve.end());
		if (ve.size()==1)
		{
			if(m[ve[0]] > 3)
				return 0;
		}
		if(ve.size() == 2)
		{
			if( (2*ve[0] != ve[1] && 3*ve[0] != ve[1] && 3*ve[0] != 2* ve[1]))
			{
				return 0; 
			}	
		}	
		else if(ve.size() == 3)
		{
			if(  ( 2*ve[0] != ve[1] && 3*ve[0] != ve[2]))
			{
				return 0;
			}	
		}	
		if(ve.size() > 3)
		{
			return 0;
		}
	}
	return 1;
}
void llenarPosi()
{
	for(int i=0;i<8;i++)
		posi[i]=permu(a[i]);
}
int j;
bool sol(int pos)
{
	if(pos==8 )
	{
		if(esCubo(a)) return 1;
		else return 0;	
	}	
	if(pos>=3)
	{
		if(!genera(a, pos))
			return 0;
	}
	int ans=0;
	for(int i=0;i<posi[pos].size();i++)
	{
		if(pos==0 || ( pos>=1 && !(posi[pos][i] == a[pos-1])))  
		{
			a[pos]=posi[pos][i];
			ans += sol(pos+1);
		}
		if(ans)
			break;				
	}
	return ans;
}
int main()
{
	for(int i=0;i<8;i++)
	{
		int x, y, z;
		cin>>x>>y>>z;
		a[i]=point(x,y,z);
	}
	llenarPosi();
	j=0;
	bool f=sol(0);
	if(f)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<8;i++)
		{
			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<endl;
		}
	}
	else
		cout<<"NO"<<endl;
}
//http://www.spoj.com/problems/BAT1/
//http://www.spoj.com/problems/DCEPC807/
//http://www.spoj.com/problems/BAT2/
