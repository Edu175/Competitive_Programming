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
const ll MAXN=1e6+5;

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	vv wh(MAXN,-1);
	vv dp(MAXN); dp[0]=1;
	ll mx=0;
	fore(i,0,n){
		ll v=a[i];
		for(ll j=mx;j>=0;j--)if(dp[j]&&!dp[j+v])dp[j+v]=1,wh[j+v]=v,mx=max(mx,j+v);
	}
	ll bad=sum&1;
	bad|=!dp[sum/2];
	if(bad){
		cout<<"-1\n";
		return 0;
	}
	multiset<ll> st(ALL(a));
	vv b;
	for(ll s=sum/2;s;s-=wh[s]){
		b.pb(wh[s]);
		st.erase(st.find(wh[s]));
	}
	a=vv(ALL(st));
	while(SZ(a)&&SZ(b)){
		ll &x=a.back(),&y=b.back();
		cout<<x<<" "<<y<<"\n";
		ll q=min(x,y);
		x-=q,y-=q;
		if(!x)a.pop_back();
		else b.pop_back();
	}
	return 0;
}