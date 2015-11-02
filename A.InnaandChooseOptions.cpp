#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#define n 12
using namespace std;
int a[6]= {1, 2, 3, 4,6 ,12 };
int b[6]= {12, 6, 4, 3, 2, 1 };
string cards;
vector < int > ans;
void evaluar( int x)
{
	vector < string > aux;
	aux.clear();
	int help=0;
	for(int i=0;i<a[x];i++)
	{
		aux.push_back( cards.substr(help,b[x]) );
		help+=b[x];
	}
	/*cout<<"<<<<<<<<<<<<<<<"<<endl;
	for(int i=0;i<a[x];i++)
		cout<<aux[i]<<endl;	
		*/
	for(int i=0;i<aux[0].size();i++)
	{
		bool flag=true;
		for(int j=0;j<aux.size() ;j++)
		{
			if(aux[j][i]!='X') flag=false;
		}
		if(flag)
		{
			//cout<<"    "<<x<<":  "<<endl;  
			//cout<<" "<<a[x] << "x"<<b[x];   
			ans.push_back(x);
			break;
		}
	}	
}
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		//cout<<"--------------------"<<endl;
		ans.clear();
		cin>>cards;
		
		for(int i=0;i<6;i++)
			evaluar(i);
		cout<<ans.size();
		for(int i=0;i<ans.size();i++)
			cout<<" "<<a[ans[i]]<<"x"<<b[ans[i]];
		cout<<endl;	
	}
	
}

