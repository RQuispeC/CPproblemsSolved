#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
	map<string , int > m;
	int cont=1, ls=26;
	for(int i=0;i<ls;i++)
	{
		string aux="";
		aux.push_back(i+'a');
		m[aux]=cont;
		cont++;
	}
	for(int i=0;i<ls;i++)
		for(int j=i+1;j<ls;j++)
		{
			string aux="";
			aux.push_back(i+'a');
			aux.push_back(j+'a');
			m[aux]=cont;
			cont++;	
		}
	for(int i=0;i<ls;i++)
		for(int j=i+1;j<ls;j++)
			for(int k=j+1;k<ls;k++)
			{
				string aux="";
				aux.push_back(i+'a');
				aux.push_back(j+'a');
				aux.push_back(k+'a');
				m[aux]=cont;
				cont++;	
			}	
	for(int i=0;i<ls;i++)
		for(int j=i+1;j<ls;j++)
			for(int k=j+1;k<ls;k++)
				for(int l=k+1;l<ls;l++)
				{
					string aux="";
					aux.push_back(i+'a');
					aux.push_back(j+'a');
					aux.push_back(k+'a');
					aux.push_back(l+'a');
					m[aux]=cont;
					cont++;	
				}
	for(int a=0;a<26;a++)
    for(int b=a+1;b<26;b++)
    {
        for(int c=b+1;c<26;c++)
        {
            for(int d=c+1;d<26;d++)
            {
                for(int e=d+1;e<26;e++)
                {
                    string s="";
                    s.push_back(a+'a');
                    s.push_back(b+'a');
                    s.push_back(c+'a');
                    s.push_back(d+'a');
                    s.push_back(e+'a');
                    m[s]=cont;
					cont++;
                }
            }
        }
    }	
	string aux;
	while(cin>>aux)
	{
		cout<<m[aux]<<endl;
	}	
	return 0;
}
