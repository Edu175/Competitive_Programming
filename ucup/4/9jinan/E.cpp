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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=2e5+5;
vv g[MAXN];
ll fa[MAXN],is[MAXN]; // fa edge is heavy?
ll c[MAXN],a[MAXN]; // a is color
void dfs0(ll x){
	c[x]=1;
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs0(y);
		c[x]+=c[y];
	}
	sort(ALL(g[x]),[&](ll a, ll b)->bool {
		if(a==fa[x])return 0;
		if(b==fa[x])return 1;
		return c[a]>c[b];
	});
	if(fa[x]!=-1){
		assert(g[x].back()==fa[x]);
		g[x].pop_back();
	}
	if(SZ(g[x]))is[g[x][0]]=1;
}
ll cnt=0;
ll S[MAXN],E[MAXN],head[MAXN],D[MAXN];
vv ord;
void dfs1(ll x){
	if(!is[x])head[x]=x;
	S[x]=cnt++;
	ord.pb(x);
	for(auto y:g[x]){
		D[y]=D[x]+1;
		head[y]=head[x];
		dfs1(y);
	}
	E[x]=cnt;
}
int main(){FIN;
	vv pot2(MAXN); pot2[0]=1;
	fore(i,1,MAXN)pot2[i]=mul(pot2[i-1],2);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			fa[i]=-1;
			D[i]=0;
			head[i]=-1;
			is[i]=0;
		}
		cnt=0; ord.clear();
		vv tot(n);
		fore(i,0,n)cin>>a[i],a[i]--,tot[a[i]]++;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs0(0);
		dfs1(0);
		
		// fore(x,0,n){
		// 	cout<<x<<": ";
		// 	for(auto y:g[x])cout<<y<<" ";
		// 	cout<<"| "<<is[x]<<"\n";
		// }
		
		vv vis(n),cols;
		vv oc(n);
		auto val=[&](ll j){return pot2[tot[j]-oc[j]];};
		auto valS=[&](ll j){return pot2[oc[j]];};
		ll ini=0;
		fore(j,0,n)ini=add(ini,val(j));
		ll cur=ini,curS=n;
		auto agr=[&](ll x){
			// cout<<"agrego "<<x<<"\n";
			ll w=a[x];
			if(!vis[w])cols.pb(w);
			vis[w]=1;
			cur=sub(cur,val(w));
			curS=sub(curS,valS(w));
			oc[w]++;
			curS=add(curS,valS(w));
			cur=add(cur,val(w));
		};
		vv hs; // hojas
		fore(h,0,n)if(!SZ(g[h]))hs.pb(h);
		sort(ALL(hs),[&](ll a, ll b){
			return D[head[a]]>D[head[b]];
		});
		ll res=0;
		vv coefs(n,-1);
		vv sums(n);
		for(auto h:hs){ // si hoja
			// cout<<"\n\nhoja "<<h<<"\n";
			ll x=h;
			while(1){
				// now
				// cout<<"x: "<<x<<"\n";
				agr(x);
				if(SZ(g[x])){
					fore(i,E[g[x][0]],E[x])agr(ord[i]);
				}
				
				// comment!!
				// for(auto i:oc)cout<<i<<" ";;cout<<endl;
				// ll dbg=0;
				// fore(i,0,n)dbg=add(dbg,val(i));
				// assert(dbg==cur);
				
				ll abajo=0;
				for(auto y:g[x]){
					assert(coefs[y]!=-1);
					abajo=add(abajo,sums[y]);
				}
				ll coef=sub(curS,n);
				coef=sub(coef,abajo);
				sums[x]=add(coef,abajo);
				coefs[x]=coef;
				ll now=mul(coef,sub(cur,n));
				res=add(res,now);
				// next
				if(!is[x])break;
				x=fa[x];
				assert(x!=-1);
			}
			cur=ini; curS=n;
			for(auto i:cols)vis[i]=0,oc[i]=0;
			cols.clear();
		}
		ll sum=0;
		vv sump(n);
		for(auto x:ord){
			ll coef=coefs[x];
			sum=add(sum,coef);
			if(fa[x]!=-1)sump[x]=sump[fa[x]];
			sump[x]=add(sump[x],coef);
		}
		ll sac=0;
		fore(x,0,n){
			ll my=coefs[x];
			ll bad=add(sums[x],sump[x]);
			bad=sub(bad,my);
			ll otr=sub(sum,bad);
			ll now=mul(my,otr);
			sac=add(sac,now);
		}
		sac=mul(sac,(MOD+1)/2);
		res=sub(res,sac);
		res=mul(res,2);
		cout<<res<<"\n";
	}
	return 0;
}
