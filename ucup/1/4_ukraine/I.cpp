#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=998244353;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,m; cin>>n>>m;
		ll l[n],r[n];
		mset(l,0);
		fore(i,0,n) r[i]=m;
		bool bad=0;
		fore(i,0,n)fore(j,0,m){
			ll a; cin>>a;--a;
			if(a<0) continue;
			if(a==i+j) l[i]=max(l[i],j+1);
			else if(a==i+j+1) r[i]=min(r[i],j);
			else bad=1;
		}
		if(bad){
			cout<<"0\n"; continue;
		}
		fore(i,1,n) r[i]=min(r[i],r[i-1]),l[n-i-1]=max(l[n-i-1],l[n-i]);
		// cout<<"l: ";show(l);
		// cout<<"r: ";show(r);
		ll dp[2][m+1];
		mset(dp,0);
		dp[0][m]=1;
		fore(i,0,n){
			ll id=i&1;
			ll acum=0; mset(dp[id^1],0);
			for(ll j=m; j>=0; j--){
				acum=addm(acum,dp[id][j]);
				if(r[i]>=j&&j>=l[i]) dp[id^1][j]=acum;
			}
			// show(dp[id^1]);
		}
		ll rt=0;
		fore(j,0,m+1) rt=addm(rt,dp[n&1][j]);
		cout<<rt<<"\n";
	}
	return 0;
}

