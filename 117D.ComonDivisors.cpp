#include<bits/stdc++.h>
#define X1 31
#define X2 37
#define MAX 1000005

using namespace std;
typedef unsigned long long ll;
//const ll MOD = (1<<63)-1;
int k;
string s, sr;
ll hs1[MAX], hsr1[MAX], hs2[MAX], hsr2[MAX];
ll pot1[MAX], pot2[MAX];
ll potencia[MAX];
map < string , ll > mapa;
void generarPot(){
	potencia[0]=1ll;
	for(int i=1; i<MAX; i++){
		potencia[i]=(potencia[i-1]*X1);
	}
}
void invertir()
{
	sr="";
	for(int i=s.size()-1;i>=0 ;i--)
		sr+=s[i];
}
void precalc()
{
	for(int i=0;i<s.size();i++)
	{
		if(i==0)
		{
			pot1[i]=pot2[i]=1ll;
			hs1[i]= ll(s[i]-'a');
			hs2[i]= ll(s[i]-'a');
		}	
		if(i>=1)
		{
			pot1[i]=pot1[i-1]*X1;
			pot2[i]=pot2[i-1]*X2;
			hs1[i]=hs1[i-1]*X1 + (s[i]-'a');
			hs2[i]=hs2[i-1]*X2 + (s[i]-'a');
		}	
	}
	for(int i=0;i<sr.size();i++)
	{
		if(i==0)
		{
			pot1[i]=pot2[i]=1ll;
			hsr1[i]= ll(sr[i]-'a');
			hsr2[i]= ll(sr[i]-'a');
		}	
		if(i>=1)
		{
			pot1[i]=pot1[i-1]*X1;
			pot2[i]=pot2[i-1]*X2;
			hsr1[i]=hsr1[i-1]*X1 + (sr[i]-'a');
			hsr2[i]=hsr2[i-1]*X2 + (sr[i]-'a');
		}	
	}
	
}
ll h1(int i, int j)
{
 	if(i==0)
 		return hs1[j];
 	return hs1[i]-hs1[j-1]*pot1[i-j+1];
 		
}
ll h2(int i, int j)
{
 	if(i==0)
 		return hs2[j];
 	return hs2[i]-hs2[j-1]*pot2[i-j+1];
 		
}
ll hr1(int i, int j)
{
	if(i==0)
 		return hsr1[j];
 	return hsr1[i]-hsr1[j-1]*pot1[i-j+1];
}
ll hr2(int i, int j)
{
	if(i==0)
 		return hsr2[j];
 	return hsr2[i]-hsr2[j-1]*pot2[i-j+1];
}
bool verificar(int l){
	ll hashing=h1(l-1,0);
	ll aux=0ll;
	int ind=0;
	for(int i=0; i<s.size()/l; i++){
		aux=aux+pot1[ind];
		ind=ind+l;
	}
	hashing=hashing*aux;
	if(h1(s.size()-1,0)==hashing)
		return true;
	return false;
}
bool verificar2(int l){
	ll hashing=hr1(l-1,0);
	ll aux=0ll;
	int ind=0;
	for(int i=0; i<sr.size()/l; i++){
		aux=aux+pot1[ind];
		ind=ind+l;
	}
	hashing=hashing*aux;
	if(hr1(sr.size()-1,0)==hashing)
		return true;
	return false;
}
int main()
{
	cin>>s>>sr;
	precalc();
	generarPot();
	vector<int> v,v2,v3;
	int l1=s.size(),l2=sr.size();	
	for(int i=1; i*i<=s.size(); i++){
		if(l1%i==0){
			if(i*i==l1)
				v.push_back(i);
			else{
				v.push_back(i);
				v.push_back(l1/i);
			}
		}
	}
	for(int i=1; i*i<=sr.size(); i++){
		if(l2%i==0){
			if(i*i==l2)
				v2.push_back(i);
			else{
				v2.push_back(i);
				v2.push_back(l2/i);
			}
		}
	}
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v2.size(); j++){
			if(v[i]==v2[j]){
				v3.push_back(v[i]);
				break;
			}		
		}
	}
	int cont=0;
	for(int i=0; i<v3.size(); i++){
		if(verificar(v3[i]) && verificar2(v3[i])){
			if(h1(v3[i]-1,0)==hr1(v3[i]-1,0) && h2(v3[i]-1,0)==hr2(v3[i]-1,0)){
				cont++;
			}
		}
	}
	cout<<cont<<endl;	
}

