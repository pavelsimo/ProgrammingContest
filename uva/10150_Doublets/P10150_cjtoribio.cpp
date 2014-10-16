#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
 
struct STR
{
        string w;int id;
        STR(string a="",int _id=0):w(a),id(_id){}
        bool operator<(const STR& S)const
        {return w < S.w;}
};
 
struct STATE
{
        int u,d;
        STATE(int _u,int _d):u(_u),d(_d){}
};
 
vector<STR> vec[17];
vector<vector<int> >adj[17];
 
 
//=============================================================================\
                                                                Creates adjList
//==============================================================================
//==============================================================================
void unite()//overall complexity O(NS + NSlgN + LNS)
{
        for(int i = 0; i < 17 ; ++i)
        {
                if(vec[i].size()<=1)continue;
                vector<STR> temp((int)vec[i].size());
                for(int j = 0; j < vec[i].size();++j)
                        temp[j] = vec[i][j];
 
                for(int k = 0; k < i; ++k)
                {
                        for(int l = 0; l < temp.size();++l)
                                rotate(temp[l].w.begin(),temp[l].w.begin()+1,temp[l].w.end());
                        sort(temp.begin(),temp.end());
                        
                        for(int l = 0, m = 1; l < temp.size(); l = m)
                        {
                                string s = temp[l].w.substr(0,i-1);
                                for(m = l+1 ; m < temp.size() && s == temp[m].w.substr(0,i-1); ++m);
                                for(int n = l; n < m ; ++n)
                                for(int o = n+1; o < m; ++o)
                                {
                                        adj[i][temp[n].id].push_back(temp[o].id);
                                        adj[i][temp[o].id].push_back(temp[n].id);
                                }                               
                        }
                }
        }
}
//==============================================================================
//==============================================================================
//==============================================================================
 
 
 
 
//===================================\
                FIND the string's id
//===================================
int find(string s)
{
        int L = s.size();
        int lo = 0, hi = vec[L].size()-1;
        while(lo<hi)
        {
                int mid = (lo+hi)/2;
                if(vec[L][mid] < s)lo = mid+1;
                else hi = mid;
        }
        return lo;
}
//=====================================
//=====================================
 
 
 
 
//================================================================\
                                                BFS --> using, adj      
//================================================================\
                                Simple BFS no need for explanation
//================================================================
int prev[100000];//be careful is global for any size.. it's just a global temp
int bfs(string st,string en)
{
        if(st.size()!=en.size())return -1;
        int L = st.size();
        int start = find(st);//find starting index
        int end = find(en);//find ending index
        if(st!=vec[L][start].w || en!= vec[L][end].w)return -1;
        queue<STATE> q;
        int visit[vec[L].size()];
        memset(visit,false,sizeof(visit));
        memset(prev,-1,sizeof(prev));
        for(int i = 0; i < adj[L][start].size();++i)
        {
                prev[adj[L][start][i]] = start;
                q.push(STATE(adj[L][start][i],1));
        }
        while(!q.empty())
        {
                STATE c = q.front();
                q.pop();
                if(c.u == end)return c.d;
                if(visit[c.u])continue;
                visit[c.u]=true;
                for(int i = 0; i < adj[L][c.u].size();++i)
                {
                        if(!visit[adj[L][c.u][i]] && prev[adj[L][c.u][i]]==-1)
                        {
                                prev[adj[L][c.u][i]] = c.u;
                                q.push(STATE(adj[L][c.u][i],c.d+1));
                        }
                }
        }
        return -1;
}
//================================================================
//================================================================
//================================================================
 
int main()
{
        while(true)
        {
                string t;
                getline(cin,t);
                if(t=="")break;
                vec[t.size()].push_back(STR(t,0));
        }
        for(int i = 0; i < 17;++i)
                sort(vec[i].begin(),vec[i].end());
        for(int i = 0; i < 17;++i)
        {
                adj[i] = vector<vector<int> >((int)vec[i].size());
                for(int j = 0; j < vec[i].size();++j)
                {
                        vec[i][j].id = j;
                }
        }
        
        unite();
        int t = 0;
        char linq[50];
        string a,b;
        while(cin>>a>>b)
        {
                if((t++) != 0)
                        printf("\n");
                int an = bfs(a,b);
                vector<string> ans;
                if(an>=0)
                {
                        int ac = find(b);
                        int idx = 0;
                        if(a!=b)
                        {
                                while(ac!=find(a))
                                {
                                        ans.push_back(vec[a.size()][ac].w);
                                        ac = prev[ac];
                                }
                                printf("%s\n",a.c_str());
                                for(int i = ans.size()-1;i>=0;--i)
                                        printf("%s\n",ans[i].c_str());
                        }else
                        {
                                printf("%s\n",a.c_str());
                                printf("%s\n",(vec[a.size()][prev[find(a)]].w).c_str());
                                printf("%s\n",a.c_str());
                        }
                }else
                        printf("No solution.\n");
        }
        return 0;
}