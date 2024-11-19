#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,h,k; cin>>n>>h>>k;
		vector<ii>a,p;
		fore(i,0,n){
			ll x,y; cin>>x>>y; y-=x; x++;
			if(y>=0)p.pb({x,y});
			else a.pb({x,y});
		}
		sort(ALL(p)); reverse(ALL(p));
		while(SZ(p)&&h>=p.back().fst)h+=p.back().snd,p.pop_back();
		k-=SZ(p);
		if(k<0){
			cout<<"N\n";
			continue;
		}
		ll m=SZ(a);
		vector<vv> dp(m+3,vv(k+3));
		sort(ALL(a),[&](ii a, ii b){
			return -a.snd+b.fst<-b.snd+a.fst;
		});
		for(ll i=m-1;i>=0;i--)fore(c,0,k+1){
			auto &res=dp[i][c];
			res=max(a[i].fst, dp[i+1][c]-a[i].snd);
			if(c)res=min(res,dp[i+1][c-1]);
		}
		cout<<(dp[0][k]<=h?"Y\n":"N\n");
	}
	return 0;
}