#include <bits/stdc++.h>

#define INF 1024

using namespace std;

int a[190][190];
int m,n;

int BFS(int i,int j)
{
	queue<int> q;
	q.push(i);
	q.push(j);

	//mark the current node as 0
	a[i][j]=0;

	while(!q.empty())
	{
		//get the first two co-ordinates (x,y)
		int x= q.front();
		q.pop();
		int y= q.front();
		q.pop();

		//check if it is possible to reach a neighbour in minimum steps
		
		int dist= a[x][y]+1;
		
		//left
		if(y-1>=0 && dist < a[x][y-1])
		{
			q.push(x);
			q.push(y-1);
			a[x][y-1]=dist;
		}
		//right
		if(y+1<n && dist < a[x][y+1])
		{
			q.push(x);
			q.push(y+1);
			a[x][y+1]= dist;
		}

		//up
		if(x-1>=0 && dist < a[x-1][y])
		{
			q.push(x-1);
			q.push(y);
			a[x-1][y]= dist;
		}

		//down
		if(x+1<m && dist < a[x+1][y])
		{
			q.push(x+1);
			q.push(y);
			a[x+1][y]= dist;
		}
	}
}

int main(void)
{
	int t;
	cin>>t;
	
	while(t--)
	{
		vector< pair<int,int> > vc;
		cin>>m>>n;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				char ch;
				cin>>ch;
				//if the current character is 1...
				if(ch=='1')
				{
					//mark the current distance as negative INFINITY
					a[i][j]= -INF;
					//add all the (i,j) into the vector.
					vc.push_back(make_pair(i,j));
				}
				else //current cell contains 0, hence mark this as INFINITY
					a[i][j]=INF;
				
			}

		//call BFS for each i,j in the vector vc
		for(int i=0;i<vc.size();i++)
			BFS(vc[i].first,vc[i].second);

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}