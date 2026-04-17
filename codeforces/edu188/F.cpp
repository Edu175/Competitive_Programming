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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll inv(ll a){return fpow(a,MOD-2);}
#define addig(a,b) a=add(a,b)
#define subig(a,b) a=sub(a,b)
#define mulig(a,b) a=mul(a,b)

int main(){FIN;
	assert(mul(5,inv(5))==1);
	ll n,m; cin>>n>>m;
	vv a(n);
	vector<ii> sa;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
	sort(ALL(sa));
	set<ll> st={-1,n};
	vv coefs(n);
	for(auto [asd,i]:sa){
		auto it=st.insert(i).fst;
		ll l=*prev(it),r=*next(it);
		auto &coef=coefs[i];
		coef=mul((i-l),(r-i));
	}
	ll fij=0; // inicial
	fore(i,0,n){
		ll cant=mul(i+1,n-i);
		ll cur=mul(inv(a[i]),cant);
		// cerr<<i<<": "<<inv(a[i])<<" "<<cant<<": "<<cur<<"\n";
		fij=add(fij,cur);
	}
	vv ks(m);
	fore(i,0,m)cin>>ks[i];
	
	vv cs(m+1),xs(m+1); // sweep
	
	fore(i,0,n){
		ll b=a[i];
		ll p=lower_bound(ALL(ks),b-1)-ks.begin();
		ll coef=coefs[i];
		ll uppC=sub(2,add(inv(b),b)); // 2 -1/b -b
		ll uppX=1; // k
		
		// ll lowC=0;
		ll lowX=inv(b); // k/a
		
		mulig(uppC,coef);
		mulig(uppX,coef);
		mulig(lowX,coef);
		
		addig(xs[0],lowX);
		subig(xs[p],lowX);

		addig(cs[p],uppC);
		subig(cs[m],uppC);

		addig(xs[p],uppX);
		subig(xs[m],uppX);
	}
	// cerr<<"fij: "<<fij<<"\n";
	vv ans(m);
	ll c=0,x=0;
	fore(i,0,m){
		addig(c,cs[i]);
		addig(x,xs[i]);
		auto &res=ans[i];
		ll k=ks[i];
		// cout<<k<<": "<<c<<" "<<x<<"\n";
		res=fij;
		addig(res,c);
		addig(res,mul(x,k));
	}
	
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}
