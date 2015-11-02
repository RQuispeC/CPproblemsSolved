#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > v;

int BinarySearch(int x, int left, int right)
{
	int m=(left+right)/2;
	if(v[m]==x) return  m;
	else if(left>right) return -1;
	else if(x>v[m]) return BinarySearch( x, m+1, right );	
	else (x<v[m]) return BinarySearch( x, left , m-1 );
}
int main()
{
	int n, m;
	while(scanf("%d %d ", &n , &m) && n!=0 && m!=0)
	{
		v.clear();
		int aux;
		for(int i=0;i<n;i++)
		{		
			scanf("%d", &aux);
			v.push_back(aux);
		}
		sort(v.begin(), v.end());
		for(int i=0;i<m;i++)
		{
			scanf("%d", &aux);
			int pos=BinarySearch(aux, 0, n-1);	
			cout<<"CASE# "<<i+1<<":"<<endl;			
			if(pos!=-1)
			{
				for(int k=pos;k>0;k--)
					if(v[k]==v[k-1]) pos--;
					else break;
				cout<<aux<<" found at "<<pos+1<<endl;
			}			
			else
				cout<<aux<<" not found"<<endl;
		}		
	}
	return 0;
}
