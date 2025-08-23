#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn= 2e5+5;
int uf[3*maxn];
int sz[3*maxn];
int find(int x){ return uf[x]<0?x:uf[x]=find(uf[x]);}
bool join(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(uf[x]>uf[y]) swap(x,y);
	uf[x]+=uf[y];
	sz[x]+=sz[y];
	uf[y]=x;
	return true;
}
#define neg(baba) (2*maxn-1-baba)
bool vis[3*maxn];
int main(){
	JET
	mset(uf,-1);
	mset(sz,0);
	fore(i,0,maxn){
		sz[neg(i)]=1;
	}
	ll _; cin>>_;while(_--){
		ll n;  cin>>n;
		vector<ii> v[n];
		ll a[n], b[n];
		fore(i,0,n){
			ll x; cin>>x; x--;
			a[i]=x;
			v[x].pb({i,0});
		}
		fore(i,0,n){
			ll x; cin>>x; x--;
			b[i]=x;
			v[x].pb({i,1});
		}
		bool f=1;
		fore(i,0,n) if(SZ(v[i])!=2) {f=0; break;}
		if(!f) {cout<<"-1"; continue;}
		fore(i,0,n){
			for(auto [pos,typ]: v[a[i]]){
				if(pos!=i){
					// cout<<a[i]<<"de "<<i<<" con "<<a[pos]<<" o "<<b[pos]<<" de "<<pos<<" "<<typ<<"\n";
					join(i,(typ?pos:neg(pos)));
					join(neg(i),(typ?neg(pos):pos));
				}
			}
			for(auto [pos,typ]: v[b[i]]){
				if(pos!=i){
					// cout<<b[i]<<"de "<<i<<" con "<<a[pos]<<" o "<<b[pos]<<" de "<<pos<<" "<<typ<<"\n";
					join(i,(typ?neg(pos):pos));
					join(neg(i),(typ?pos:neg(pos)));
				}
			}
		}
		// fore(i,0,n) cout<<find(i)<<" ";;cout<<"\n";
		// fore(i,0,n) cout<<find(sz[find(i)])<<" ";;cout<<"\n";
		// fore(i,0,n) cout<<find(find(neg(i)))<<" ";;cout<<"\n";
		ll s=0;
		vv r;
		fore(i,0,n){
			if(sz[find(neg(i))]<sz[find(i)]) r.pb(i);
			if(sz[find(neg(i))]==sz[find(i)] && find(neg(i))<find(i)) r.pb(i);	
			if(!vis[find(i)]){
			s+=min(sz[find(i)],sz[find(neg(i))]);
			f=f&(find(i)!=find(neg(i)));
			vis[find(i)]=1;
			vis[find(neg(i))]=1;
		}}
		
		fore(i,0,n){
			sz[i]=0;
			sz[neg(i)]=1;
			uf[i]=-1;
			uf[neg(i)]=-1;
			vis[i]=0;
			vis[neg(i)]=0;
		}
		cout<<(f?s:-1)<<"\n";
		if(!f) continue;
		fore(i,0,SZ(r)){
			cout<<r[i]+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

// 6
// 4
// 1 2 3 4
// 2 3 1 4
// 5
// 5 3 5 1 4
// 1 2 3 2 4
// 3
// 1 2 1
// 3 3 2
// 4
// 1 2 2 1
// 3 4 3 4
// 4
// 4 3 1 4
// 3 2 2 1
// 3
// 1 1 2
// 3 2 2
// 0de 0 con 2 o 0 de 2 1
// 1de 0 con 1 o 2 de 1 0
// 1de 1 con 0 o 1 de 0 1
// 2de 1 con 2 o 0 de 2 0
// 2de 2 con 1 o 2 de 1 1
// 0de 2 con 0 o 1 de 0 0
// 4
// 4de 0 con 4 o 2 de 2 0
// 0de 0 con 0 o 1 de 3 0
// 2de 1 con 4 o 2 de 2 1
// 1de 1 con 0 o 1 de 3 1
// 4de 2 con 4 o 0 de 0 0
// 2de 2 con 2 o 1 de 1 0
// 0de 3 con 4 o 0 de 0 1
// 1de 3 con 2 o 1 de 1 1
// 3
// 0de 0 con 0 o 1 de 2 0
// 2de 0 con 1 o 2 de 1 1
// 1de 1 con 0 o 1 de 2 1
// 2de 1 con 0 o 2 de 0 1
// 0de 2 con 0 o 2 de 0 0
// 1de 2 con 1 o 2 de 1 0
// 1
// 0de 0 con 0 o 3 de 3 0
// 2de 0 con 1 o 2 de 2 1
// 1de 1 con 1 o 2 de 2 0
// 3de 1 con 0 o 3 de 3 1
// 1de 2 con 1 o 3 de 1 0
// 2de 2 con 0 o 2 de 0 1
// 0de 3 con 0 o 2 de 0 0
// 3de 3 con 1 o 3 de 1 1
// 2
// 3de 0 con 3 o 0 de 3 0
// 2de 0 con 2 o 1 de 1 0
// 2de 1 con 3 o 2 de 0 1
// 1de 1 con 0 o 1 de 2 1
// 0de 2 con 3 o 0 de 3 1
// 1de 2 con 2 o 1 de 1 1
// 3de 3 con 3 o 2 de 0 0
// 0de 3 con 0 o 1 de 2 0
// 2
// -1