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

const ll MAXN = 1e6+5;
vv g[MAXN];
ll S[MAXN],E[MAXN];

struct STree{
	ll oper(ll a, ll b){
		return a+b;
	}
	ll n; vv t;
	STree(ll n):n(n),t(2*n+5,0){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}	
	ll query(ll l, ll r){
		ll izq = 0, der = 0;
		for(l += n, r+=n;l<r;l>>=1,r>>=1){
			if(l&1) izq = oper(izq,t[l++]);
			if(r&1) der = oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

struct STreeRangeAssign{
	ll n;
	vv upds;
	ll NEUT;
	vv t;
	STreeRangeAssign(ll N):n(1ll<<(__lg(N)+1)),upds(1,-1),NEUT(0),t(2*n+5,NEUT){}
	void upd(ll l, ll r, ll v){
		assert(l<r);
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
	for(ll y:g[x])if(y!=-1){
		dad[y]=x;dfs1(y); wg[x]+=wg[y];
	}
}
ll curpos,pos[MAXN],head[MAXN];
void hld(ll x, ll c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c; ll mx=-1;
	for(ll y:g[x])if(y!=-1&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(ll y:g[x])if(y!=-1&&y!=mx)hld(y,-1);
}
void hld_init(ll rt){dad[rt]=-1;dfs1(rt);curpos=0;hld(rt,-1);}

STreeRangeAssign owns(1);
void updPath(ll x, ll y, ll v){ // y ancestor of x, [y,x]
	// cerr<<"updPath "<<x<<","<<y<<": "<<v<<"\n";
	assert(S[y]<=S[x] && S[x]<E[y]);
	while(head[x]!=head[y]){
		assert(x>=0);
		// cerr<<x<<" "<<y<<"\n";
		owns.upd(pos[head[x]],pos[x]+1,v);
		x=dad[head[x]];
	}
	assert(x>=0);
	owns.upd(pos[y],pos[x]+1,v);
}
bool wins(ii a, ii b){ // does b win?
	if(a.snd!=b.snd)return a.snd<b.snd;
	return a.fst>b.fst;
}

ll rival[MAXN]; // node of conflict
ll cnt = 0;
vv val;
STree st(1);
ii dfs(ll x){
	S[x] = cnt++;
	rival[x]=-1;
	if(!SZ(g[x])){
		st.upd(S[x],val[x]);
		owns.upd(pos[x],pos[x]+1,x);
		E[x]=cnt;
		return {x,val[x]};
	}
	ll y1=g[x][0];
	ll y2=g[x][1];
	auto got1=dfs(y1);
	auto got2=dfs(y2);
	if(wins(got1,got2))swap(got1,got2);
	ll sum=got1.snd+got2.snd;
	ll res=got1.fst;
	owns.upd(pos[x],pos[x]+1,res);
	rival[got2.fst]=x;
	E[x] = cnt;
	return {res,sum};
}

ll n,h,rt;
ll best;
void upd(ll x, ll w){
	// cerr<<"upd "<<x<<" "<<w<<"\n";
	ll ult=x;
	st.upd(S[x],w);
	
	while(rival[x] != -1){
		ll p = rival[x];
		ll rx=g[p][0];
		ll ry=g[p][1];

		if(!(S[rx]<=S[x] && S[x]<E[rx])) swap(rx,ry);
		
		ll y = owns.query(pos[p]);
		ll wrx = st.query(S[rx],E[rx]);
		ll wry = st.query(S[ry],E[ry]);
		// cerr<<x<<" "<<y<<" "<<p<<": "<<rx<<" "<<ry<<": "<<wrx<<" "<<wry<<"\n";
		if(wins({ry,wry},{rx,wrx})){
			swap(rival[x], rival[y]);
		}
		else {
			updPath(ult,rx,x);
			ult=p;
			x=y;
		}
	}
	updPath(ult, rt, x);
	best=x;
	assert(owns.query(pos[rt])==best);
}

void query(){
	// fore(i,0,n)cout<<owns.query(pos[i])<<" ";;cout<<"\n";
	// fore(i,0,h)cout<<rival[i]<<" ";;cout<<"\n"; cout<<endl;
	cout<<best+1<<"\n";
}

int main(){
	JET
	cin>>n;
	
	h=n; n=2*h-1; rt=n-1;
	val=vv(h);
	fore(i,0,h) cin>>val[i];
	fore(i,h,n){
		ll x,y; cin>>x>>y;x--,y--;
		g[i] = {x,y};
	}
	
	st = STree(2*n);
	owns = STreeRangeAssign(2*n);
	hld_init(rt);
	best=dfs(rt).fst;
	
	query();
	ll q; cin>>q;
	while(q--){
		ll x,w; cin>>x>>w; x--;
		upd(x,w);
		query();
	}
	return 0;
}

