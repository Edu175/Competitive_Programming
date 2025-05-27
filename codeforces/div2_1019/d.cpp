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
const ll MAXN=2e5+5;

vv g[MAXN];
ll vis[MAXN];
vv ord;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}
void add(ll i, ll j, ll dir){ // 1: i<j
	if(dir)g[i].pb(j);
	else g[j].pb(i);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		vv a(n);
		vector<ii>ind;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==-1)a[i]=n+5;
			ind.pb({a[i],i});
		}
		sort(ALL(ind));
		reverse(ALL(ind));
		
		auto add_edge=[&](ll i, ll j, ll _t, ll dir){
			assert(i<j);
			ll t=min(a[i],a[j]);
			assert(t==_t);
			if(a[i]==a[j])add(i,j,dir);
			else {
				if(a[i]==t)swap(i,j);
				add(i,j,t&1);
			}
		};
		
		set<ll>st;
		vv now;
		fore(i,0,n){
			now.pb(ind[i].snd);
			if(i==n-1||ind[i].fst!=ind[i+1].fst){
				ll t=ind[i].fst;
				// vv arr(n);
				vv old;
				for(auto i:st)old.pb(i);
				sort(ALL(now));
				// cout<<"\ntime "<<t<<"\n";
				// imp(old)
				// imp(now)
				ll p=0;
				vv arr;
				for(auto i:now){
					while(p<SZ(old)&&old[p]<i)arr.pb(old[p++]);
					arr.pb(i);
				}
				while(p<SZ(old))arr.pb(old[p++]);
				
				// imp(arr)
				// cout<<endl;
				ll did=a[arr[0]]!=t;
				fore(i,0,SZ(arr)-1){
					did|=a[arr[i+1]]!=t;
					ll dir=1;
					
					if((t&1)&&!did)dir=0;
					else if(t%2==0&&did)dir=0;
					
					add_edge(arr[i],arr[i+1],t,dir);
				}
				
				
				for(auto i:now)st.insert(i);
				now.clear();
			}
			
		}
		
		
		fore(i,0,n)if(!vis[i])dfs(i);
		reverse(ALL(ord));
		vv pos(n);
		fore(i,0,n)pos[ord[i]]=i;
		
		for(auto i:pos)cout<<i+1<<" ";;cout<<"\n";
		
	}
	return 0;
}
