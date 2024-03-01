#include "highway.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=9e4+5;
vector<ll> g[MAXN];

void find_pair(int N, std::vector<int> U, std::vector<int> V, int A, int B) {
  int M = U.size();
  ll n=N,m=M,a=A,b=B;
  fore(i,0,m){
  	g[U[i]].pb(V[i]);
  	g[V[i]].pb(U[i]);
  }
  
  answer(s,e);
}
