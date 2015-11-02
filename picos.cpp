#include <iostream>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#define MAX 100005
#define LOGMAX 1000
using namespace std;
int M[MAX][LOGMAX];
int a[100005];
int N;
void process2()
  {
      int i, j;
     // cout<<N<<endl;
  //initialize M for the intervals with length 1
      for (i = 0; i < N; i++)
          M[i][0] = i;
  //compute values from smaller to bigger intervals
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
  }  
int hallarLog(int k){
	int ans=2;
	for(int i=0; i<1000; i++){
		if(k<=ans) return i;
		ans=ans*2;
	}
}
int RMQ(int i, int j){
	//cout<<"aqui"<<endl;
	int k=hallarLog(j-i+1);
	if(a[M[i][k]]<=a[M[j-(1<<k)+1][k]])
		return M[i][k];
	else{
		return M[j-(1<<k)+1][k];
	}
	//cout<<"aqui2"<<endl;
}
int main(){
	int n;
	vector<int> picos;
	while(cin>>n){
			N=n;
		picos.clear();
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		for(int i=1; i<n-1; i++)
			if(a[i]>a[i-1] && a[i]>a[i+1])
				picos.push_back(i);
	process2();
	int picosDer[MAX];
	int picosIzq[MAX];
	picosIzq[0]=picos[0];
	for(int i=1; i<picos.size(); i++){
		int j=i-1;
		while( j >=0 && a[picos[i]] >= a[picosIzq[j]]){
			j--;
		}
		if(j<0)
			picosIzq[i]=picos[i];
		else	
			picosIzq[i]=picosIzq[j];
	}
	picosDer[picos.size()-1]=picos[picos.size()-1];
	for(int i=picos.size()-2; i>=0 ; i--){
		int j=i+1;
		while( j<picos.size() && a[picos[i]] >= a[picosDer[j]]){
			j++;
		}
		if(j==picos.size())
			picosDer[i]=picos[i];
		else	
			picosDer[i]=picosDer[j];
	}
	/*for(int i=0;i<picos.size();i++)
	{
		cout<<picos[i]<<" : "<<picosDer[i]<<" -- "<<picosIzq[i]<<endl;
	}*/
	vector < int >  ans;
	for(int i=0; i<picos.size(); i++)
	{
		int prominence;
		if(picosDer[i]==picosIzq[i] &&  picosDer[i]==picos[i]) prominence = a[picos[i]];
		else 
		{	
			//cout<<"en1"<<endl;
			prominence = max(a[RMQ(picosIzq[i],picos[i])] , a[RMQ(picos[i],picosDer[i])]);
			prominence = a[picos[i]] - prominence;
		}	
		//cout<<a[RMQ(picosIzq[i],picos[i])] <<" - "<< a[RMQ(picos[i],picosDer[i])]<<endl;
		//cout<<prominence<<endl;
		if(prominence >= 150000)
			ans.push_back(picos[i]+1);
			//cout<<picos[i]+1<<endl;
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size())
			cout<<" ";
	}
	cout<<endl;
}
	return 0;
}
