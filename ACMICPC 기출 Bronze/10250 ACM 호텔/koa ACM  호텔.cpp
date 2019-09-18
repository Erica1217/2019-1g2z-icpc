#include <iostream>
#include <cstdio>
using namespace std;
int T,H,W,N,X,Y;
int main()
{
	cin>>T;
	for(int x=0; x<T; x++)
	{
		cin>>H>>W>>N;
		if(N%H!=0)
		{
			X=N/H+1;
		}
		else X=N/H;
		
		if(N%H==0) Y=H;
		else Y=N%H;
		printf("%d%02d\n",Y,X);
		
	}
}