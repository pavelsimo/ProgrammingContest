#include <cstdio>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class BipartiteMatchingAdjMatrix {
   vector<bool> seen;
   bool bpm(int u) {
      for (int v = 0; v < matchR.size(); v++) {
         if (!A[u][v] || seen[v]) continue;
         seen[v] = true;
         if (matchR[v] < 0 || bpm(matchR[v])) {
            matchL[u] = v;
            matchR[v] = u;
            return true;
         }
      }
      return false;
   }
public:
   // input: adjacency matrix
   vector< vector<bool> > A;

   // output: matching for left and right sets
   vector<int> matchL, matchR;

   BipartiteMatchingAdjMatrix(size_t _Lsz, size_t _Rsz)
      : A( _Lsz, vector<bool>(_Rsz) ) {}

   int process() {
      matchL.assign( A.size(), -1 ),
      matchR.assign( A.empty() ? 0 : A[0].size(), -1 );
      int cnt = 0;
      for (int i = 0; i < matchL.size(); ++i) {
         seen = vector<bool>(matchR.size(), false);
         if (bpm(i))
            cnt++;
      }
      return cnt;
   }
};


class BipartiteMatching {
   vector<bool> seen;
   bool bpm(int u) {
      for (int j = 0; j < adj[u].size(); ++j) {
         int v = adj[u][j];
         if (seen[v]) continue;
         seen[v] = true;
         if (matchR[v] < 0 || bpm(matchR[v])) {
            matchL[u] = v;
            matchR[v] = u;
            return true;
         }
      }
      return false;
   }
public:
   size_t nL, nR;
   vector< vector<int> > adj; // adjacency lists

   vector<int> matchL, matchR;
   BipartiteMatching(size_t _nL, size_t _nR) : nL(_nL), nR(_nR), adj(_nL) {}

   int process() {
      matchL.assign( nL, -1 ),
      matchR.assign( nR, -1 );
      int cnt = 0;
      for (int i = 0; i < nL; ++i) {
         seen = vector<bool>(nR, false);
         if (bpm(i))
            cnt++;
      }
      return cnt;
   }
};

// Capacity >= 1 for R
class BipartiteMatchingMCapR {
   vector<int> seen;
   bool bpm(int u) {
      for (int v = 0; v < matchR.size(); v++) {
         if (!A[u][v] || seen[v] >= capR[v]) continue;
         int j = seen[v];
         seen[v]++;
         if (j >= matchR[v].size()) {
            matchL[u] = v;
            matchR[v].push_back(u);
            return true;
         }
         else if (bpm(matchR[v][j])) {
            matchL[u] = v;
            matchR[v][j] = u;
            return true;
         }
      }
      return false;
   }
public:
   // input: adjacency matrix and capacity on right side
   vector< vector<bool> > A;
   vector< int > capR;

   // output
   vector<int> matchL;
   vector< vector<int> > matchR;
   BipartiteMatchingMCapR(size_t _nL, size_t _nR)
      : A( _nL, vector<bool>(_nR) ), capR(_nR, 1) {}

   int process() {
      matchL.assign( A.size(), -1 ),
      matchR.assign( capR.size(), vector<int>() );
      int cnt = 0;
      for (int i = 0; i < matchL.size(); ++i) {
         seen = vector<int>(capR.size(), 0);
         if (bpm(i))
            cnt++;
      }
      return cnt;
   }
};



/*
 * Hopcroft–Karp algorithm
 * G = G1 \cup G2 \cup NIL
 * where G1 and G2 are partition of graph and NIL is a special null vertex
*/

/*
 function BFS ()
     for u in G1
         if Pair[u] = NIL
             Dist[u] = 0
             Enqueue(Q,u)
         else
             Dist[u] = \infty
   
     while Empty(Q) == false
         u = Dequeue(Q)
         if u != NIL
             for each v in Adj[u]
                 if Dist[ Pair[v] ] == \infty
                     Dist[ Pair[v] ] = Dist[u] + 1
                     Enqueue(Q,Pair[v])
     return Dist[NIL] != \infty

 function DFS (u)
     if u != NIL
         for each v in Adj[u]
             if Dist[ Pair[v] ] == Dist[u] + 1
                 if DFS( Pair[v] )
                     Pair[v] = u
                     Pair[u] = v
                     return true
     else return true
     Dist[u] = \infty
     return false

 function Hopcroft-Karp
     for each u in G
         Pair[u] = NIL
     matching = 0
     while BFS() == true
         for each u in G1
             if Pair[u] == NIL
                 if DFS(u) == true
                     matching = matching + 1
     return matching
*/

class BipartiteMatchingHK {
   const int static INF = 98765432;
   size_t Lsz, Rsz;
   vector<int> dist;
   bool _bfs();
   bool _dfs(int v);
   vector< vector<int> > adj;
public:
   const int static NIL_VERTEX = 0;

   // output: warning: vertex indices start with 1, not 0
   vector<int> match;

