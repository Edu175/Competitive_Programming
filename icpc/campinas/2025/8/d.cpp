#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5,MAXM=1e5+5;
vector<ii> g[MAXN];
ll vised[MAXM],vis[MAXN],col[MAXN];

ll od=0;
ll cic(ll x){ // return: node of found cycle
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			ll to=cic(y);
			if(to!=-1){
				col[i]=od; od^=1;
				vised[i]=2;
				if(to!=x){
					vis[x]=0;
					return to;
				}
			}
		}
		else {
			col[i]=od=0; od^=1;
			vis[x]=0; vised[i]=2;
			return y;
		}
	}
	return -1;
}
void tree(ll x, ll w){ // w: col of arista padre
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		assert(!vis[y]); // because it's a tree, duh
		w^=1;
		col[i]=w;
		tree(y,w);
	}
}
ll cnt=0;
bool check(){
	fore(x,0,cnt){
		vv c(2);
		for(auto [y,i]:g[x]){
			c[col[i]]++;
		}
		if(abs(c[0]-c[1])>1)return 0;;
	}
	return 1;
}
int main(){
	JET
	map<ll,ll>xs,ys;
	ll n; cin>>n;
	// ll cnt=0;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		if(!xs.count(x))xs[x]=cnt++;
		if(!ys.count(y))ys[y]=cnt++;
		g[xs[x]].pb({ys[y],i});
		g[ys[y]].pb({xs[x],i});
		// cerr<<xs[x]<<" "<<ys[y]<<"\n";
	}
	fore(i,0,cnt)if(!vis[i])cic(i);
	// fore(i,0,n)cerr<<vised[i]<<" ";;cerr<<"\n";
	mset(vis,0);
	fore(i,0,n)if(vised[i]==1)vised[i]=0;
	fore(i,0,cnt)if(!vis[i])tree(i,0);
	// fore(x,0,cnt)for(auto [y,i]:g[x])cerr<<x<<" "<<y<<" "<<col[i]<<"\n";
	assert(check());
	fore(i,0,n)cout<<"LF"[col[i]];;cout<<"\n";
	return 0;
}