#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define showp(v) {cout<<#v<<": ";for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> tri;

const ll MAXN=2e5+5;

vv dp(MAXN);

int main(){FIN;
	dp[0]=0;
	fore(i,1,MAXN){
		dp[i]=i;
		for(ll j=1;j*j<=i;j++)dp[i]=min(dp[i],1+dp[i-j*j]);
	}
	// show(dp)
	// cerr<<"max: "<<*max_element(ALL(dp))<<"\n";
	// return 0;
	vv is(MAXN);
	vv sqs;
	for(ll i=1;i*i<MAXN;i++)sqs.pb(i*i),sqs.pb(-i*i),is[i*i]=1;
	sort(ALL(sqs));
	vector<tri> two;
	for(auto i:sqs)for(auto j:sqs){ // linear
		ll mn=min({ll(0),i,i+j});
		ll mx=max({ll(0),i,i+j});
		two.pb({-mn,mx,i+j});
	}
	sort(ALL(two)); // nlogn
	vector<vector<vector<ii>>> bags(2,vector<vector<ii>>(MAXN));
	
	for(auto [mn,mx,d]:two){
		ll l=upper_bound(ALL(sqs),-d)-sqs.begin();
		ll r=lower_bound(ALL(sqs),MAXN-d)-sqs.begin();
		fore(id,l,r){ // nsqrtn*8
			ll i=sqs[id];
			ll d2=d+i;
			if(dp[d2]<4)continue; // /8
			ll mx2=max(mx,d2);
			auto &b=bags[1][d2];
			if(SZ(b)&&b.back().snd<=mx2)continue;
			// gano estricto en snd
			while(SZ(b)&&mn<=b.back().fst)b.pop_back();
			b.pb({mn,mx2});
		}
		
		// ahora las de 2
		if(d>0&&d<MAXN){
			if(dp[d]<3)continue;
			auto &b=bags[0][d];
			if(SZ(b)&&b.back().snd<=mx)continue;
			// gano estricto en snd
			b.pb({mn,mx});
		}
	}
	
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		while(q--){
			ll a,b; cin>>a>>b; a--,b--; ll d=b-a;
			ll res=dp[d];
			fore(ty,0,2){
				auto &bg=bags[ty][d];
				auto ptr=lower_bound(ALL(bg),ii({a+1,-1}));
				if(ptr!=bg.begin()&&n-1-a>=(--ptr)->snd)res=min(res,2+ty);
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