   BipartiteMatchingHK(size_t _Lsz, size_t _Rsz)
      : Lsz(_Lsz), Rsz(_Rsz), adj(Lsz+1) {}

   void add_edge(int u, int v);

   int process();
};

inline void BipartiteMatchingHK::add_edge(int u, int v) {
   adj[u + 1].push_back(v + Lsz + 1);
}

int BipartiteMatchingHK::process() {
   match = vector<int>(Lsz+Rsz+1, +NIL_VERTEX);
   int nmatches = 0;
   dist = vector<int>(Lsz+1, +INF);
   while (_bfs()) {
      for (int u = 1; u <= Lsz; ++u)
         if (match[u] == NIL_VERTEX && _dfs(u))
            ++nmatches;
   }
   return nmatches;
}

bool BipartiteMatchingHK::_dfs(int u) {
   if (u == NIL_VERTEX)
      return true;
   for (int j = 0; j < adj[u].size(); ++j) {
      int v = adj[u][j];
      if ( dist[ match[v] ] == dist[u]+1 && _dfs( match[v] ) ) {
         match[v] = u;
         match[u] = v;
         return true;
      }
   }
   dist[u] = INF;
   return false;
}

bool BipartiteMatchingHK::_bfs() {
   queue<int> q;
   for (int u = 1; u <= Lsz; ++u) {
      if (match[u] == NIL_VERTEX) {
         dist[u] = 0;
         q.push(u);
      }
      else
         dist[u] = INF;
   }
   dist[NIL_VERTEX] = INF;
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == NIL_VERTEX) continue;
      for (int j = 0; j < adj[u].size(); ++j) {
         int v = adj[u][j];
         if (dist[ match[v] ] >= INF) {
            dist[ match[v] ] = dist[u] + 1;
            q.push(match[v]);
         }
      }
   }
   return dist[NIL_VERTEX] < INF;
}

/*
7 7 19
0 1
0 5
1 1
1 3
2 0
2 2
2 4
3 0
3 2
3 4
4 1
4 3
4 5
5 2
5 3
5 4
5 5
5 6
6 5
*/

int main() {
   char line[200];
   int Lsz, Rsz, M;   // size of LEFT set, size of RIGHT set, number of edges
   
   gets(line);
   sscanf(line, "%d %d %d", &Lsz, &Rsz, &M);
   BipartiteMatching bpm(Lsz, Rsz);
   BipartiteMatchingAdjMatrix bpmam(Lsz, Rsz);
   BipartiteMatchingMCapR bpmcr(Lsz, Rsz);
   BipartiteMatchingHK bpmhk(Lsz, Rsz);
   while (M-- > 0) {
      int u, v;
      gets(line);
      sscanf(line, "%d %d", &u, &v);
      bpm.adj[u].push_back(v);
      bpmam.A[u][v] = true;
      bpmcr.A[u][v] = true;
      bpmhk.add_edge(u, v);
   }

   printf("Adjacency List: %d\n", bpm.process() );
   puts("Left -> Right");
   for (int u = 0; u < Lsz; ++u)
      printf("%3d: %3d\n", u, bpm.matchL[u]);
   puts("Right -> Left");
   for (int v = 0; v < Rsz; ++v)
      printf("%3d: %3d\n", v, bpm.matchR[v]);
   putchar('\n');

   printf("Adjacency Matrix: %d\n", bpmam.process() );
   puts("Left -> Right");
   for (int u = 0; u < Lsz; ++u)
      printf("%3d: %3d\n", u, bpmam.matchL[u]);
   puts("Right -> Left");
   for (int v = 0; v < Rsz; ++v)
      printf("%3d: %3d\n", v, bpmam.matchR[v]);
   putchar('\n');

   printf("Adjacency Matrix + Capacity on Right set: %d\n", bpmcr.process() );
   puts("Left -> Right");
   for (int u = 0; u < Lsz; ++u)
      printf("%3d: %3d\n", u, bpmcr.matchL[u]);
   puts("Right -> Left");
   for (int v = 0; v < Rsz; ++v) {
      printf("%3d:", v);
      for (int j = 0; j < bpmcr.matchR[v].size(); ++j)
         printf(" %3d", bpmcr.matchR[v][j]);
      putchar('\n');
   }
   putchar('\n');

   printf("Hopcroft–Karp: %d\n", bpmhk.process() );
   puts("Left -> Right");
   for (int u = 0; u < Lsz; ++u)
      printf("%3d: %3d\n",
             u, bpmhk.match[u+1] == bpmhk.NIL_VERTEX ? -1 : bpmhk.match[u+1]-Lsz-1);
   puts("Right -> Left");
   for (int u = 0; u < Rsz; ++u)
      printf("%3d: %3d\n",
             u, bpmhk.match[u+1+Lsz] == bpmhk.NIL_VERTEX ? -1 : bpmhk.match[u+1+Lsz]-1);
   putchar('\n');

   return 0;
}
