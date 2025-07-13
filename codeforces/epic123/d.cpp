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
const ll MAXN=3e5+5;
typedef pair<ii,ii> node;
node oper(node a, node b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}
node NEUT={{MAXN,MAXN},{-1,-1}};
struct STree{
	int n; vector<node>t;
	STree(){}
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
vv g[MAXN];
ll cnt=0;
ll S[MAXN],E[MAXN];
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x])dfs(y);
	E[x]=cnt;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
		}
		vv fa(n);
		fa[0]=-1;
		cnt=0;
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
			fa[i]=p;
		}
		dfs(0);
		vector<STree> st(n);
		fore(i,0,n)st[i]=STree(SZ(g[i]));
		vv pos(n);
		fore(i,0,n)fore(j,0,SZ(g[i]))pos[g[i][j]]=j;
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		auto upd=[&](ll i){
			ii par={p[i],i};
			if(fa[i]!=-1)st[fa[i]].upd(pos[i],{par,par});
			// cout<<"upd "<<i<<": "<<fa[i]<<": "<<par.fst<<","<<par.snd<<"\n";
		};
		auto sz=[&](ll x){
			return E[x]-S[x];
		};
		auto bad=[&](ll x)->bool{
			if(x==-1)return 0;
			if(!SZ(g[x]))return 0; // hoja good
			auto rq=st[x].query(0,SZ(g[x]));
			ll y0=rq.fst.snd;
			ll y1=rq.snd.snd;
			// fore(i,0,SZ(g[x])){
			// 	auto v=st[x].t[st[x].n+i];
			// 	cout<<"{"<<v.fst.fst<<","<<v.fst.snd<<" "<<v.snd.fst<<","<<v.snd.snd<<"} ";
			// }
			// cout<<"\n";
			// imp(a)
			// cout<<"bad "<<x<<": "<<y0<<","<<y1<<endl;
			// cout<<p[y0]<<" "<<p[y1]+sz(y1)<<"=="<<p[x]+sz(x)<<"\n";
			ll good=p[y0]==p[x]+1&&p[y1]+sz(y1)==p[x]+sz(x);
			// cout<<!good<<"\n\n";
			return !good;
		};
		fore(i,0,n)upd(i);
		ll cant=0;
		fore(i,0,n)cant+=bad(i);
		// fore(i,-1,n)cout<<"bad "<<i<<": "<<bad(i)<<"\n";
		// cout<<cant<<" cant\n";

		fore(_,0,q){
			ll i,j; cin>>i>>j; i--,j--;
			ll x=a[i],y=a[j];
			set<ll>xs={x,fa[x],y,fa[y]};
			for(auto i:xs)cant-=bad(i);
			swap(a[i],a[j]);
			swap(p[x],p[y]);
			upd(x);
			upd(y);
			for(auto i:xs)cant+=bad(i);
			// imp(a)
			// imp(p)
			// fore(i,-1,n)cout<<"bad "<<i<<": "<<bad(i)<<"\n";
			// cout<<cant<<" cant\n";
			if(!cant)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
