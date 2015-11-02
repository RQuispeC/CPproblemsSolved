#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool orden(pair < int, int >   a, pair < int, int >   b)
{
	return a.first<b.first ||( a.first==b.first && a.second<b.second);
}
bool contain ( pair < int, int >   a, pair < int, int >   b)
{
    if(a.first<=b.first && b.second<=a.second)
            return true;
    else return false;        
}
int main()
{
	int tested;
	cin>>tested;
	vector <pair < int, int > > v;
	while(tested--)
	{
		v.clear();
		int m;
		cin>>m;
		int x1,x2;
		bool flag=false;
		while(cin>>x1>>x2)
		{
			if(x1==0 && x2==0) break;
			if( x2>0 )
			{		
				    v.push_back(make_pair(x1,x2)); 
			}
			if(x2>=m && x1<=0)
			{
				cout<<1<<endl;
				cout<<x1<<" "<<x2<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			if(v.size()==0) cout<<0<<endl;
			else
			{
				sort(v.begin(), v.end(), orden);
				if( v[v.size()-1].second < m || v[0].first >=m )
					cout<<0<<endl;
				else
				{	
				  for(int i=1;i<v.size();i++)
					{
                 cout<<v[i].first<<"  "<<v[i].second<<endl;       
					}	
					cout<<"(((((((((((((((((((((((((((("<<endl;
					vector <pair < int, int > > ans;
					ans.clear();
					int t=0;
					ans.push_back(v[0]);
					int h=0;
					for(int i=1;i<v.size();i++)//eliminar intervalos contenido en otros
					{
						  if( !contain(ans[h], v[i]) )
						  {
						      ans.push_back(v[i]);
						      h++;
						  }  
					}
					for(int i=1;i<ans.size();i++)
					{
                 cout<<ans[i].first<<"  "<<ans[i].second<<endl;       
					}	

				}
			}				
		}
		cout<<"---------------"<<endl;	
	}
	return 0;
}
