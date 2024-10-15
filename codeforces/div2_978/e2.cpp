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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll cas=(1ll<<30)%MOD;
const ll MAXN=4e5+5;
ll id[MAXN],xv[MAXN],fa[MAXN];
vv comp[MAXN];
ll flag=1;
ll uf_join(ll x, ll y, ll w){
	// cout<<"join "<<x<<","<<y<<" "<<w<<"\n";
	ll _x=x,_y=y;
	x=id[x],y=id[y];
	if(x==y){
		// cout<<"cycle "<<_x<<","<<_y<<" "<<w<<": "<<xv[_x]<<" "<<xv[_y]<<": "<<(xv[_x]^xv[_y])<<" = "<<((xv[_x]^xv[_y]^w)==0)<<"\n";
		flag&=(xv[_x]^xv[_y]^w)==0;
		return 0;
	}
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y),swap(_x,_y);
	ll dif=xv[_x]^xv[_y]^w;
	for(auto i:comp[y])xv[i]^=dif,comp[x].pb(i),id[i]=x;
	comp[y].clear();
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k,q; cin>>n>>m>>k>>q;
		fore(i,0,n+m){
			xv[i]=0; id[i]=i;
			comp[i]={i};
		}
		ll res=0; flag=1;
		auto get=[&](){
			ll lib=n+m-1-res;
			// cout<<"get "<<flag<<"\n";
			return fpow(cas,lib)*flag;
		};
		auto scan=[&](){
			ll i,j,v; cin>>i>>j>>v; i--,j--;
			res+=uf_join(i,n+j,v);
			// fore(i,0,n+m)cout<<xv[i]<<" ";;cout<<"\n\n";
		};
		fore(i,0,k)scan();
		cout<<get()<<"\n";
		fore(i,0,q){
			scan();
			cout<<get()<<"\n";
		}
	}
	return 0;
}
