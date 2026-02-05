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
struct tn{
	ll c[2][2];
	tn(){}
	tn(ll d, ll ac, ll neut=0){
		mset(c,0);
		if(!neut)c[d][ac]++;
	}
}; // node type
typedef ii tl; // lazy type
tn NEUT(1,1,1);
tl CLEAR={0,0}; // cleared lazy node
tn oper(tn a, tn b){
	fore(i,0,2)fore(j,0,2)a.c[i][j]+=b.c[i][j];
	return a;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a.fst^=v.fst;
	a.snd^=v.snd;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	if(v.fst)swap(a.c[0][0],a.c[0][1]);
	if(v.snd)swap(a.c[1][0],a.c[1][1]);
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

const ll MAXN=1e5+5,LG=20;

ll xr[MAXN],D[MAXN],S[MAXN],E[MAXN];

vector<ii> g[MAXN];
ll cnt=0;
void dfs(ll x, ll fa){
	S[x]=cnt++;
	for(auto [y,w]:g[x])if(y!=fa){
		xr[y]=xr[x]^w;
		D[y]=D[x]+1;
		dfs(y,x);
	}
	E[x]=cnt;
}
// ll to2(ll x){return x*(x-1)/2;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		cnt=0; D[0]=0; xr[0]=0;
		dfs(0,-1);
		vector<STree> st(LG,STree(n));
		fore(j,0,LG){
			vector<tn> ini(n);
			fore(i,0,n)ini[S[i]]=tn(D[i]&1,xr[i]>>j&1);
			st[j].init(ini);
			// cout<<"ini "<<j<<": ";
			// fore(i,0,n){
			// 	cout<<"|";
			// 	fore(j,0,2){
			// 		fore(k,0,2)cout<<ini[i].c[j][k]<<",|"[k];
			// 	}
			// 	cout<<" ";
			// }
			// cout<<"\n";
		}
		ll q; cin>>q;
		while(q--){
			ll ty; cin>>ty;
			if(ty==1){
				ll x,v; cin>>x>>v; x--;
				fore(j,0,LG)if(v>>j&1){
					tl upd={0,0};
					if(D[x]&1)upd.fst=1;
					else upd.snd=1;
					st[j].upd(S[x],E[x],upd);
				}
			}
			else {
				ll x; cin>>x; x--;
				ll res=0;
				fore(j,0,LG){
					auto rq=st[j].query(S[x],E[x]);
					// cout<<j<<" rq: ";
					// cout<<"|";
					// fore(j,0,2){
					// 	fore(k,0,2)cout<<rq.c[j][k]<<",|"[k];
					// }
					// cout<<"\n";
					ll uno=rq.c[0][1]+rq.c[1][1];
					ll zer=rq.c[0][0]+rq.c[1][0];
					// cout<<"num "<<num<<"\n";
					res+=(uno*zer)<<j;
				}
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}
