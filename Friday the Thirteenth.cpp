/*
ID: your_id_here
PROG: friday
LANG: C++ 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int lun, mar, mie, jue, vie, sab,  dom, n;
bool leap( int anio)	
{
	if( (anio%4==0 && anio%100 !=0) || anio%400==0)
		return true;
	return false;	
}
void day( int acuDay)
{
	int aux=acuDay%7;
	if(aux==0) dom++;
	else if(aux==1) lun++;
	else if(aux==2) mar++;
	else if(aux==3) mie++;
	else if(aux==4) jue++;
	else if(aux==5) vie++;
	else sab++;	
}
int daysMonth( int month , int anio)
{
	if(month==0) return 0;
	if(month==2)
		if(leap(anio)) return 29;
		else return 28;
	else
	{
		if(month==1 || month==3  || month==5  || month==7  || month==8  || month==10  || month==12  )
			return 31;
		else
			return 30;	
	}	
}
void run()
{
	lun=0, mar=0, mie=0, jue=0, vie=0, sab=0, dom=0;
	int acu=0;
	n+=1900;
	for(int anio=1900;anio<n;anio++)
	{
		for(int mes=0;mes<=11;mes++)
		{
			acu+=daysMonth(mes, anio);
			//cout<<acu+13<<endl;
			day(acu+13);
		}
		acu+=daysMonth(12, anio);
	}	
}
int main() {
    ofstream fcout ("friday.out");
    ifstream fcin ("friday.in");
	fcin>>n;
	run();	
	fcout<<sab<<" "<<dom<<" "<<lun<<" "<<mar<<" "<<mie<<" "<<jue<<" "<<vie<<endl;
	return 0;
}
