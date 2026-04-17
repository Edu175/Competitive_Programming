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
const ll MAXN=8005;
int uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
ll vis[MAXN];
vector<ii> ret;
vv g[MAXN];
bool a[MAXN][MAXN];
ll cnt[MAXN];
ll n;
vv per;
void dfs(ll x){
	// cerr<<"dfs "<<x<<"\n";
	vis[x]=1;
	while(1){
		ll go=-1;
		fore(y,0,n)if(!vis[y]&&a[y][x]){
			if(go==-1||cnt[y]<cnt[go])go=y;
		}
		if(go==-1)break;
		g[go].pb(x);
		ret.pb({go,x});
		assert(uf_join(x,go));
		// cerr<<"edge "<<go<<","<<x<<"\n";
		dfs(go);
	}
	for(auto y:per)if(a[y][x]&&uf_join(y,x)){
		g[y].pb(x);
		ret.pb({y,x});
		// cerr<<"edge snd "<<y<<","<<x<<"\n";
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			vis[i]=0;
			g[i].clear();
			fore(j,0,n)a[i][j]=0;
			cnt[i]=0;
		}
		ret.clear();
		fore(i,0,n){
			cnt[i]=0;
			fore(j,0,n){
				char c; cin>>c;
				a[i][j]=c-'0';
				cnt[i]+=a[i][j];
			}
		}
		per=vv(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){return cnt[i]<cnt[j];});
		uf_init(n);
		fore(i,0,n)if(!vis[i])dfs(i);
		ll good=-uf[uf_find(0)]==n;
		fore(x,0,n)good&=vis[x];
		if(!good){
			// cerr<<"first\n";
			cout<<"No\n";
			continue;
		}

		vector<vector<bool>> b(n);
		auto f=[&](ll x, auto &&f)-> vector<bool> {
			auto &res=b[x];
			if(SZ(res))return res;
			res=vector<bool>(n);
			res[x]=1;
			for(auto y:g[x]){
				auto got=f(y,f);
				fore(j,0,n)res[j]=res[j]||got[j];
			}
			return res;
		};
		fore(x,0,n){
			auto got=f(x,f);
			fore(j,0,n)good&=got[j]==a[x][j];
		}
		if(!good){
			// cerr<<"second\n";
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		for(auto [x,y]:ret)cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}
