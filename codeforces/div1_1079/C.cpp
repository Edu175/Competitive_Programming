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
const ll MAXN=35;

vv g[MAXN];
ll rt,n;

vv dp;
ll f(ll x){
	auto &res=dp[x];
	if(res!=-1)return res;
	res=1; // ends here
	for(auto y:g[x])res+=f(y);
	return res;
}
ll get_paths(ll x){
	dp=vv(n+1,-1);
	return f(x);
}

vv ask(ll k){
	if(k==0){return {rt,0};}
	cout<<"? "<<k+1<<endl;
	ll sz; cin>>sz;
	vv ret(1+sz);
	ret[0]=rt;
	fore(i,1,sz+1)cin>>ret[i],ret[i]--;
	return ret;
}

int main(){
	// FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		rt=n;
		fore(i,0,n+1)g[i].clear();
		vv p={rt};
		ll k=0; // k is index of next
		vv vis(n+1); vis[rt]=1;
		while(SZ(p)){
			auto q=ask(k);
			if(SZ(q)==1)break;
			ll lcp=min(SZ(p),SZ(q));
			fore(i,0,lcp)if(p[i]!=q[i]){lcp=i;break;}
			assert(SZ(q)>lcp);
			ll y=q[lcp];
			ll x=q[lcp-1];
			g[x].pb(y);
			p=q;
			if(!vis[y]){ // tree	
				vis[y]=1;
				k++;
			}
			else { // cross
				p.pop_back();
				k+=get_paths(y);
			}
		}
		vector<ii> ed;
		fore(x,0,n)for(auto y:g[x]){
			assert(y!=rt);
			ed.pb({x,y});
		}
		cout<<"! "<<SZ(ed)<<endl;
		for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<endl;
	}
	return 0;
}
