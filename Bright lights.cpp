#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
const double EPS = 1e-9;
struct point 
{
	int x, y, hight;
	double a;
	point(){}
	point(int X, int Y, int h)
	{
		x=X, y=Y, hight=h;
		if(x!=0)
			a=y/x;
	}
};
int n;
typedef vector < point > vp;
typedef long long ll;
vector < vp > data;
vp ans, dataGen;
ll dist(point p)
{
	return ll(p.x)*ll(p.x) + ll(p.y)*ll(p.y);
}
bool byDist(point p1, point p2)
{
	return dist(p1) < dist(p2);
}
bool byAngle(point p1, point p2)
{
	if(p1.a != p2.a)
		return p1.a < p2.a;
	return dist(p1) < dist(p2);
}
bool byCoordinates(point p1, point p2)
{
	if(p1.x != p2.x)
		return p1.x < p2.x;
	return	p1.y < p2.y;
}
void getSolFrom(vp v)
{
	int maxHight = -1;
	for(int i=0;i<v.size();i++)
	{
		//cout<<v[i].x<<" "<<v[i].y<<" : "<<v[i].hight<<endl;
		if(v[i].hight <= maxHight)
		{
			//cout<<"en"<<endl;
			ans.push_back(v[i]);
		}	
		maxHight=max(maxHight, v[i].hight);
	}	
}
void getSolGeneralFrom (vp v)
{
	for(int i=0;i<data[3].size();i++)
	{
		int j=i;
		dataGen.clear();
		while(j<data[3].size() && data[3][i].a ==data[3][j].a)
		{
			dataGen.push_back(data[3][j]);
			j++;
		}
		getSolFrom(dataGen);
		//for(int it=0;it<dataGen.size();it++)
			//cout<<dataGen[it].x<<" + "<<dataGen[it].y<<endl;	
		//cout<<i<<" ** "<<j<<endl;
		i=j-1;
	}	
}
int main()
{	
	int test=1;
	while(scanf("%d", &n) == 1)
	{
		if(n<=0) break;
		data.assign(4, vp());
		for(int i=0;i<n;i++)
		{
			int x,y,hight;
			scanf("%d %d %d", &x, &y, &hight);
			if(x==0 && y==0)
				continue;
			if(x==0)
			{
				data[0].push_back(point(x,y,hight));
				continue;
			}
			if(y==0)
			{
				if(x>0)
					data[1].push_back(point(x,y,hight));
				else
					data[2].push_back(point(x,y,hight));
				continue;
			}
			data[3].push_back(point(x,y,hight));
		}
		sort(data[0].begin(), data[0].end(), byDist);
		sort(data[1].begin(), data[1].end(), byDist);
		sort(data[2].begin(), data[2].end(), byDist);
		sort(data[3].begin(), data[3].end(), byAngle);
		//cout<<data[0].size()<<data[1].size()<<data[2].size()<<data[3].size()<<endl;
		ans.clear();
		getSolFrom(data[0]);
		getSolFrom(data[1]);
		getSolFrom(data[2]);
		getSolGeneralFrom(data[3]);
		if(ans.size()==0)
		{
			printf("Data set %d:\nAll the lights are visible.\n", test++);
		}
		else
		{
			sort(ans.begin(),ans.end(),byCoordinates);
			printf("Data set %d:\nSome lights are not visible:\n", test++);
			for(int i=0;i<ans.size();i++)
			{
				printf("x = %d, y = %d", ans[i].x, ans[i].y);
				if(i+1 < ans.size()) printf(";\n");
			}	
			printf(".\n");
		}
	}
}
