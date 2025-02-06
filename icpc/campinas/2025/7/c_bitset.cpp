#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+100;
bitset<MAXN> inv;
vv h[MAXN];
ll d[MAXN];
ll rta[MAXN];
bitset<MAXN> dfs(ll i){
	bitset<MAXN> b;
	for(auto j:h[i]){
		b|=dfs(j);
	}
	b[d[i]]=1;
	rta[i]=(b^inv)._Find_first()+1;
	return b;
}
int main(){
	JET
	fore(i,0,MAXN)inv[i]=1;
	ll n; cin>>n;
	ll papa; cin>>papa;
	fore(i,1,n) {
		ll f; cin>>f; f--;h[f].pb(i);
	}
	fore(i,0,n){
		ll dia; cin>>dia; d[i]=dia-1;
	}
	dfs(0);
	fore(i,0,n)cout<<rta[i]<<" ";
	cout<<"\n";
	return 0;
}