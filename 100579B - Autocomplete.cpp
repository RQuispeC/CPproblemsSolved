#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int deph, te, lim;
char s[1000005];
class Trie
{
	public:
		Trie* edges[26];
		Trie();
		void addWord( int pos, int d);
};
Trie::Trie()
{
	for(int i=0;i<26;i++)
		edges[i]=NULL;
}
void Trie::addWord( int pos,  int d)
{
	if(pos==lim)
		return;
	else
	{
		char k= s[pos];
		if(edges[k - 'a']==NULL)
		{
			edges[k-'a']= new Trie;
			if(deph == -1)
				deph=d;
		}	
		edges[k-'a']->addWord(pos+1, d+1);
	}	
}
Trie* t;
int main()
{
	int test;
	scanf("%d", &test);
	for(te=1;te<=test;te++)
	{
		t=new Trie;
		int n;
		scanf("%d", &n);
		int ans=0;
		if(n==1) 
		{
			scanf("%s", s);
			printf("Case #%d: %d\n", te, 1);
			continue;
		}
		for(int i=0;i<n;i++)
		{
			line++;
			scanf("%s", s);
			lim=strlen(s);
			deph=-1;
			t->addWord( 0, 1);
			if(deph==-1)
				ans+=strlen(s);
			else 
				ans+=deph;	
		}
		printf("Case #%d: %d\n", te, ans);
	}
}

