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
const ll MAXN=4005;

ii a[MAXN];

bool vis[MAXN][MAXN];
vv xs,ys;

vv xc,yc;
ll get_idx(vv &v, ll x){
	auto p=lower_bound(ALL(v),x);
	if(p==v.end()||*p!=x)return -1;
	return p-v.begin();
}

ll ms[MAXN][MAXN];
ll step;
bool good;
ll len;
ii rt;
void doit(ii x, ll w){
	while(1){
		ll i=get_idx(xc,x.fst);
		ll j=get_idx(yc,x.snd);
		if(i==-1||j==-1){good=0;return;}
		ll k=w?j:i;
		auto &wh=w?ys:xs;
		if(vis[i][j]){
			good&=w&&rt==x;
			return;
		}
		
		vis[i][j]=1;
		
		ii m={k,wh[k]};
		if(!w)m.snd=get_idx(yc,m.snd);
		else swap(m.fst,m.snd),m.fst=get_idx(xc,m.fst);
		if(ms[m.fst][m.snd]==step)good=0;
		ms[m.fst][m.snd]=step;
		// cerr<<"dfs "<<x.fst<<","<<x.snd<<": "<<m.fst<<","<<m.snd<<": ";
		ll dx=xc[m.fst]-x.fst;
		ll dy=yc[m.snd]-x.snd;
		x.fst+=2*dx;
		x.snd+=2*dy;
		ll dif=abs(2*dx)+abs(2*dy);
		len+=dif;
		// if(!dif){good=0;return;}
		assert(dif);
		// cerr<<x.fst<<","<<x.snd<<"\n";
		w^=1;
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		xc.pb(a[i].fst);
		yc.pb(a[i].snd);
	}
	sort(ALL(xc)); sort(ALL(yc));
	xs=ys=vv(n);
	fore(i,0,n){
		auto [x,y]=a[i];
		xs[get_idx(xc,x)]=y;
		ys[get_idx(yc,y)]=x;
	}
	ll res=0;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		ii cur={a[i].fst,a[j].snd};
		// cerr<<"new cycle\n";
		good=1,len=0; ++step; rt=cur;
		doit(cur,1);
		// cerr<<good<<" "<<len<<"\n\n";
		if(good)res=max(res,len);
	}
	cout<<res<<"\n";
	return 0;
}