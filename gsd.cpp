#include<iostream>
#include<vector>
using namespace std;
vector <int> divis;
int total;
int gsd(int x,int y)
{
	if(x%y==0) return y;
	else
		return gsd(y,x%y);
}
int main()
{
	int n, m;
	cin>>n>>m;
	cout<<" $$$ "<<gsd(n,m)<<endl;
	
	return 0;
	
}
