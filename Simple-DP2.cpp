#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
vector<int> T[MAX];
int DP[MAX][MAX];

inline int Route(int i, int j, int n){
	if(DP[i][j]!=-1) return DP[i][j];
	if(i == n) return T[i][j];
	return DP[i][j] = T[i][j]+max(Route(i+1, j, n), Route(i+1, j+1, n));
}
int solve(int iBeg, int jBeg, int nBeg)
{
	for(int j=0;j<=nBeg;j++) //get the initial values
		Route(nBeg, j, nBeg); //will always get into the second IF (if(i == n) return T[i][j];)
	for(int i=nBeg-1;i>=iBeg;i--)
		for(int j = 0; j<=nBeg;j++)
			Route(i,j,nBeg);
	return 	Route(iBeg, jBeg, nBeg);
}

int main() {
	int levels, aux, casE = 0;
	while(cin >> levels){
		memset(DP, -1, sizeof DP);
		for(int i=0; i<levels; i++)
			for(int j=0; j<=i; j++){
				cin >> aux;
				T[i].push_back(aux);
			}
		cout << "Caso " << ++casE << " = " << solve(0, 0, levels-1) << endl;
		for(int i=0; i<levels; i++) T[i].clear();
	}
	return 0;
}

/* INPUT
5
1
4 3
1 2 4
5 8 6 4
1 6 5 4 8
3
1
4 3
1 4 2
*/
