#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath> 
using namespace  std;
struct weed
{
	int left, right, row;
	weed()
	{
		row=-1;
		left=right=-1;
	}
	weed(int l , int r, int ro)
	{
		left=l;
		right=r;
		row=ro;
	}
};
vector < string > a;
vector < weed > w;
int n,m;

int main()
{
	a.clear();
	w.clear();
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string aux;
		cin>>aux;
		a.push_back(aux);
	}
	int auxMin=1000;
	int auxMax=-1;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		int l,r;
		bool flag2=false;
		l=n;
		r=-1;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='W')
			{
				flag2=true;
				l=min(l,j);
				r=max(r,j);
				//cout<<l<<" :  "<<r<<endl;
			}
		}
		if(flag2)
		{	
			flag=true;
			w.push_back(weed(l,r,i));
			auxMin=min(auxMin,i);
			auxMax=max(auxMax,i);
		}
	}
	int ans;
	if(flag) ans=auxMax-auxMin;
	else ans=0;
	for(int i=0;i<w.size();i++)
	{
		//cout<<w[i].row<<" :  "<<w[i].left<<" :  "<<w[i].right<<endl;
		ans+=( w[i].right - w[i].left );
	}
	if(w.size()>0)
		ans+=w[0].left +w[0].row;
	int dir=0; // 0 derecha, 1 izquierda; 
	for(int i=0;i+1<w.size();i++)
	{
		if(dir==0)
		{
			ans+=min( abs(w[i].right - w[i+1].left), abs ( w[i].right - w[i+1].right ) );
			if( abs(w[i].right - w[i+1].left) > abs ( w[i].right - w[i+1].right ) ) // cambiar dirección
				dir=(dir+1)%2;
		}
		else
		{
			ans+=min( abs(w[i].left - w[i+1].left), abs ( w[i].left - w[i+1].right ) );
			if( abs(w[i].left - w[i+1].left) < abs ( w[i].left - w[i+1].right ) )  //cambiar dirección
				dir=(dir+1)%2;
		}
	}
	cout<<ans<<endl;
}
