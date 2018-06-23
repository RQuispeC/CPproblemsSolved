/*
PAPICHA, el que codea ricucha
*/

#include<bits/stdc++.h> //g++ -std=c++11
using namespace std;

//#define DEBUG
#ifndef DEBUG
  #define din if(0) cin
  #define dout if(0) cout
#else
  #define din cin
  #define dout cout
#endif


#define inf (1 << 30)
#define pi (2*asin(1))
#define repall(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define rep(i,x,y) for (int i = x; i < y; i++)
#define irep(i,x,y) for (int i = x; i >= y; i--)
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mp make_pair
#define MAX 300005

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long int i64;
typedef vector < i64 > vi64;
map < int, int > frec;
int preprocess(string x){
	int cnt = 0,  unmatched = 0, ans = 0;
	vector< char > s;
	rep(i, 0, x.size()){
		if(x[i] == '(') s.push_back(x[i]);
		else{
			if(s.size() && s[s.size() - 1] == '(') s.pop_back();
			else s.push_back(x[i]);
		}
	}
	rep(i, 0, s.size()){	
		if(cnt < 0 && s[i] == '(') {
			unmatched++;
			ans = cnt;
			cnt = 0;
		}
		if(s[i] == '(') cnt++;
		else cnt--;
	}
	if(cnt!=0){
		unmatched++;
		ans = cnt;
	}
	return unmatched <=1?ans:inf;
}
int main()
{
	int n;
	frec.clear();
	scanf("%d", &n);
	rep(i, 0, n){
		string x;
		cin >> x;
		int val = preprocess(x);
		dout << x << " : " << val << endl;
		frec[val]++;
	}
	i64 ans = 0;
	repall(it, frec){
		int val = it -> first;
		int cnt = it -> second;
		if(val == inf || val < 0) continue;
		if(val == 0){
			ans += cnt + ((cnt - 1ll) * cnt);
		}
		else{
			if(frec.count(-val)){
				ans += 1ll * cnt * frec[-val];
			}
		}
	}
	cout << ans << endl;
}

