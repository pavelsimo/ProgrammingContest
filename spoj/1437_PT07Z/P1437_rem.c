#include <stdio.h>
 
struct node {
	int v;
	struct node* next;
};
 
typedef struct node node;
 
#define maxn 10000
int n, maxD, x;
node* adj[maxn];
node nodes[maxn*2];
 
void dfs(int u, int par, int d) {
	if (d > maxD) {
		maxD = d;
		x = u;
	}
	for (node* p = adj[u]; p; p = p->next) {
		if (p->v != par)
			dfs(p->v, u, d+1);
	}
}
 
char buf[1<<18];
int pos;
 
int nextInt() {
	while (buf[pos] <= ' ') ++pos;
	int res = 0;
	while (buf[pos] > ' ') 
		res = res*10+(buf[pos++]&15);
	return res;
}
 
int main() {
	int p, u, v, z;
	//freopen("input.txt", "rt", stdin);
	fread(buf, 1, sizeof(buf), stdin);
	pos = 0;
	n = nextInt();
	p = 0;
	for (z = n-1; z; --z) {
		u = nextInt();
		v = nextInt();
		--u; --v;
		//adj[u].push_back(v);
		//adj[v].push_back(u);
		nodes[p].next = adj[u];
		nodes[p].v = v;
		adj[u] = &nodes[p++];
		nodes[p].next = adj[v];
		nodes[p].v = u;
		adj[v] = &nodes[p++];
		//++deg[u]; ++deg[v];
	}
	maxD = -1;
	dfs(0, -1, 0);
	maxD = -1;
	dfs(x, -1, 0);
	printf("%d\n", maxD);	
}
