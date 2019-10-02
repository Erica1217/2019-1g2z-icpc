#include <iostream>
#include <queue>
#include <vector>
#define Mx 9999999
using namespace std;

struct st{
	int Node,Cost;
};

struct cmp
{
	bool operator()(st A, st B)
	{
		return A.Cost>B.Cost;	
	}
};

int N,M,S,a,b,c,check[22000],Min[22000];
priority_queue<st,vector<st>,cmp> que;
vector< vector<st> > E(22000);
st Z,Q;

int main()
{	
	cin>>N>>M>>S;
	for(int x=0; x<M; x++)
	{
		cin>>a>>b>>c;
		Z.Node=b;
		Z.Cost=c;
		E[a].push_back(Z);
		//Z.Node=a;
		//E[b].push_back(Z);
	}
	
	for(int x=1; x<=N; x++) Min[x]=Mx;
	
	Min[S]=0;
	check[S]=0;
	Z.Node=S;
	Z.Cost=0;
	que.push(Z);
	
	while(!que.empty())
	{
		Z=que.top();
		//cout<<Z.Node<<endl;
		check[Z.Node]=1;
		for(int x=0; x<E[Z.Node].size(); x++)
		{
			if(Min[E[Z.Node][x].Node]>Min[Z.Node]+E[Z.Node][x].Cost)
			{
				Min[E[Z.Node][x].Node]=Min[Z.Node]+E[Z.Node][x].Cost;
				Q.Node=	E[Z.Node][x].Node;
				Q.Cost=Min[Z.Node]+E[Z.Node][x].Cost;
				//cout<<Z.Node<<" "<<Q.Node<<" "<<Q.Cost<<endl;
				que.push(Q);
			}
		}
		que.pop();
	}
	
	for(int x=1; x<=N; x++)
	{
		if(Min[x]!=Mx) cout<<Min[x]<<"\n";
		else cout<<"INF\n";
	}
}