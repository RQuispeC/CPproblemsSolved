#include <iostream>
using namespace std;
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		int bot,uno, cinco, diez;
		cin>>bot>>uno>>cinco>>diez;
		int ans=0;
		int aux=bot*8;
		if(diez*10>=aux)
		{
			ans+=aux/10;
			aux%=10;
			if(aux>0)
			{
				ans++;
				aux=0;
			}
		}
		else
		{
			if(diez>=1)
			{
				ans+=diez;
				int pued=(diez*10)/8;
				int vuelto=(diez*10)%8;
				bot-=pued;
				aux=bot*8;
				cinco+=vuelto/5;
				uno+=vuelto%5;
			}
		}
		cout<<diez<<"  "<<cinco<<"   "<<uno<<endl;
		if(aux>0)
		{
			if(cinco*5>=aux)
			{
				ans+=(aux/5);
				aux%=5;
				if(aux>0)
				{
					ans++;
					aux=0;
				}
			}
			else
			{
				if(cinco>=2)
				{
					ans+=cinco;
					int pued=(cinco*5)/8;
					int vuelto=(cinco*5)%8;
					bot-=pued;
					aux=bot*8;
					uno+=vuelto;
				}
				else
				{
					if(cinco==1 && uno>=3)
					{
						ans+=4;
						cinco--;
						uno-=3;
						bot--;
						aux-=8;
					}
				}
			}
			if(aux>0)
			{
				ans+=aux;
			}
		}
		cout<<ans<<endl;
	}
}
/*while(bot>0)
		{
			if(diez*10>=bot*8)
			{
				int aux=bot*8;
				ans+=(aux/10);
				aux=aux%10;
				if(aux>0)
					ans++;
				bot=0;
			}
			else
			{
				if(diez>=1)
				{
					ans++;
					diez--;
					uno+=2;
					bot--;
					//cout<<"entras a10 : "<<ans<<endl;
				}
				else
				{
					if(cinco*5>=bot*8)
					{
						int aux=bot*8;
						ans+=aux/5;
						aux=aux%5;
						if(aux>0)
							ans++;
						//cout<<ans<<endl;
						bot=0;
					}
					else
					{
						if(cinco>=2)
						{
							bot--;
							cinco-=2;
							uno+=2;
							ans+=2;
						}
						else
						{
							if(cinco>=1 && uno>=3)
							{
								ans+=4;
								cinco--;
								uno-=3;
								bot--;
							}
							else
							{
								if( uno>=8)
								{
									ans+=8;
									uno-=8;
									bot--;
								}
								else
								{
									cout<<"incu"<<endl;
								}
							}
						}
					}
				}
			}
		}*/

