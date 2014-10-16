 
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
#define FALSE false
#define TRUE true
 
 
vector< vector<int> >edges(10000, vector<int>(1000,0));
map<string,int>edge_map;
map<int,string>ulta_map;
class graph
{
public:
      vector<int> degree;
      int nvertices;
      int nedges;
      vector<bool>processed;
      vector<bool>discovered;
      vector<int>parent;
      vector<int>numbers;
      vector<string>path;
      graph()
      {
            edge_map.clear();
            nvertices=1;
            degree.resize(10000,0);
            nedges=0;
            processed.resize(10000,false);
            discovered.resize(10000,false);
            parent.resize(10000,-1);
            numbers.resize(10000,0);
            nedges=0;
      }
      // BFS FUNTIONS
      void process_vertex(int v)
      {
//          cout<<endl;
//          cout<<"processed vertex "<<ulta_map[v]<<endl;
      }
 
      void process_edge(int x,int y)
      {
//          cout<<"processed edge "<<ulta_map[x]<<" "<<ulta_map[y]<<endl;
      }
 
      void bfs(int start)
      {
          queue<int>q;
          int v;
          int i;
          q.push(start);
          discovered[start]=TRUE;
          while(!q.empty())
          {
              v=q.front();
              q.pop();
              process_vertex(v);
              processed[v]=true;
              for(i=0;i<degree[v];i++)
              {
                  if(true) //valid_edge(edges[v][i]==TRUE)
                  {
                      if(discovered[edges[v][i]]==FALSE)
                      {
                          q.push(edges[v][i]);
                          discovered[edges[v][i]]=true;
                          parent[edges[v][i]]=v;
                      }
                      if(processed[edges[v][i]]==false)
                          process_edge(v,edges[v][i]);
                  }
              }
          }
    }
     //BFS FUNCTIONS END
      void insert_edge(string x,string y,bool directed)
      {
            if(!edge_map[x])
            {
                  ulta_map[nvertices]=x;
                  edge_map[x]=nvertices++;
            }
            if(!edge_map[y])
            {
                  ulta_map[nvertices]=y;
                  edge_map[y]=nvertices++;
            }
 
            if(nvertices>=edges.capacity())
            {
                edges.resize(edges.size()+100, vector <int>(edges.size()+1,0));
 
            }
 
            if(degree[edge_map[x]]+1>=(edges.at(edge_map[x])).capacity())
                  (edges.at(edge_map[x])).resize((edges.at(edge_map[x])).size()+10,0);
 
            if(degree[edge_map[y]]+1>=(edges.at(edge_map[y])).capacity())
                  (edges.at(edge_map[y])).resize((edges.at(edge_map[y])).size()+10,0);
 
            edges[edge_map[x]][degree[edge_map[x]]]=edge_map[y];
            degree[edge_map[x]]++;
            if(directed==false)
                  insert_edge(y,x,true);
            else
                  nedges++;
      }
 
      void read_graph(bool directed,int howmany)
      {
            string x,y;
            int kotobar=howmany;
            while(kotobar--)
            {
                  cin>>x>>y;
                  insert_edge(x,y,directed);
            }
      }
      void print_graph()
      {
            int i,j;
            cout<<"total vertices:"<<nvertices-1<<endl;
            for(i=1;i<nvertices;i++)
            {
                  cout<<i<<" stands for "<<ulta_map[i]<<endl;
            }
            for(i=1;i<nvertices;i++)
            {
                  cout<<i<<" : ";
 
                  for(j=0;j<degree[i];j++)
                  {
                        cout<<edges[i][j]<<" ";
                  }
                  cout<<endl;
            }
      }
 
      void find_path(int start,int end)
      {
          if((start==end)|| (end==-1))
          {
              path.push_back(ulta_map[start]);
          }
          else
          {
              find_path(start,parent[end]);
              path.push_back(ulta_map[end]);
          }
      }
};
 
int main()
{
      int howmany,first=0;
      while(cin>>howmany)
      {
            graph g;
            g.read_graph(false,howmany);
//            g.print_graph();
            g.bfs(1);
            string x,y;
            cin>>x>>y;
            g.find_path(edge_map[x],edge_map[y]);
 
            if(x==y)continue;
 
            if(first)cout<<endl;
            else first=first+1;
 
            if(g.path.size()<3)
            {
                bool flag=0;
                for(int i=0;i<g.degree[edge_map[x]];i++)
                {
                    if(edges[edge_map[x]][i]==edge_map[y])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)cout<<x<<" "<<y<<endl;   //JUST EITA THIK KORA LAGBE
                else cout<<"No route"<<endl;
            }
            else
                for(int i=0;i<g.path.size()-1;i++)
                    cout<<g.path[i]<<" "<<g.path[i+1]<<endl;
 
      }
      return 0;
}
 
