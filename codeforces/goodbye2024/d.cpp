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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vv ia(n),ib; iota(ALL(ia),0); ib=ia;
		sort(ALL(ia),[&](ll i, ll j){return a[i]<a[j];});
		sort(ALL(ib),[&](ll i, ll j){return b[i]<b[j];});
		vv posa(n),posb(n);
		fore(i,0,n)posa[ia[i]]=i,posb[ib[i]]=i;
		ll cur=1;
		auto val=[&](ll i){return min(a[ia[i]],b[ib[i]]);};
		auto pongo=[&](ll i){cur=mul(cur,val(i));};
		auto saco=[&](ll i){cur=mul(cur,fpow(val(i),MOD-2));};
		fore(i,0,n)pongo(i);
		cout<<cur<<" ";
		while(q--){
		// cout<<"\n\n";
		// fore(i,0,n)cout<<a[ia[i]]<<" ";;cout<<"\n";
		// fore(i,0,n)cout<<b[ib[i]]<<" ";;cout<<"\n";
			ll w,k; cin>>w>>k; w--,k--;
			if(!w){
				ll i=posa[k];
				ll l=i+1,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(a[ia[m]]==a[ia[i]])l=m+1;
					else r=m-1;
				}
				saco(r);
				a[k]++;
				swap(ia[i],ia[r]);
				posa[ia[i]]=i;
				posa[ia[r]]=r;
				pongo(r);
				// cout<<i<<" -> "<<r<<"\n";
			}
			else {
				ll i=posb[k];
				ll l=i+1,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(b[ib[m]]==b[ib[i]])l=m+1;
					else r=m-1;
				}
				saco(r);
				b[k]++;
				swap(ib[i],ib[r]);
				posb[ib[i]]=i;
				posb[ib[r]]=r;
				pongo(r);
				// cout<<i<<" -> "<<r<<"\n";
			}
			// cout<<"\n\n";
			// fore(i,0,n)cout<<a[ia[i]]<<" ";;cout<<"\n";
			// fore(i,0,n)cout<<b[ib[i]]<<" ";;cout<<"\n";
			cout<<cur<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
