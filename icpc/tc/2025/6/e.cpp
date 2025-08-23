#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5*2+5;

vector<ii> dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll n,m;
bool allowed(ii a){
	return 0<=a.fst&&a.fst<n&&0<=a.snd&&a.snd<m;
}

pair<ii,ll> cv(ll x){
	ll bo=x%2; x/=2;
	return {{x/m,x%m},bo};
}
ll cv(pair<ii,ll> x){
	auto [a,bo]=x;
	return (a.fst*m+a.snd)*2+bo;
}
ii cvs(ll x){
	return cv(2*x).fst;
}
ll cvs(ii x){
	return cv({x,0})/2;
}
ii ray; // desde x coordinate con isla
ll go(ll x, ll d){
	auto y=cv(x);
	auto _y=y;
	y.fst=y.fst+dir[d];
	if(!allowed(y.fst))return -1;
	if(y.fst.snd>ray.snd){
		y.snd^=(_y.fst.fst<ray.fst)!=(y.fst.fst<ray.fst);
	}
	return cv(y);
}
ll opu(ll x){
	return x^1;
}

ll id[MAXN];
vv comp[MAXN];
ll t;
ll ans[MAXN];

void merge(ll x, ll y){
	// cout<<"merge "<<x<<" "<<y<<"\n";
	x=id[x],y=id[y];
	if(x==y)return;
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	for(auto i:comp[y]){
		id[i]=x;
		comp[x].pb(i);
		if(id[opu(i)]==x)ans[i]=t;
	}
	comp[y].clear();
}

vv bfs(vv s){
	vv d(n*m,-1);
	queue<ll>q;
	for(auto i:s)q.push(i),d[i]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(di,0,4){
			auto y=go(2*x,di);
			if(y==-1)continue;
			y/=2;
			
			if(d[y]==-1)d[y]=d[x]+1,q.push(y);
		}
	}
	return d;
}

int main(){
	JET
	mset(ans,-1);
	ll q; cin>>n>>m>>q;
	fore(i,0,MAXN)comp[i]={i},id[i]=i;
	vector<char> a(n*m,'.');
	vv s; ll cnt=0;
	fore(i,0,n)fore(j,0,m){
		cin>>a[cnt];
		if(a[cnt]=='#')ray={i,j};
		if(a[cnt]=='v')s.pb(cnt);
		cnt++;
	}
	auto d=bfs(s);
	vector<vv> h(n*m);
	fore(i,0,n*m){
		h[d[i]].pb(i);
	}
	vv put(n*m);
	for(ll _t=n*m-1;_t>=0;_t--)if(SZ(h[_t])){
		t=_t;
		for(auto _x:h[t])fore(bo,0,2){
			ll x=_x*2+bo;
			fore(di,0,4){
				auto y=go(x,di);
				if(y==-1||a[x/2]=='#'||a[y/2]=='#')continue;
				if(put[y/2])merge(x,y);
			}
			put[x/2]=1;
		}
	}
	fore(i,0,n)fore(j,0,m){
		ll x=cvs({i,j});
		auto &a=ans[x],&b=ans[opu(x)];
		if(a!=-1&&b!=-1)assert(a==b);
		if(a==-1)a=b;
		if(b==-1)b=a;
	}
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		cout<<ans[cvs({x,y})*2]<<"\n";
	}
	return 0;
}