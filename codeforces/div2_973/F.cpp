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
typedef ll node;
#define oper max
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
vector<ll>g[MAXN];
ll ma[MAXN],found=0,b;
vv h;
void dfs0(ll x, ll fa=-1){
	ma[x]=1;
	h.pb(x);
	if(x==b){found=1;return;}
	for(auto y:g[x])if(!found&&y!=fa)dfs0(y,x);
	if(found)return;
	ma[x]=0;
	h.pop_back();
}
ll D[MAXN],mx;
void dfs1(ll x, ll fa=-1){
	mx=max(mx,D[x]);
	for(auto y:g[x])if(y!=fa&&!ma[y]){
		D[y]=D[x]+1;
		dfs1(y,x);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		//reset all  --------------------------
		fore(i,0,n){
			ma[i]=0;
			g[i].clear();
		}
		found=0,b=0; h.clear();
		
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		cin>>b>>b; b--;
		dfs0(0);
		// cout<<found<<" "<<b<<" found\n";
		vv v;
		for(auto i:h){
			D[i]=0;mx=0;
			dfs1(i);
			v.pb(mx);
		}
		ll m=SZ(h);
		vv vala(m),valb(m);
		fore(i,0,m){
			vala[i]=v[i]+i;
			valb[i]=v[i]+m-1-i;
		}
		STree sta(m),stb(m);
		fore(i,0,m)sta.upd(i,vala[i]),stb.upd(i,valb[i]);
		ll l=0,r=m-1;
		ll win=0,pl=0;
		while(r-l>1){
			if(pl==0){
				if(vala[l]>stb.query(l+1,r+1)){win=1;break;}
				l++;
			}
			else {
				if(valb[r]>=sta.query(l,r)){win=2;break;}
				r--;
			}
			pl^=1;
		}
		if(!win){
			// cout<<"none\n";
			win=!(vala[l]>valb[r])+1;
		}
		// imp(h)
		// imp(v)
		// cout<<"\n";
		// imp(vala)
		// imp(valb)
		// cout<<"\n";
		// cout<<win<<endl;
		// assert(ans==1||ans==2);
		if(win==1)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
