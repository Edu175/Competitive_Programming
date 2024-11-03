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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv A(n);
		vector<ii>a(n);
		fore(i,0,n){
			ll x; cin>>x;
			A[i]=x;
			ll c=0;
			while(x%2==0)c++,x/=2;
			a[i]={x,c};
		}
		auto val=[&](ll i){return a[i].fst<<a[i].snd;};
		auto valm=[&](ll i){
			return mul(a[i].fst,fpow(2,a[i].snd));
		};
		ll res=0;
		vv dom;
		fore(i,0,n){
			while(SZ(dom)&&(a[i].snd>=30||val(i)>=a[dom.back()].fst)){
				ll j=dom.back(); dom.pop_back();
				res=sub(res,valm(j));
				a[i].snd+=a[j].snd;
				a[j].snd=0;
				res=add(res,valm(j));
			}
			res=add(res,valm(i));
			dom.pb(i);
			// cout<<"\n\n"<<i<<": ";
			// imp(dom);
			// impr(a)
			cout<<res<<" ";
		}
		cout<<"\n";
		// cout<<"\n";
		// cout<<"\n";
	}
	return 0;
}
