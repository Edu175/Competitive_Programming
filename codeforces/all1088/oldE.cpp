#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct node{
	vector<ii> dp;
	ll mn;
};

void rm_dup_fst(vector<ii> &a){
	vv vals;
	for(auto i:a)vals.pb(i.fst);
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	vector<ii> b;
	for(auto i:vals){
		ll mn=1e18;
		for(auto j:a)if(j.fst==i)mn=min(mn,j.snd);
		b.pb({i,mn});
	}
	a=b;
}

node merge(ll x, vector<node> a){
	ll sum=0;
	for(auto e:a)sum+=e.mn;
	node ret;
	auto &dp=ret.dp;
	dp.pb({x,sum+1});
	auto &mn=ret.mn;
	mn=sum+1;
	vv vec;
	for(auto e:a)for(auto [v,s]:e.dp){
		ll g=gcd(x,v);
		if(g==1)continue;
		ll cur=sum-e.mn+s;
		dp.pb({g,cur});
	}
	// cout<<"\n\nmerge "<<x<<":\n";
	// for(auto i:dp)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	rm_dup_fst(dp);
	vector<ii> _dp=dp; dp.clear();
	
	for(auto i:_dp){
		ll good=1;
		for(auto j:_dp)if(i!=j){
			if(i.snd==j.snd&&j.fst%i.fst==0){
				// assert(i.snd>=j.snd);
				good=0;
			}
			if(i.snd>j.snd+1)good=0; // unnecesary
		}
		if(good)dp.pb(i);
	}
	mn=sum+1;
	for(auto i:dp)mn=min(mn,i.snd);
	// cout<<"answer: "<<mn<<": ";
	// for(auto i:dp)cout<<i.fst<<","<<i.snd<<" ";;
	// cout<<endl;
	return ret;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		// cerr<<"testcase\n";
		ll n; cin>>n;
		vector<node> dp(n);
		for(ll x=n-1;x>=0;x--){
			ll val,k;
			cin>>val>>k;
			vector<node> a(k);
			fore(i,0,k){
				ll y; cin>>y; y--;
				a[i]=dp[y];
			}
			dp[x]=merge(val,a);
			cout<<dp[x].mn<<endl;
		}
	}
	return 0;
}
