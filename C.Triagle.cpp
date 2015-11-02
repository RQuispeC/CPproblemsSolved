#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<map>
using namespace std;
int a,b;
bool posib( pair < int , int > x, pair < int , int > y)
{
	pair < int , int > nx=make_pair(abs(x.first), abs(x.second));
	pair < int , int > ny=make_pair(abs(y.first), abs(y.second));
	int xp=ny.first;
	int yp=nx.first;
	//cout<<nx.first<<"  "<<nx.second<<"  :  "<<ny.first<<" "<<ny.second<<endl;
	if(xp*nx.second==yp*ny.second) return true;
	return false;
}
bool paral1( pair < int , int > x, pair < int , int > y)
{
	if(abs(x.second) == abs (y.second) ) return true;
	return false;
}
bool paral2( pair < int , int > x, pair < int , int > y)
{
	if(abs(x.first) == abs(y.first) ) return true;
	return false;
}
pair < int , int > inver( pair < int, int > x)
{
	return make_pair(-x.second , x.first);
}
int main()
{
	cin>>a>>b;	
	int temp1=max(a,b), temp2=min(a,b);
	a=temp1;
	b=temp2;
	int xa=-1,xb=-1,ya=-1,yb=-1 ;
	vector < pair < int , int > > A;
	vector < pair < int , int > > B; 
	A.clear();
	B.clear();
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
		//	cout<<i<<" "<<j<<endl;
			//cout<<i*i+j*j<<endl;
			if(i*i+j*j==a*a)
			{
				xa=i;
				ya=j;
				A.push_back(make_pair(max(i,j), min(i,j) ));
			}
		}
	}
	for(int i=1;i<=b;i++)
	{
		for(int j=i;j<=b;j++)
		{
			if(i*i+j*j==b*b)
			{
				xb=i;
				yb=j;
				B.push_back(make_pair(max(i,j), min(i,j) ));
			}
		}
	}  
	if(xa!=-1 && xb!=-1 && ya!=-1 && yb!=-1)
	{
		if(a==b)
		{
			cout<<"YES"<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<min(xa, ya)<<" "<<max(ya,xa)<<endl;
			cout<<-max(xb,yb)<<" "<<min(yb,xb)<<endl;
		}
		else
		{
			bool flag=false;
			for(int i=0;i<A.size() ;i++)
			{
				if(flag) break;
				pair < int , int > in=inver(A[i]);
				for(int j=0;j<B.size() ;j++)
				{
					if(flag) break;
					if ( posib (in, make_pair(-B[j].first, B[j].second) ) && !paral1 ( A[i] , make_pair(-B[j].first, B[j].second ) ) )
					{
						cout<<"YES"<<endl;
						cout<<0<<" "<<0<<endl;
						cout<<A[i].first<<" "<<A[i].second<<endl;
						cout<<-B[j].first<<" "<<B[j].second<<endl;
						flag=true;
					}
					else if ( posib( in, make_pair(-B[j].second, B[j].first ) ) && !paral1( A[i], make_pair(-B[j].second, B[j].first) ) )
					{
						//if(paral1( in, make_pair(-B[j].second, B[j].first) )) cout<<"no "<<in.second<<" "<<B[j].first<<endl;
						cout<<"YES"<<endl;
						cout<<0<<" "<<0<<endl;
						cout<<A[i].first<<" "<<A[i].second<<endl;
						cout<<-B[j].second<<" "<<B[j].first<<endl;
						flag=true;
					}
					else if ( posib(in, make_pair(B[j].first, -B[j].second ) ) && !paral2 (A[i], make_pair ( B[j].first, -B[j].second ) ) )
					{
						cout<<"YES"<<endl;
						cout<<0<<" "<<0<<endl;
						cout<<A[i].first<<" "<<A[i].second<<endl;
						cout<<B[j].first<<" "<<-B[j].second<<endl;
						flag=true;
					}
					else if ( posib ( in, make_pair(B[j].second, -B[j].first ) ) && !paral2( A[i], make_pair(B[j].second, -B[j].first ) ) )
					{
						cout<<"YES"<<endl;
						cout<<0<<" "<<0<<endl;
						cout<<A[i].first<<" "<<A[i].second<<endl;
						cout<<B[j].second<<" "<<-B[j].first<<endl;
						flag=true;
					}
				}
			}
			if(!flag)
				cout<<"NO"<<endl;
			
		}
	}
	else
		cout<<"NO"<<endl;
}

