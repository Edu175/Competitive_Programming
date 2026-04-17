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
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors
// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXV=1e5+5;
vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}
short mu[MAXV] = {0,1}; // ojo
void mobius(){
	fore(i,1,MAXV)if(mu[i])for(int j=i+i;j<MAXV;j+=i)mu[j]-=mu[i];
}
ll sig(short coef, ll val){
	if(coef) return coef==1?val:sub(0,val);
	return 0; 
}
int main(){FIN;
	divisores();
	mobius();
	// fore(i,0,)
	ll n; cin>>n;
	vv pot(n+5);
	pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=add(pot[i-1],pot[i-1]);
	vv a(n);
	vv cant(MAXV),val(MAXV,1); // 1s
	// vector<vv> iter(MAXV);
	// fore(v,1,MAXV)for(auto d:divs[v])if(mu[v/d])iter[v].pb(d);
	auto upd=[&](ll v, ll pon){ // 1 o -1
		for(auto y:divs[v]){
			ll prev=pot[cant[y]];
			cant[y]+=pon;
			ll now=pot[cant[y]];
			for(auto x:divs[y]){
				auto u=mu[y/x];
				val[x]=add(val[x],
					sub(sig(u,now),sig(u,prev))
				);
			}
		}
	};
	fore(i,0,n)cin>>a[i],upd(a[i],1);
	ll tot=sub(fpow(2,n),1);
	tot=fpow(tot,MOD-2);
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(ty==2){
			ll p,v; cin>>p>>v; p--;
			// if(1){
			if(a[p]!=v){
				upd(a[p],-1);
				a[p]=v;
				upd(a[p],1);
			}
		}
		else {
			ll g; cin>>g;
			ll res=val[g];
			res=sub(res,1);
			// cerr<<res<<": ";
			res=mul(res,tot);
			cout<<res<<"\n";
		}
	}
	return 0;
}
