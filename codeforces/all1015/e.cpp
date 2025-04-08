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
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=1e9+7,MAXF=1e4+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, LL b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}


int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),p(n,-1);
		ll k=0;
		fore(i,0,n){
			cin>>a[i],k+=a[i]==-1;
			if(a[i]!=-1)p[a[i]]=i;
		}
		vv c(n+1);
		vector<vv> qnt(n,vv(n));
		vector<ii>ra0,ra1;
		fore(l,0,n){
			ll lib=0;
			fore(r,l,n)lib+=a[r]==-1,c[lib]++,ra0.pb({l,r}),qnt[l][r]=lib;
		}
		ra1=ra0;
		sort(ALL(ra0));
		sort(ALL(ra1),[&](ii a, ii b){
			swap(a.fst,a.snd);
			swap(b.fst,b.snd);
			return a<b;
		});
		
		reverse(ALL(ra1));
		vector<vv> vis(n,vv(n));
		ll s=n,e=-1;
		auto good=[&](ii a){
			return a.fst<=s&&e<=a.snd;
		};
		ll res=0;
		fore(x,1,n+1){ // aparecen [0,x)
			ll hay=0;
			fore(i,0,n)hay+=a[i]!=-1&&a[i]<x;
			if(p[x-1]!=-1)s=min(s,p[x-1]),e=max(e,p[x-1]);
			fore(h,0,2){
				auto &v=(h?ra1:ra0);
				while(SZ(v)&&!good(v.back())){
					auto [l,r]=v.back();
					if(!vis[l][r])c[qnt[l][r]]--;
					vis[l][r]=1;
					v.pop_back();
				}
			}
			ll resi=0;
			fore(z,0,SZ(c)){
				ll num=c[z];
				ll obj=x-hay;
				ll ceb=mul(nCr(k-obj,z-obj),mul(fc[z],fc[k-z]));
				// cout<<z<<" "<<obj<<": "<<num<<" "<<ceb<<": "<<mul(ceb,num)<<"\n";
				resi=add(resi,mul(ceb,num));
			}
			// cout<<x<<": "<<resi<<"\n";
			res=add(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
