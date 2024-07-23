#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=455,INF=MAXN*MAXN;
ll k;
vector<ll>a;
ll fn(ll n){return n*(n+1)/2;}
ll cuenta(ll n, ll k){
	if(k>=n)return 0;
	ll z=n-k,b=k+1,r=z%b;
	ll res=r*fn((z+b-1)/b)+(b-r)*fn(z/b);
	// cout<<"cuenta "<<n<<" "<<k<<": "<<res<<"\n";
	return res;
}
ll dp[2][MAXN];

int main(){
	JET
	ll n; cin>>n>>k;
	string s; cin>>s;
	ll q=0;
	fore(i,0,n){
		if(s[i]=='0'){
			if(q)a.pb(q),q=0;
		}
		else q++;
	}
	if(s.back()=='1')a.pb(q);
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	ll m=SZ(a);
	// cout<<n<<"\n";
	for(ll i=m-1;i>=0;i--)fore(s,0,n+1){
		ll &res=dp[i&1][s];
		res=INF;
		fore(j,0,s+1){
			ll resi=cuenta(a[i],j)+dp[(i+1)&1][s-j];
			// cout<<i<<" "<<s<<" "<<j<<": "<<resi<<"\n";
			res=min(res,resi);
			// if(res==-1||resi<res)res=resi;
		}
		// cout<<"dp "<<i<<" "<<s<<": "<<res<<"\n";
	}
	ll l=0,r=n+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(dp[0][m]<=k)r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}