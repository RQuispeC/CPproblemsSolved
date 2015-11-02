#include<bits/stdc++.h>
using namespace std;
class Trie
{
	public:
		int words, prefixes;
		Trie* edges[26];
		Trie();
		void addWord(string word);
		int countWords(string word);
		int countPrefixes(string prefix);
};
Trie::Trie()
{
	words=prefixes=0;
	for(int i=0;i<26;i++)
		edges[i]=NULL;
}
void Trie::addWord(string word)
{
	if(word.size()==0)
		words++;
	else
	{
		prefixes++;
		char k= word[0];
		if(edges[k - 'a']==NULL)
			edges[k-'a']= new Trie;
		edges[k-'a']->addWord(word.substr(1));
	}
}
int Trie::countWords(string word)
{
	if(word.size()==0)
		return words;
	else
	{
		char k= word[0];
		if(edges[k-'a']==NULL)
			return 0;
		return 	edges[k-'a']->countWords(word.substr(1));
	}	
}
int Trie::countPrefixes(string prefix)
{
	if(prefix.size()==0)
		return prefixes;
	else
	{
		char k= prefix[0];
		if(edges[k-'a']==NULL)
			return 0;
		return 	edges[k-'a']->countPrefixes(prefix.substr(1));
	}	
}
int main()
{
	Trie root;
}

