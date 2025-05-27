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
const ll MAXN=305;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	uf_init();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		if(c=='1')uf_join(i,j);
	}
	vv h[n];
	fore(i,0,n)h[uf_find(i)].pb(a[i]);
	fore(i,0,n)sort(ALL(h[i])),reverse(ALL(h[i]));
	vv ret(n);
	fore(i,0,n){
		auto &v=h[uf_find(i)];
		ret[i]=v.back();
		v.pop_back();
	}
	imp(ret)
	return 0;
}
