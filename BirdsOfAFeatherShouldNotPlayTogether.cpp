#include<bits/stdc++.h>
using namespace std;
map < string , int >  mapa2;
vector  < vector < int > > v;
int  frec[200];
double p[200], ans[10];
int main()
{
	string s;
	int r=1;
	while(getline(cin ,s))
	{
		v.assign(10, vector <int>()) ;
		mapa2.clear();
		memset(ans, 0.0, sizeof ans);
		memset(frec, 0, sizeof frec);
		int n=atoi(s.c_str());
		if(n==0 ) break;
		string aux;
		int  k2=1;
		vector < string >  pal,nom;
		pal.clear(), nom.clear();
		for(int i=0;i<n;i++)
		{
			getline(cin , s);
			stringstream in(s);
			in>>aux;
			nom.push_back(aux);
			while(in>>aux)
			{
				if(mapa2[aux] == 0 ) 
				{
					mapa2[aux]=k2++;
					pal.push_back(aux);
				}
				//cout<<"rne"<<endl;
				v[i].push_back(mapa2[aux]);
				frec[mapa2[aux]]++;
			}
		}
		for(int i=0;i<pal.size();i++)
		{
			p[mapa2[pal[i]]]=((pal[i].size())* 2520)/frec[mapa2[pal[i]]];
			//2520 vueve entero todos los resultados, 2520=MCD(1, 2, 3, 4, 5, 6, 7, 8, 9)
		}	
		double maxi=0.0;	
		for(int i=0;i<n;i++)
		{
			double tot=0;
			for(int j=0;j<v[i].size();j++)
			{
				tot+=p[v[i][j]];
			}
			ans[i]=tot;
			maxi=max(maxi, tot);
		}	
		cout<<"Round "<<r++<<endl;
		vector < string > win;
		win.clear();
		for(int i=0;i<n;i++)
		{
			if(ans[i]==maxi)
				win.push_back(nom[i]);
		}
		for(int i=0;i<win.size();i++)
		{
			cout<<win[i];
			if(i+1<win.size()) cout<<" ";
		}
		cout<<endl;
				
	}
}

