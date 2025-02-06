#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vv g[MAXN];
ll n;
vv bfs(ll s){
	vv d(n,-1);
	d[s]=0;
	queue<ll>q; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){
	JET
	cin>>n;
	fore(i,0,n){
		ll k; cin>>k;
		fore(_,0,k){
			ll x; cin>>x;
			g[i].pb(x);
		}
	}
	auto d=bfs(0);
	ll mx=max_element(ALL(d))-d.begin();
	d=bfs(mx);
	ll res=*max_element(ALL(d));
	// cout<<res<<"\n";
	cout<<(res+1)/2<<"\n";;
	return 0;
}