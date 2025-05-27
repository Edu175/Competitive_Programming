#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
int uf[MAXN];
ll fat[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return x==-1||uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	assert(x!=y);
	assert(fat[x]==y||fat[y]==x);
	ll p=fat[x];
	// if(fat[x]==y)swap(x,y);
	if(fat[x]==y)p=fat[y];
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	fat[x]=p;
	return true;
}
vv g[MAXN];

void dfs0(ll x){
	for(auto y:g[x])if(y!=fat[x]){
		fat[y]=x;
		dfs0(y);
	}
}
ll k;
void operator+=(vv &a, vv b){
	ll m=min(max(SZ(a),SZ(b)),k+1);
	a.resize(m);
	b.resize(m);
	fore(i,0,m)a[i]+=b[i];
}
void operator-=(vv &a, vv b){
	for(auto &i:b)i=-i;
	a+=b;
}
vv shi(vv a, ll s){
	vv b(SZ(a)+s);
	fore(i,s,SZ(b))b[i]=a[i-s];
	return b;
}
vv cant[MAXN];
ll fa(ll x){
	return fat[x]=uf_find(fat[uf_find(x)]);
}
ll get(ll x, ll k){ // paths of distance k from x going x->fa(x) first
	ll prev=x,res=0;
	// cout<<"get "<<x<<"\n";
	for(ll y=fa(x),j=1;j<=k&&y!=-1;y=fa(y),j++){
		// cout<<"iter "<<y<<"\n";
		ll resi=cant[y][k-j]-(k-j>0?cant[prev][k-j-1]:0);
		res+=resi;
		prev=y;
	}
	return res;
}
ll numb(ll x, ll k){ // paths of distance k passing through x->fa(x) (not neccesarily first)
	ll res=0;
	fore(d,0,k)res+=cant[x][d]*get(x,k-d);
	return res;
}
ll res;
void upd(ll x, ll __y){
	x=uf_find(x),__y=uf_find(__y);
	if(fa(x)!=__y)swap(x,__y);
	assert(fa(x)==__y);
	assert(x);
	res+=-numb(x,k)+numb(x,k+1);
	
	// actually remove the edge
	auto my=cant[x];
	for(ll y=fa(x),j=1;j<=k+1&&y!=-1;y=fa(y),j++){
		cant[y]+=my;
		my=shi(my,1);
		cant[y]-=my;
	}
	uf_join(x,__y);
	cant[uf_find(x)]=cant[__y];
}

int main(){FIN;
	uf_init();
	ll n; cin>>n>>k;
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	fat[0]=-1;
	dfs0(0);
	fore(i,0,n)cant[i].resize(k+1);
	fore(x,0,n){
		for(ll y=x,j=0;j<=k&&y!=-1;y=fat[y],j++){
			// if(j>=SZ(cant[y]))cant[y].resize(j+1);
			cant[y][j]++;
		}
	}
	// ll res=0;
	fore(x,0,n){
		ll y=x;
		fore(_,0,k)if(y!=-1)y=fat[y];
		// cout<<x<<": "<<get(x,k)<<"+"<<(y!=-1)<<" = "<<get(x,k)+(y!=-1)<<endl;
		res+=get(x,k)+(y!=-1); // quiero tambien contar dos veces los caminos solo para arriba
	}
	assert(res%2==0);
	res/=2;
	// cerr<<"res inicial: "<<res<<"\n";
	
	fore(_,0,n-1){
		ll idx; cin>>idx;
		idx=(idx+res)%(n-1);
		// cerr<<"idx "<<idx<<"\n";
		upd(ed[idx].fst,ed[idx].snd);
		cout<<res<<"\n";
	}
	
	return 0;
}
