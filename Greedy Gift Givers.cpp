/*
ID: your_id_here
PROG: gift1
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
map < string , int > m;
int main()
{
    ofstream fcout ("gift1.out");
    ifstream fcin ("gift1.in");
	m.clear();
	int ans[15];
	int ini[15];
	string names[15];
	memset( ans , 0, sizeof ans);
	memset( ini , 0, sizeof ini);
	int n, k=1;
	fcin>>n;
	for(int i=0;i<n;i++)
	{
		string aux;
		fcin>>aux;
		m[aux]=k;
		names[k]=aux;
		k++;
	}
	for(int i=0;i<n;i++)
	{
		string na;
		int mon, numPer;
		fcin>>na>>mon>>numPer;
		if(numPer!=0)
		{
			ini[ m [ na ] ] = mon;
			int cad=mon/numPer;
			for(int j=0;j<numPer;j++)
			{
				string per;
				fcin>>per;
				ans[ m [ per]]+=cad;
			}
			ans [ m [ na ] ] += mon%numPer;
		}
	}
	for(int i=1;i<=n;i++)
	{
		fcout<<names[i]<<" "<<ans[i] -ini [i]<<endl;
	}
	return 0;
}
