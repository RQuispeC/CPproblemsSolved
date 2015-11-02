#include<iostream>
using namespace std;
int main()
{
	int tested, n;
	cin>>tested;
	while(tested--)
	{
		cin>>n;
		string small, big, s[18];
		s[2] = "1";
		s[3] = "7";
		s[4] = "4";
		s[5] = "2";
		s[6] = "6";
		s[7] = "8";
		s[8] = "10";
		s[9] = "18";
		s[10] = "22";
		s[11] = "20";
		s[12] = "28";
		s[13] = "68";
		s[14] = "88";
		s[15] = "108";
		s[16] = "188";
		s[17] = "200";
		//determinar small
		small = "";
		int x = n;
		while (x > 17)
		{
		 	small += "8";
		 	x -= 7;
		}
		small = s[x] + small;
		//determinar big
		big = "";
		x = n;
		while (x > 3) 
		{
			big += "1";
			x -= 2;
		}	
		big = s[x] + big;
		cout<<small<<" "<<big<<endl;
	}
	
}

