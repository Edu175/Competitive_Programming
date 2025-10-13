#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	assert(e>=0);
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b),e>>=1;
	}
	return res;
}
ll n,m;
const ll MAXN=10;
ll a[MAXN][MAXN];
bool good(ll a, ll b, ll c, ll d){ // reading order
	if(a==b&&c==d)return 1;
	if(a==c&&b==d)return 1;
	return 0;
}
ll mem[MAXN][MAXN];
ll f(ll i, ll j){ // no hay cuadrados especiales
	if(j==m)return f(i+1,0);
	if(i==n)return 1;
	ll res=0;
	fore(v,0,3){
		a[i][j]=v;
		ll fg=1;
		fore(ip,0,i)fore(jp,0,j){
			fg&=!good(a[ip][jp],a[ip][j],a[i][jp],a[i][j]);
		}
		if(fg)res=add(res,f(i,j+1));
	}
	return res;
}
ll get(ll _n, ll _m){ // COMPLEMENTO
	n=_n,m=_m;
	if(n>m)swap(n,m);
	if(n==1)return fpow(3,n*m);
	if(m>7)return 0;
	
	auto &res=mem[n][m];
	if(res!=-1)return res;
	// cout<<"backtracking\n";
	res=f(0,0);
	return res;c
}

int main(){
	mset(mem,-1);
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll tot=fpow(3,n*m);
		ll com=get(n,m);
		ll res=sub(tot,com);
		cout<<res<<"\n";
	}
	return 0;
}