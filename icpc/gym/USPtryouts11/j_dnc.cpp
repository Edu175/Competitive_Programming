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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

#define maxig(i,j) if(val[i]<val[j])i=j
vv val;
ll NEUT=0;
struct FTree1d{
	ll ft[MAXN+1];
	void clear(int i0){
		for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=0;
	}
	void upd(int i0, ll v){
		for(int i=i0+1;i<=MAXN;i+=i&-i)
			maxig(ft[i],v);
	}
	ll get(int i0){ // [0,i0)
		ll r=NEUT;
		for(int i=i0;i;i-=i&-i)
			maxig(r,ft[i]);
		return r;
	}
};

bool good(vv a, vv b){
	ll fg=1;
	fore(i,0,SZ(a))fg&=a[i]<b[i];
	return fg;
}
FTree1d ft;

vector<vv> a;
ll m;
ll get(ll i){
	if(m==1)return ft.get(a[i][0]);
	ll mx=NEUT;
	fore(j,0,i){
		ll cur=j;
		if(good(a[j],a[i]))maxig(mx,cur);
	}
	return mx;
}
void upd(ll i){
	if(m==1)ft.upd(a[i][0],i);
}

vv fa;

ll le[MAXN];

void f(ll l, ll r){
	if(r-l==1){val[l]=1;fa[l]=0;le[l]=l;return;}
	ll m=(l+r)/2;
	f(l,m); f(m,r);
	vector<ii> xs;
	fore(i,l,r)xs.pb({a[i][0],-i});
	sort(ALL(xs));
	cerr<<"\nf "<<l<<","<<r<<":\n";
	for(auto [x,i]:xs){
		i=-i;
		cout<<x<<" "<<i<<": ";
		if(i<m){
			ft.upd(a[i][1],i);
			cout<<"upd "<<a[i][1]<<"\n";
		}
		else {
			auto p=ft.get(a[le[i]][1]);
			cout<<"query "<<a[le[i]][1]<<": "<<p<<": ";
			if(p!=0){
				fa[le[i]]=p;
				val[i]+=val[p];
				le[i]=le[p];
			}
			cout<<le[i]<<" "<<val[i]<<"\n";
		}
	}
	fore(i,l,m)ft.clear(a[i][1]);
}

void solve(){ // calcs fa and val
	assert(m==2);
	ll n=SZ(a);
	f(1,n);
	fore(i,1,n)cout<<i<<": "<<fa[i]<<" "<<le[i]<<" "<<val[i]<<"\n";
}

int main(){FIN;
	ll n; cin>>m>>n; n++;
	a=vector<vv>(n,vv(m));
	fore(j,0,m)fore(i,1,n)cin>>a[i][j];
	
	auto zip=[&](ll w){
		vv vals;
		fore(i,0,n)vals.pb(a[i][w]);
		sort(ALL(vals));
		vals.resize(unique(ALL(vals))-vals.begin());
		fore(i,0,n)a[i][w]=lower_bound(ALL(vals),a[i][w])-vals.begin();
	};
	
	fore(i,0,m)zip(i);
	
	fore(i,0,n)imp(a[i])
	
	val=fa=vv(n);
	if(m==2)solve();
	else {
		fore(i,1,n){
			fa[i]=get(i);
			val[i]=val[fa[i]]+1;
			upd(i);
		}
	}
	ll mx=1;
	fore(i,1,n)if(val[i]>val[mx])mx=i;
	vv res;
	while(mx!=NEUT)res.pb(mx),mx=fa[mx];
	reverse(ALL(res));
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
	return 0;
}
