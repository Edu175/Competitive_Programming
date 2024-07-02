#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

ll uf[MAXN];
ll val[MAXN];

ii uf_find(ll x){
	if(uf[x]<0)return {x,val[x]};
	ii r=uf_find(uf[x]);
	uf[x]=r.fst,val[x]=min(val[x],r.snd);
	return {uf[x],val[x]};
}

int main(){JET
	mset(uf,-1);
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>val[i];
	fore(_,0,q){
		char c; cin>>c;
		if(c=='?'){
			ll x; cin>>x; x--;
			cout<<uf_find(x).snd<<"\n";
		}
		else {
			ll x,y; cin>>x>>y; x--,y--;
			uf[y]=x;
		}
	}
	return 0;
}