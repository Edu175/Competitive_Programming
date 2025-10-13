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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5,INF=1e18;
int uf[MAXN];

set<ii> cl,cr;

vector<ii> ran; // (m)
ll mnr[MAXN],mxl[MAXN];
void sac(ll i){
	cl.erase({mxl[i],i});
	cr.erase({mnr[i],i});
}
void put(ll i){
	cl.insert({mxl[i],i});
	cr.insert({mnr[i],i});
}

void uf_init(ll m){
	fore(i,0,m){
		uf[i]=-1;
		mnr[i]=ran[i].snd;
		mxl[i]=ran[i].fst;
		put(i);
	}
}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}

bool uf_join(int x, int y){
	// cout<<"join "<<x<<","<<y<<"\n";
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	
	sac(x); sac(y);
	
	uf[x]+=uf[y];uf[y]=x;
	mnr[x]=min(mnr[x],mnr[y]);
	mxl[x]=max(mxl[x],mxl[y]);
	
	put(x);
	return true;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv a(n),p(n+1);
	p[n]=n;
	fore(i,0,n)cin>>a[i],p[a[i]]=i;
	ran.resize(m);
	fore(i,0,m)cin>>ran[i].fst>>ran[i].snd,ran[i].fst--,ran[i].snd--;
	uf_init(m);
	ll res=0;
	fore(v,0,n+1){
		ll i=p[v];
		// impr(cl)
		// impr(cr)
		vv L,R;
		for(auto it=cl.upper_bound({i,INF});it!=cl.end();it++)
			R.pb(it->snd);
		for(auto it=cr.lower_bound({i,-1});it!=cr.begin();it--)
			L.pb(prev(it)->snd);
		vv nod=L;
		for(auto i:R)nod.pb(i);
		// cout<<v<<" "<<i<<": ";
		// imp(nod)
		fore(i,0,SZ(nod)-1)res+=v*uf_join(nod[i],nod[i+1]);
	}
	cout<<res<<"\n";
	return 0;
}
