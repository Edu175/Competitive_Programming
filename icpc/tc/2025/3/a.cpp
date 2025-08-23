#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e8+5;


int main(){
	JET
	ll n; cin>>n;
	vector<ii>a(n+1,{-INF,-1});
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd;
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	sort(ALL(a));
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	vv dp(n+2); // used
	fore(i,1,n+1){
		ll p=lower_bound(ALL(a),ii({a[i].fst-a[i].snd,-1}))-a.begin();
		p--;
		assert(p>=0);
		dp[i]=dp[p]+1;
	}
	ll mx=0;
	fore(i,1,n+1)mx=max(mx,dp[i]);
	cout<<n-mx<<"\n";
	return 0;
}