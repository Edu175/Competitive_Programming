#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet; i++)
#define forr(i,a,b) for(int i=b-1, jet=a; i>=jet; i--)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=8005,INF=1e14;

vv get(vv a, ll NO, auto best){
	int n=SZ(a);
	vector<vv> dp(2,vv(n+5,NO));
	dp[0][n]=0;
	vv ret;
	fore(k,1,n+1){
		vector<ii> s;
		vector<ll> ans;
		ans.pb(NO);
		dp[k&1][n]=NO;
		forr(i,0,n){
			auto &res=dp[k&1][i];
			ll snd=dp[(k-1)&1][i+1];
			while(SZ(s)&&a[i]>=s.back().fst)
				snd=best(snd,s.back().snd),
				s.pop_back(),ans.pop_back();
			s.pb({a[i],snd});
			res=(best(ans.back(),a[i]+snd));
			ans.pb(res);
		}
		ret.pb(ans.back());
	}
	return ret;
}



int main(){
	ET
	int n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto men=[](ll a, ll b){return min(a,b);};
	auto may=[](ll a, ll b){return max(a,b);};
	auto r0=get(a,INF,men);
	auto r1=get(a,-INF,may);
	fore(i,0,n){
		cout<<r0[i]<<" "<<r1[i]<<"\n";
	}
}