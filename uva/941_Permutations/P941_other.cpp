#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back
#define mp         make_pair
#define ALL(C)     (C).begin(),(C).end()

typedef long long ll;

void convert(int *num,vector<int> &tmp){
  rep(i,26)if(num[i])tmp.pb(num[i]);
  sort(ALL(tmp));
}

ll dp(int now,int *num,map<vector<int>,ll> &M){
  if (now == 0)return 1;
  vector<int> tmp;
  convert(num,tmp);
  if (M.find(tmp) != M.end())return M[tmp];

  ll ret=0;
  rep(i,26){
    if(num[i]){
      num[i]--;
      ret+=dp(now-1,num,M);
      num[i]++;
    }
  }
  return M[tmp]=ret;
}


string solve(ll n,string &in,int *num,map<vector<int>,ll> &M){
  string ret;
  vector<int> a;
  M[a]=1;
  rep(i,in.size()){
    rep(j,26){
      if (num[j] == 0)continue;
      num[j]--;
      vector<int> tmp;
      convert(num,tmp);
      ll val=M[tmp];
      if (n > val){
	n-=M[tmp];
      }else {
	ret+=(char)('a'+j);
	break;
      }
      num[j]++;
    }
  }
  return ret;
}

main(){
  int te;
  cin>>te;
  map<vector<int>,ll> M;
  while(te--){
    ll n;string in;
    cin>>in>>n;
    n++;
    int num[26]={0};
    rep(i,in.size())num[in[i]-'a']++;
    dp(in.size(),num,M);
    cout << solve(n,in,num,M) << endl;

  }
  return false;
}
