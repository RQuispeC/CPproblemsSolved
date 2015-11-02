#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int a[4][4];
bool visited [16];
int  points [16];
vector <int > ex;
bool paralel(int a, int b, int c, int d)
{
	if(a==c || b==d) return true;
	return false;
}
 
int main()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			a[i][j];
	int x1,y1,x2,y2;
	bool ans=true;
	int x=0,y=2;
	int l=0;
	for(int i=0;i<4;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		points [l]=x1;
		points [l+1]=y1;
		points [l+2]=x2;
		points [l+3]=y2;
		l+=4;
		if(x1==x2 && y1==y2 )
		{
			ans=false;
			break;
		}
		if(!paralel(x1,y1,x2,y2))
		{
			ans=false;
			break;
		} 
		if(x1==x2)//paralelo al eje y;
		{	
			if(y1<y2)
			{
				a[y][0]=x1;	
				a[y][1]=y1;	
				a[y][2]=x2;	
				a[y][3]=y2;	
			}
			else
			{
				a[y][0]=x2;	
				a[y][1]=y2;	
				a[y][2]=x1;	
				a[y][3]=y1;
			}
			y++;
		}
		else //paralelo al eje x
		{	
			if(x1<x2)
			{
				a[x][0]=x1;	
				a[x][1]=y1;	
				a[x][2]=x2;	
				a[x][3]=y2;	
			}
			else
			{
				a[x][0]=x2;	
				a[x][1]=y2;	
				a[x][2]=x1;	
				a[x][3]=y1;	
			}
			x++;
			
		}
			
	}
	if(ans)
	{
		if(a[0][0]!=a[1][0] || a[0][2]!=a[1][2] || a[0][1]==a[1][1]  )
			ans=false;
		if(a[2][1]!=a[3][1] || a[2][3]!=a[3][3] || a[2][0]==a[3][0]  )
			ans=false;		
	}
	if (ans)
	{
		ex.clear();
		for(int i=0 ;i<16;i++) visited[i]=false;
		for(int i=0 ;i<16;i+=2)
		{
			if(!visited[i])
			{	
				int total=1;
				visited[i]=true;
				visited[i+1]=true;
				for(int j=i+2;j<16;j+=2)
				{
					if(!visited[j] && points[i]==points[j] && points[i+1] ==points[j+1])
					{	
						total++;
						visited[j]=true;
						visited[j+1]=true;	
					}
				}
				if(total==2) ex.push_back(i);
			}		
		}
		if(ex.size()!=4)
			ans=false;
	}
	if(ans) cout<<"YES"<<endl;
	else    cout<<"NO"<<endl;
	return 0;
}
