#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int ll;
int n, k, A[200005];
ll k2, memo[200005][3];

ll DoIt(int pos, int p){
	
	if(pos == n) return 0;
	//if(memo[pos][p] != -1) return memo[pos][p];
	//if(pos!=n){
	//else{
	int gg, b;
	gg = DoIt(pos+1, p);
	if(!p)
	{
		b = A[pos];
		gg += DoIt(pos+1, 1);
	}
	if(p == 1 && A[pos] == b*k) gg += DoIt(pos+1, 2);
	if(p == 2 && A[pos] == b*k2) gg++;
	//}
	return memo[pos][p] = gg;
}

int main() {
	while(scanf("%d%d", &n, &k) == 2){
		k2 = k*k;
		for(int i=0; i<n; i++){
			scanf("%d", &A[i]);
			for(int j=0; j<3; j++) memo[i][j] = -1;
		}
		memset(memo, -1, sizeof memo);
		printf("%lld\n", DoIt(0, 0));
	}
	return 0;
}
/*
INPUT:
5 2
1 1 2 2 4
3 1
1 1 1
10 3
1 2 6 2 3 6 9 18 3 9
*/
