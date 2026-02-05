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
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>MOD;
		ll p=fpow(m,MOD-2);
		ll tot=fpow(m,n);
		vv sp(n+1);
		ll pot=1;
		fore(i,1,n+1){
			sp[i]=add(sp[i-1],pot);
			pot=mul(pot,p);
		}
		ll sum=0,dob=0;
		fore(i,0,n+1)fore(od,0,2){
			ll z=min(i,n-od-i);
			if(z<0)continue;
			ll rhs=sub(sp[z+1],sp[!od]);
			ll cur=mul(sum,rhs);
			dob=add(dob,cur);
			sum=add(sum,rhs); // rhs = lhs actually
			// cout<<i<<" "<<od<<": "<<cur<<"\n";
		}
		// cerr<<"dob "<<mul(dob,tot)<<"\n";
		ll same=0,sol=0; // sol is only diff
		fore(mx,0,n+1)fore(b,0,2){
			ll z=!b+2*mx;
			ll slide=n+1-z;
			if(slide<=0||(b&&mx==0))continue;
			ll otr=mx+1 -1-b;
			ll cur=mul(slide,fpow(p,mx));
			sol=add(sol,mul(otr,cur));
			same=add(same,cur);
			// cout<<mx<<" "<<b<<": "<<cur<<": "<<mul(mul(otr,cur),tot)<<"\n";
		}
		// cerr<<"sol "<<mul(sol,tot)<<"\n";
		// cerr<<"same "<<mul(same,tot)<<"\n";
		ll res=add(dob,sol);
		res=mul(res,2);
		res=add(res,same);
		// cerr<<mul(res,tot)<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
