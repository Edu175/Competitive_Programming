#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=4e5+5;

vector<ll> g[MAXN];

ll idx[MAXN],lw[MAXN],cmp[MAXN],is[MAXN],qidx=0;
stack<ll>st;

void tjn(ll x){
	// cout<<"tjn "<<x<<"\n";
	lw[x]=idx[x]=qidx++;
	st.push(x); cmp[x]=-2;
	for(auto y:g[x]){
		if(idx[y]==-1||cmp[y]==-2){
			if(idx[y]==-1)tjn(y);
			lw[x]=min(lw[x],lw[y]);
		}
	}
	if(lw[x]==idx[x]){
		// ll y;
		// do{y=st.top(),st.pop(),cmp[y]=x;}
		// while(y!=x);
		while(st.top()!=x){
			cmp[st.top()]=x; st.pop();
		}
		cmp[st.top()]=x; st.pop();
	}
}

vector<ll>h;
ll N;
void scc(vector<ii> ed){
	for(auto [x,y]:ed){
		if(!is[x])is[x]=1,h.pb(x);
		if(!is[y])is[y]=1,h.pb(y);
	}
	for(auto [x,y]:ed)g[x].pb(y);
	// imp(h);
	for(auto x:h)if(idx[x]==-1)tjn(x);
	// fore(x,0,N){
	// 	cout<<"["<<x<<":"<<idx[x]<<","<<lw[x]<<"] ";
	// }
	// cout<<"\n";
	qidx=0;
	for(auto x:h){
		is[x]=0;
		g[x].clear();
	}
}
vector<pair<ll,ii>>uno;
void rec(ll s, ll e, vector<pair<ll,ii>>ed){
	ll m=(s+e)/2;
	vector<ii>edm;
	for(auto [t,ar]:ed)if(t<=m)edm.pb(ar);
	// cout<<"rec "<<s<<","<<e<<":\n"; 
	// for(auto [t,ar]:ed)cout<<"{"<<t<<",{"<<ar.fst<<","<<ar.snd<<"}} ";
	// cout<<"\n";
	// for(auto ar:edm)cout<<"{"<<ar.fst<<","<<ar.snd<<"} ";
	// cout<<"\n";
	scc(edm);
	// fore(i,0,N)cout<<cmp[i]<<" ";;cout<<"\n\n";
	vector<pair<ll,ii>>l,r;
	for(auto ar:ed){
		auto [x,y]=ar.snd;
		if(idx[x]!=-1&&idx[y]!=-1&&cmp[x]==cmp[y])l.pb(ar),uno.pb({m,ar.snd});
		else r.pb({ar.fst,{idx[x]==-1?x:cmp[x],idx[y]==-1?y:cmp[y]}});
	}
	for(auto i:h)idx[i]=-1;
	h.clear();
	if(e-s>1){
		rec(s,m,l);
		rec(m+1,e,r);
	}
}

ll uf[MAXN];
ll res=0;
ll val(ll x){
	return x==-1?0:x*x;
}
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return;
	// cout<<"joined "<<x<<" "<<y<<"\n";
	if(-uf[x]<-uf[y])swap(x,y);
	res-=val(uf[x])+val(uf[y]);
	uf[x]+=uf[y];
	uf[y]=x;
	res+=val(uf[x]);
}

int main(){FIN;
	ll n,n2,m; cin>>n>>n2>>m;
	N=n+n2;
	vector<pair<ll,ii>> ed;
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--,y--;
		char c; cin>>c;
		y+=n;
		if(c=='B')ed.pb({i,{x,y}});
		else ed.pb({i,{y,x}});
	}
	mset(idx,-1);
	rec(0,m,ed);
	uf_init();
	vector<ii>cou[m];
	for(auto [t,ar]:uno)cou[t].pb(ar);
	fore(i,0,m){
		// cout<<"event "<<i<<"\n";
		for(auto [x,y]:cou[i])uf_join(x,y);
		cout<<res<<"\n";
	}
	return 0;
}