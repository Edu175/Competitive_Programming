#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
vector<ii> g[MAXN];
ll fa[MAXN];
void dfs(ll x){
	for(auto [y,w]:g[x])if(y!=fa[x])fa[y]=x,dfs(y);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ll n; cin>>n;
	fore(i,0,n){
		
	}
}