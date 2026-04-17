#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){ET;
	ll n; cin>>n;
	vector<vv> a(n);
	ll sum=0;
	priority_queue<ii>pq;
	fore(i,0,n){
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j];
		reverse(ALL(a[i]));
		sum+=m;
		pq.push({-a[i].back(),i});
	}
	ll res=0;
	for(ll d=sum;d;d--){
		auto [v,i]=pq.top(); pq.pop(); v=-v;
		a[i].pop_back();
		if(SZ(a[i]))pq.push({-a[i].back(),i});
		res=add(res,mul(v,fpow(365,d)));
	}
	cout<<res<<"\n";
}