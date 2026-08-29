#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN = 2e5+5;
ii g[MAXN];
ll S[MAXN],E[MAXN];

struct STree{
	ll oper(ll a, ll b){
		return a+b;
	}
	#define NEUT 0
	ll n; vv t;
	STree(ll n):n(n),t(2*n,NEUT){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}	
	ll query(ll l, ll r){
		ll izq = NEUT, der = NEUT;
		for(l += n, r+=n;l<r;l>>=1,r>>=1){
			if(l&1) izq = oper(izq,t[l++]);
			if(r&1) der = oper(t[--r],der);
		}
		return oper(izq,der);
	}
	#undef NEUT
};

struct STreeRangeAssign{
	ll n;
	vv upds;
	ll NEUT;
	vv t;
	STreeRangeAssign(ll n):n(n),upds(1,-1),NEUT(0),t(2*n,NEUT){}
	void upd(ll l, ll r, ll v){
		ll sz=SZ(upds); upds.pb(v);
		for(l+=n,r+=n; l<r; l>>=1,r>>=1){
			if(l&1) t[l++]=sz;
			if(r&1) t[--r]=sz;
		}
	}
	ll query(ll p){
		ll res=NEUT;
		for(p+=n;p>0;p>>=1)res=max(res,t[p]);
		return upds[res];
	}
};
ll wg[MAXN],dad[MAXN];
void dfs1(ll x){
	wg[x]=1;
	for(ll y:{g[x].fst,g[x].snd})if(y!=-1){
		dad[y]=x;dfs1(y); wg[x]+=wg[y];
	}
}
ll curpos,pos[MAXN],head[MAXN];
void hld(ll x, ll c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c; ll mx=-1;
	for(ll y:{g[x].fst,g[x].snd})if(y!=-1&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(ll y:{g[x].fst,g[x].snd})if(y!=-1&&y!=mx)hld(y,-1);
}
void hld_init(ll rt){dad[rt]=-1;dfs1(rt);curpos=0;hld(rt,-1);}

STreeRangeAssign owns(1);
void updPath(ll x, ll y, ll v){ // y ancestor of x, [y,x]
	// cerr<<"updPath "<<x<<","<<y<<"\n";
	while(head[x]!=head[y]){
		// cerr<<x<<" "<<y<<"\n";
		owns.upd(pos[head[x]],pos[x]+1,v);
		x=dad[head[x]];
	}
	owns.upd(pos[y],pos[x]+1,v);
}

ll rival[MAXN]; // node of conflict
ll cnt = 0;
ll dfs(ll x){
	S[x] = cnt++;
	ll r = x;
	auto [y1,y2]=g[x];
	if(y1!= -1){
		ll r1 = dfs(y1);
		ll r2 = dfs(y2);
		if(r1 > r2) swap(r1,r2), swap(y1,y2);
		rival[r2] = x;
		updPath(r2, y2, r2);
		r = min(r1,r2); 
	}
	E[x] = cnt;
	return r;
}

ll n,h,rt;
ll wins;
STree st(1);
void upd(ll x, ll w){
	// cerr<<"upd "<<x<<" "<<w<<"\n";
	ll xo = x;
	ll ult=x;
	while(rival[x] != -1){
		ll p = rival[x];
		auto [rx,ry]=g[p];
		if(!(S[rx]<=S[x] && S[x]<E[rx])) swap(rx,ry);
		
		ll y = owns.query(pos[ry]);
		// ll y = owns.query(pos[p]);
		ll wrx = st.query(S[rx],E[rx]);
		ll wry = st.query(S[ry],E[ry]);
		// cerr<<x<<" "<<y<<" "<<p<<": "<<rx<<" "<<ry<<": "<<wrx<<" "<<wry<<"\n";
		assert(wrx<=wry);
		if((wrx + w > wry) || (wrx + w == wry && x<y)){
			swap(rival[x], rival[y]);
		}
		else {
			updPath(ult,rx,x);
			ult=p;
			x=y;
		}
	}
	updPath(ult, rt, x);
	st.upd(S[xo],w);
	wins=x;
	assert(owns.query(pos[rt])==wins);
}

void query(){
	// fore(i,0,n)cout<<owns.query(pos[i])<<" ";;cout<<"\n";
	// fore(i,0,h)cout<<rival[i]<<" ";;cout<<"\n";
	cout<<wins+1<<"\n";
}

int main(){
	JET
	cin>>n;
	fore(i,0,2*n){
		g[i] = {-1,-1};
		rival[i]=-1;
	}
	
	h=n; n=2*h-1; rt=n-1;
	vv val(h);
	fore(i,0,h) cin>>val[i];
	fore(i,h,n){
		ll x,y; cin>>x>>y;x--,y--;
		g[i] = {x,y};
	}
	
	st = STree(n);
	owns = STreeRangeAssign(n);
	hld_init(rt);
	ll x=dfs(rt);
	updPath(x, rt, x);
	
	fore(i,0,h)upd(i,val[i]);
	query();
	ll q; cin>>q;
	while(q--){
		ll x,w; cin>>x>>w; x--;
		upd(x,w);
		query();
	}
	return 0;
}

