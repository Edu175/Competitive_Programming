#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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
const ll maxn=2e6+10;
ll dg[maxn];
vv g[maxn];
vv ord;

void topo(ll n){
	ord.clear();
	priority_queue<int> pq;
	fore(v,0,n)if(!dg[v]) pq.push(-v);
	while(SZ(pq)){
		ll u=-pq.top(); pq.pop();
		for(auto v :g[u])
			if(!--dg[v]) pq.push(-v);
		ord.pb(u);
	}
	reverse(ALL(ord));
}
int main(){
	JET
	ll 	_; cin>>_; while(_--){
		ll n,m; cin>>n>>m;
		fore(i,0,n) g[i].clear();
		vv a[m]; 
		
		fore(i,0,n){
			ll p; cin>>p;
			fore(j,0,p){
				ll b; cin>>b; b--;
				a[b].pb(i);
			}
		}
		fore(i,0,m) if(SZ(a[i])) {
			ll x=a[i].back(); a[i].pop_back();
			while(SZ(a[i])){
				g[x].pb(a[i].back());
				dg[a[i].back()]++;
				a[i].pop_back();
			}
		}
		topo(n);
		ll t=0;
		fore(i,0,n) if(ord[i]!=i) t=1;
		if(!t){
			cout<<"No\n"; 
			continue;
		}
		cout<<"Yes\n";
		fore(i,0,n) cout<<ord[i]+1<<" ";;cout<<"\n";
		
		
	}
	return 0;
}