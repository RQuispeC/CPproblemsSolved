#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n;
	map<int , int> m;
	vector<int> ele;
	ele.clear();
	while(cin>>n)
	{
		if(m[n]==0) ele.push_back(n);
		m[n]++;
	}	
	for(int i=0;i<ele.size();i++)
		cout<<ele[i]<<" "<<m[ele[i]]<<endl;
	return 0;
}
/*map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
		cout<<(*it).first<<" "<<(*it).second<<endl;	
	*/
	//este codigo me mostraria los elementos ordenados 
	
