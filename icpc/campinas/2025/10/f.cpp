#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+10;

ll n,k;
ll a[MAXN],sp[MAXN];

ii aliens(ll lam){
	vector<ii> dp(n+3);
	deque<ii>dq; // start,opt
	auto cost=[&](ll i, ll j)->ii{
		assert(i>=0&&j>=0);
		return {(sp[j]-sp[i])*(j-i)+dp[j].fst+lam,dp[j].snd+1};
	};
	dq.pb({n-1,n});
	for(ll j=n-1;j>=0;j--){ // info hasta (j
		ll opt=dq.back().snd;
		assert(dq.back().fst==j);
		dp[j]=cost(j,opt);
		if(!j)break;
		// agrego j:
		// acomodo el final
		dq.pop_back();
		if(!SZ(dq)||dq.back().fst<j-1)dq.pb({j-1,opt});
		// saco algun prefijo usando a j de opt
		ll s=0;
		while(SZ(dq)){
			auto [i,opt]=dq.front();
			if(cost(i,j)<cost(i,opt))dq.pop_front(),s=i;
			else break;
		}
		if(!SZ(dq)){dq.pb({j-1,j});continue;}
		// deberia hacer binary para el nuevo start
		// entre [s,dq.front().fst)
		auto [e,ji]=dq.front();
		ll l=s,r=e-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(cost(m,j)<cost(m,ji))l=m+1;
			else r=m-1;
		}
		if(r>=0)dq.push_front({r,j});
	}
	return dp[0];
}
const ll INF=1e17; // 1e16
int main(){FIN;
	cin>>n>>k; k++;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(aliens(m).snd<=k)r=m-1;
		else l=m+1;
	}
	ll lam=l;
	auto [res,cnt]=aliens(lam);
	res-=k*lam;
	// cerr<<lam<<" lam\n";
	// cerr<<cnt<<" cnt\n";
	cout<<res<<"\n";
	return 0;
}