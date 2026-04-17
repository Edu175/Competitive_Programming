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

vector<ll> all[MAXN];
void agr(ll i0, ll j0){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)
		all[i].pb(j);
};
ll get_idx(ll i, ll j){
	auto &vec=all[i];
	auto po=lower_bound(ALL(vec),j);
	if(po==vec.end()||*po!=j)return -1;
	return 
}

#define maxig(a,b) a=max(a,b)
struct FTree2d{
	map<int,ii> ft[MAXN+1];
	void upd(int i0, int j0, ii v){
		for(int i=i0+1;i<=MAXN;i+=i&-i)
		for(int j=j0+1;j<=MAXN;j+=j&-j)
			maxig(ft[i][j],v);
	}
	ii get(int i0, int j0){ // [0,i0) , [0,j0)
		ii r={0,-1};
		for(int i=i0;i;i-=i&-i)
		for(int j=j0;j;j-=j&-j)
			maxig(r,ft[i][j]);
		return r;
	}
};
struct FTree1d{
	ii ft[MAXN+1];
	void upd(int i0, ii v){
		for(int i=i0+1;i<=MAXN;i+=i&-i)
			maxig(ft[i],v);
	}
	ii get(int i0){ // [0,i0)
		ii r={0,-1};
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
FTree1d ft1;
FTree2d ft2;

vector<vv> a;
vv val;
ll m;
ii get1(vv b){return ft1.get(b[0]);}
ii get2(vv b){return ft2.get(b[0],b[1]);}
ii get(ll i){
	if(m==1)return get1(a[i]);
	if(m==2)return get2(a[i]);
	ii mx={0,-1};
	fore(j,0,i){
		ii cur={val[j],j};
		if(good(a[j],a[i]))maxig(mx,cur);
	}
	return mx;
}
void upd(ll i){
	ii v={val[i],i};
	if(m==1)ft1.upd(a[i][0],v);
	if(m==2)ft2.upd(a[i][0],a[i][1],v);
}

int main(){FIN;
	ll n; cin>>m>>n;
	a=vector<vv>(n,vv(m));
	fore(j,0,m)fore(i,0,n)cin>>a[i][j];
	vv fa(n);
	val=vv(n);
	fore(i,0,n){
		auto rq=get(i);
		fa[i]=rq.snd;
		val[i]=rq.fst+1;
		upd(i);
	}
	ll mx=0;
	fore(i,0,n)if(val[i]>val[mx])mx=i;
	vv res;
	while(mx!=-1)res.pb(mx),mx=fa[mx];
	reverse(ALL(res));
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
