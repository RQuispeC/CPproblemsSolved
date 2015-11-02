/*
ID: your_id_here
PROG: milk2
LANG: C++ 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
struct i
{
	int l, r;
	i(){}
	i(int left, int right)
	{
		l=left;
		r=right;
	}
};
int n;
vector < i > a;
bool orden( i x, i y)
{
	if(x.l==y.l)
		return x.r>y.r;		
	return x.l<y.l;	
}
int main() {
	a.clear();
    ofstream fcout ("milk2.out");
    ifstream fcin  ("milk2.in");
    fcin>>n;
    for(int k=0;k<n;k++)
    {
		int l,r;
		fcin>>l>>r;
		a.push_back(i(l,r));  	
    }
    vector < i > ans;
    int mi=0, ma=0;
    int k=0;
    if(n==1)
    {
    	fcout<<a[0].r-a[0].l<<" "<<0<<endl;
    	goto totem1;
    }
    sort(a.begin(), a.end() , orden);
    //cout<<"pas"<<endl;
    //reverse(a.begin(), a.end());
    //cout<<"pas"<<endl;
    //for(int i=0;i<n;i++)
    	//cout<<a[i].l<<"  "<<a[i].r<<endl;

    ans.clear();
    while(true)
    {
    	if(k>=n-1 || k+1>n-1) break;
    	int j=k+1;
    	int ini=a[k].l;
    	int fin=a[k].r;
    	while(fin>=a[j].l)
    	{
    		if(j==n) 
    		{
    			j++;
    			break;
    		}	
    		fin=max(fin,a[j].r);    		
    		j++; 		
    	}
    	ans.push_back(i(ini, fin));
    	k=j;
    	if(k==n-1) ans.push_back(a[k]);
    }
    //cout<<"asssss"<<endl;
    for(int k=0;k<ans.size();k++)
    	//cout<<ans[k].l<<" "<<ans[k].r<<endl;
    //cout<<"asasasa"<<endl;
    for(int k=0;k<ans.size();k++)
    {
    	ma=max(ma, ans[k].r-ans[k].l);
    }
    for(int k=0;k+1<ans.size();k++)
    {
    	mi=max(mi, ans[k+1].l- ans[k].r);
    }
    fcout<<ma<<" "<<mi<<endl;	
    totem1:;
    return 0;
}
