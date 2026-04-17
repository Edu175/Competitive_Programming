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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXV=1e5+5;
vector<ll> divs[MAXV],pf[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
	fore(i,2,MAXV)if(!SZ(pf[i]))for(int j=i;j<MAXV;j+=i)pf[j].pb(i);
}
ll cant(ll n, ll p){
	ll c=0;
	while(n%p==0)c++,n/=p;
	return c;
}
// ll ala(ll p, ll k){
// 	ll res=1;
// 	fore(i,0,k)res*=p;
// 	return res;
// }
int main(){FIN;
	divisores();
	ll n; cin>>n;
	vv pot(n+5);
	pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],2);
	vv a(n);
	vv hists[MAXV];
	vv ms(MAXV);
	fore(i,1,MAXV)ms[i]=SZ(pf[i])+1;
	fore(v,1,MAXV)hists[v].resize(1ll<<ms[v]);
	auto upd=[&](ll v, ll pon){ // 1 o -1
		auto &ds=divs[v];
		// auto &ps=pf[v];
		// vv cs;
		// for(auto p:ps)cs.pb(cant(v,p));
		for(auto d:ds){
			ll sb=0;
			auto &ps=pf[d];
			ll m=SZ(ps);
			fore(i,0,m){
				ll p=ps[i];
				if(cant(v,p)==cant(d,p))sb|=1ll<<i;
			}
			if(ms[v]!=ms[d])sb|=1ll<<m; // bit extra
			// cout<<d<<": "<<m<<" "<<(1ll<<m)<<": "<<SZ(hists[d])<<" "<<sb<<endl;
			hists[d][sb]+=pon;
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
			upd(a[p],-1);
			a[p]=v;
			upd(a[p],1);
		}
		else {
			ll g; cin>>g;
			auto hist=hists[g];
			imp(hist)
			ll m=SZ(pf[g]),M=1ll<<m;
			assert(m>=0);
			//sos
			fore(j,0,m)fore(mk,0,M){
				if(mk>>j&1)hist[mk]+=hist[mk^(1ll<<j)];
			}
			// 2 ala coef
			fore(mk,0,M)hist[mk]=sub(pot[hist[mk]],1);
			// rev sos
			fore(j,0,m)for(ll mk=M-1;mk>=0;mk--){
				if(mk>>j&1)hist[mk]=sub(hist[mk],hist[mk^(1ll<<j)]);
			}
			
			ll res=hist[M-1];
			cerr<<res<<": ";
			res=mul(res,tot);
			cout<<res<<"\n";
		}
	}
	return 0;
}
