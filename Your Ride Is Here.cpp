/*
ID: your_id_here
PROG: ride
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string  a, b;
	fin>>a>>b;
	int acu1=1, acu2=1;
	for(int i=0;i<a.size();i++)
	{
		acu1*=(a[i]-'A'+1);
	}
	for(int i=0;i<b.size();i++)
	{
		acu2*=(b[i]-'A'+1);
	}
	if(acu1%47 == acu2%47)
	{
		fout<<"GO"<<endl;
	}
	else
	{
		fout<<"STAY"<<endl;
    }
	return 0;
}
