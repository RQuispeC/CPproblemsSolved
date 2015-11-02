#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 200010
using namespace std;
int n;
int cows [MAX];
struct mira
{
	int left,right,index;
	mira()
	{
		left=0;
		right=0;
		index=-1;
	}
	mira(int l, int r, int i)
	{
		left=l;
		right=r;
		index=i;
	}
};
vector < mira > a;
bool orden( mira x, mira y)
{
	return x.left+x.right>y.right+y.left;
}	
void mos( mira x )
{
	cout<<x.left<<"   "<<x.right<<"  :  "<<x.index<<endl;
}
int main()
{
	a.clear();
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>cows[i];
	for(int i=0;i<n;i++)
	{
		if(cows[i]==0)//mira a la izquierda
		{
			a.push_back(mira(i,0,i));
		}
		else// mira a la derecha
		{
			a.push_back(mira(0,n-(i+1),i));
		}
	}
	sort(a.begin(),a.end(),orden);	
	//solution
}
