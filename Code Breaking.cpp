#include<bits/stdc++.h>
#define	INF 1<<30
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef pair < string , string > pss; 
typedef long long ll;
vector < vi > a[85], b[85];
map < char , int > indexx;
set < int > used;
string encrypt(string s, vi per)
{
	string ans="";
	for(int i=0;i<s.size();i++) ans+=" ";
	for(int i=0;i<s.size();i++)
		ans[per[i]]=s[i];
	return ans;	
}
string encryptAll(string s, vi per)
{
	string ans="";
	for(int i=0;i<s.size();i+=per.size())
	{
		string sub= s.substr(i, (int)per.size());
		ans+=encrypt(sub, per);
		cout<<i<<" ****** "<<s.size()<<endl;
	}
	return ans;
}
string desencrypt(string s, vi per)
{
	string ans="";
	for(int i=0;i<s.size();i++) ans+=" ";
	for(int i=0;i<s.size();i++)
		ans[i]=s[per[i]];
	return ans;	
}
string desencryptAll(string s, vi per)
{
	string ans="";
	for(int i=0;i<s.size();i+=per.size())
	{
		string sub= s.substr(i, (int)per.size());
		ans+=desencrypt(sub, per);
	}
	return ans;
}
void getAlf(string beg, string end, int ind)
{
	for(int i=0;i<beg.size();i++)
	{
		a[ind][indexx[beg[i]]].push_back(i);
		b[ind][indexx[end[i]]].push_back(i);
	}	
}
int cnt;
void getFirst(string beg, string end, int ind, vi &per)
{
	for(int i=0;i<beg.size();i++)
	{
		int ind1= indexx[beg[i]];
		if(a[ind][ind1].size() != b[ind][ind1].size())
		{
			per =vi();
			break;
		}
		if(a[ind][ind1].size()==1)
		{
			if(per[i]==-1)
			{
				cnt++;
				per[i] = b[ind][ind1][0];
				used.insert(b[ind][ind1][0]);
			}	
			else
			{
				if(per[i]!=b[ind][ind1][0])
				{
					per =vi();
					break;
				}
			}	
		}	
	}
}
vi getPer(string beg, string end, int k)
{
	used.clear();
	if(beg.size()%k!=0 ) return vi();
	for(int i=0;i<beg.size();i++) 
		a[i].assign(100, vi()), b[i].assign(100, vi());
	vector < pss > v;
	v.clear();
	for(int i=0;i<beg.size();i+=k)
	{
		string sub1=beg.substr(i, k);
		string sub2=end.substr(i, k);
		v.push_back(pss(sub1, sub2));
	}
	vi ans = vi(k, -1);
	cnt=0;
	//first
	for(int i=0;i<v.size();i++)
	{
		getAlf(v[i].first, v[i].second, i);
		getFirst(v[i].first, v[i].second, i, ans);
		if(ans.size()==0) return vi();
	}
	//second
	for(int i=0;i<k;i++)
		if(ans[i]==-1)
		{
			int ind1=indexx[v[0].first[i]];
			bool f=0;
			for(int it=0;it<b[0][ind1].size();it++)
			{
				if(used.find(b[0][ind1][it])==used.end())
				{
					bool ok=1;
					int val = b[0][ind1][it];
					for(int j=1;j<v.size();j++)
						if(v[j].first[i]!=v[j].second[val])
						{
							ok=0;
							break;
						}
					if(ok)
					{
						f=1;
						ans[i] = val;
						used.insert(val);
						break;
					}	
				}
			}	
			if(!f)	return vi();
		}
	return ans;	
}
vi sol(string beg, string end)
{
	vi ans=vi();
	for(int k=1;k<=beg.size();k++)
	{
		ans=getPer(beg, end, k);
		if(ans.size()!=0) break;
	}
	return ans;
}
int main()
{
	string pl1, en1, en2;
	while(getline(cin, pl1))
	{
		if(pl1=="#") break;
		indexx.clear();
		int k=1;
		for(int i=0;i<pl1.size();i++)
		{
			if(indexx[pl1[i]]==0) 
				indexx[pl1[i]] = k++;
			if(indexx[en1[i]]==0) 
				indexx[en1[i]] = k++;
		}
		getline(cin, en1);
		getline(cin, en2);
		
		vi per= sol(pl1, en1);
		
		if(per.size()==0)
			cout<<en2<<endl;
		else
		{
			while(en2.size()%per.size()!=0) en2+='?';
			cout<<desencryptAll(en2, per)<<endl;
		}	
	}
}

