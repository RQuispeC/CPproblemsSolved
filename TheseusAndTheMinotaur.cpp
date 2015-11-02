#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool visited[ 30];
vector < int > a [30];
int teseus, minotauro, k;
void move( int num)
{
	//cout<<num<<"  : "<<teseus<<"  * *  "<<minotauro<<endl;
	if(num==k)
	{
		visited[teseus]=true;
		num=0;
		cout<<char(teseus+'A')<<" ";
	}
	bool  flag=true;
	for(int i=0;i<a[minotauro].size();i++)
	{
		if(!visited[a[minotauro][i]]  && a[minotauro][i]!=teseus)
		{
			teseus=minotauro;
			minotauro=a[minotauro][i];
			move( num+1);
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<"/"<<char(minotauro+'A')<<endl;
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="#") break;
		for(int i=0;i<30;i++)
			a[i].clear();
		memset(visited, false, sizeof visited);	
		int j;	
		for(int i=0;i+1<s.size();i++)
		{
			if(s[i+1]==':')
			{
				j=s[i]-'A';
				//cout<<j<<":  "<<endl;	
				i=i+2;	
				while(s[i]!=';' && i+1<s.size())
				{
					//cout<<s[i]-'A'<<endl;
					a[j].push_back(s[i]-'A');
					i++;	
				}	
			}	
		}
		cin>>s;
		minotauro=s[0]-'A'; 
		cin>>s;
		teseus=s[0]-'A';
		cin>>k;
		//visited[teseus]=true;
		move(0);
	}	
}

