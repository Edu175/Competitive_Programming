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
const ll MAXN=2e5+5;

ll val[MAXN];
ll tot;
ll clique(vv v){
	ll res=1,sum=val[v[0]];
	// cout<<"clique { ";
	// for(auto i:v)cout<<i<<" ";
	// cout<<"}:\n";
	fore(i,1,SZ(v)){
		res=mul(res,sub(fpow(2,sum),1));
		// cout<<i<<": "<<sum<<endl;
		tot-=sum;
		sum+=val[v[i]];
	}
	// cout<<res<<"\n"<<endl;
	val[v[0]]=sum;
	return res;
}
ll to2(ll n){return n*(n-1)/2;}
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	tot=to2(n);
	// cout<<tot<<"\n";
	vv r(n,n);
	ll res=1;
	// cout<<clique(1)<<"\n";
	for(ll i=n-1;i>=0;i--){
		ll x=a[i];
		r[i]=i+1; val[i]=1;
		vv v={i};
		while(r[i]<n&&x>a[r[i]]){
			v.pb(r[i]);
			r[i]=r[r[i]];
		}
		res=mul(res,clique(v));
		// fore(j,0,SZ(v))us[v[j]]-=SZ(v)-1-j;
		// cout<<i<<": "; imp(v);
	}
	assert(tot>=0);
	res=mul(res,fpow(2,tot));
	cout<<res<<"\n";
	return 0;
}
