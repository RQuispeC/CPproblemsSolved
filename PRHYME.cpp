#include<bits/stdc++.h>
#define INF "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
using namespace std;
typedef vector < char > vc;
typedef pair < int , string > pis;
string s;
class Trie
{
	public:
	bool word;
	vc v;
	Trie* edges[26];
	string best;
	Trie();
	void addWord(string w, string ori);
	string query(string w);
};
Trie::Trie()
{
	word=0, v.clear();
	best=INF;
	for(int i=0;i<26;i++)
		edges[i]=NULL;
}
 void Trie::addWord(string w, string ori)
{
	best=min(best, ori);
	if(w.size()==0) 
		word=1;
	else
	{
		char k=w[0];
		if(edges[k-'a']==NULL)
		{
			edges[k-'a']=new Trie();
			v.push_back(k);
		}
		edges[k-'a']->addWord(w.substr(1), ori);
	}
	//cout<<w<<" : "<<ori<<" --> "<<best<<endl;
}
string Trie::query(string w)
{
	if(v.size()==0 && word && w.size()==0) 	
	{
		//cout<<w<<"  invalid"<<endl;
		return "*";//invalid path
	}	
	string ans="-";
	if(w.size()>0)
	{
		char k=w[0];
		if(edges[k-'a']!=NULL)
			ans = edges[k-'a']->query(w.substr(1));
	}
	else
	{
		ans=INF;
		for(int i=0;i<v.size();i++)
			ans=min(ans, edges[v[i]-'a']->best);
		//cout<<w<<" : "<<ans<<endl;	
		return ans;			
	}
	if(ans=="-")//no way to grow the match
	{
		//cout<<w<<" : "<<best<<endl;
		return best;
	}	
	if(ans=="*")//next node generate a bad path
	{
		ans=INF;
		if(best != edges[w[0]-'a']->best)
		{
			//cout<<"muajaj"<<endl;
			ans=best;
		}	
		for(int i=0;i<v.size();i++)
			if(v[i]!=w[0])
				ans=min(ans, edges[v[i]-'a']->best);
		if(ans==INF)
		{
			//cout<<w<<" : *"<<endl;
			return "*";
		}
		//cout<<w<<" : "<<ans<<endl;	
		return ans;	
	}
	//cout<<w<<" : "<<ans<<endl;	
	return ans;			
		
}

int main()
{
	Trie* root = new Trie();
	while(getline(cin, s))
	{
		if(s.size()==0) break;
		string m=s;
		reverse(m.begin(), m.end());
		root->addWord(m , s);
	}
	while(getline(cin, s))
	{
		reverse(s.begin(), s.end());
		string ans=root->query(s);
		//cout<<s<<" : "<<ans.first<<"  ";
		cout<<ans<<endl;
	}
}
/*
int main()
{
	char x[35];
	Trie* root = new Trie();
	while(gets(x) && x[0])
	{
		//printf("--%s\n", x);
		s=string(x);
		//if(s.size()==0) break;
		string m=s;
		reverse(m.begin(), m.end());
		root->addWord(m , s);
	}
	while(gets(x) )
	{
		s=string(x);
		reverse(s.begin(), s.end());
		string ans=root->query(s);
		if(ans=="*") ans=string(x);
		//cout<<s<<" : "<<ans.first<<"  ";
		printf("%s\n",ans.c_str());
	}
}

*/

