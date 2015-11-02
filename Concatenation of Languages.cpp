#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int casos, g1, g2;
	string str;

	scanf("%d", &casos);
	for(int v=1; v<=casos; v++)
	{
		vector<string> vec1, vec2;
		set<string> mySet;
		scanf("%d %d", &g1, &g2);
		getline(cin,str);

		for(int x=1; x<=g1; x++)
		{
		    getline(cin,str);
		    vec1.push_back(str);
		}
		for(int x=1; x<=g2; x++)
		{
		    getline(cin,str);
		    vec2.push_back(str);
		}

		string tmp;
		for(int x=0; x<vec1.size(); x++)
		    for(int y=0; y<vec2.size(); y++)
		    {
		        tmp = vec1[x] + vec2[y];
		        mySet.insert(tmp);
		    }
		printf("Case %d: %d\n", v,(int) mySet.size());
	}
	return 0;
}

