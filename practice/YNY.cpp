    //maximum matching in a general graph
    #include <iostream>
    #include <cstdio>
    #include <map>
    #include <vector>
    using namespace std;

    int h[100][100];// shows connectivity of the graph in form of 1,0 Y,N
    int vis[100]; // a color array which will be used in intermediate process while assigning the augmented path
    int f[100]; // shows i is paired with which vertex f[1]=2 means 1 paired with 2 or handshaking with him
    int n;
    int dfs(int u)
    {
       if(!vis[u])  vis[u]=1;
       else return false;

       for(int i=0;i<n;i++)
        {
    		vis[i]=1;
		   if(h[u][i]&&(f[i]==-1||dfs(f[i])))
		    {
		       f[i]=u;
		       f[u]=i;
		    return true;

                   }
                vis[i]=0;
        }

     return false;
    }


    int main()
    {
       cin>>n;
       for(int i=0;i<n;i++)
         { for(int j=0;j<n;j++)
            {
	       char c;
	       cin>>c;
               if(c=='Y')
		    h[i][j]=1;
	       else
		    h[i][j]=0;
 	     }
          }

      memset(f, -1, sizeof(f));
      int ans=0;
      for(int i=0;i<n;i++)
       {
          memset(vis, 0, sizeof(vis));
          if((f[i]!=-1)||dfs(i))
          ans++;
       }

      cout<<ans<<endl;
    }
