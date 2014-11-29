//in a grid of 1,0s of size (n*m) find minimum lenght path to reach (0,0) from (n,m)
#include<iostream>
//#include<map>
//#include<vector>
#include<limits.h>
#include<queue>

int grid[110][110];
bool visited[110][110];
int minlist[110][110];
int c[]={-1,0,1};

using namespace std;

int main()
{  int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
    { for(int j=1;j<=m;j++)
     {cin>>grid[i][j];}
    }

    for(int i=0;i<=n+1;i++)
    for(int j=0;j<=m+1;j++)
    minlist[i][j]=INT_MAX;

    queue<pair<pair<int,int>,int> > q;
    //queue<pair<pair<int,int> ,int> > q;
    //int d=0;

    if(grid[1][1]==1) {visited[1][1]=1;
                        minlist[1][1]=0;
                        q.push(make_pair(make_pair(1,1),0));
                      }

    while(!q.empty())
    { int x=q.front().first.first;
      int y=q.front().first.second;
      int d=q.front().second;



      if(!visited[x][y]) {visited[x][y]=1;
                           minlist[x][y]=d;
                           q.push(make_pair(make_pair(x,y),d));
                           }

       q.pop();

       for(int i=0;i<3;i++)
       {
        for(int j=0;j<3;j++)
       {
               if(minlist[x][y]+1<minlist[x+c[i]][y+c[j]]&& grid[x+c[i]][y+c[j]])
               { minlist[x+c[i]][y+c[j]]=d+1;
                 q.push(make_pair(make_pair(x+c[i],y+c[j]),d+1));}
        }
        }
        // can move left, right, diagnol

    }
    if(visited[n][m]) cout<<minlist[n][m];
        else cout<<-1;


    }
