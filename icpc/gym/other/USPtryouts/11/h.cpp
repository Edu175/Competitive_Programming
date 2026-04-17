#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv cant(m);
	fore(i,0,m)cin>>cant[i];
	vv s(n),po(n);
	vector<vv> to(n);
	priority_queue<array<ll,3>> pq; // {s,-po,-i}
	auto put=[&](ll i){
		if(po[i]<SZ(to[i]))pq.push({s[i],-po[i],-i});
	};
	fore(i,0,n){
		cin>>s[i];
		ll k; cin>>k;
		to[i].resize(k);
		fore(j,0,k)cin>>to[i][j],to[i][j]--;
		put(i);
	}
	vv ans(n,-2);
	while(SZ(pq)){
		auto [asd,asdf,i]=pq.top(); pq.pop();
		i=-i;
		ll w=to[i][po[i]];
		if(cant[w]==0){
			po[i]++;
			put(i);
			continue;
		}
		ans[i]=w;
		cant[w]--;
	}
	for(auto i:ans)cout<<i+1<<"\n";
	return 0;
}
