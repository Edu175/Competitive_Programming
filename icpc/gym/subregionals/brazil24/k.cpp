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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


const ll maxn=105;

int dp[maxn][maxn*maxn];

int main(){
	JET
	mset(dp,-1);
	ll n; cin>>n;
	ll a[n];
	ll S=0;
	fore(i,0,n){
		cin>>a[i];
		S+=a[i];
	}
	if(S&1){
		cout<<"-1\n";
		return 0;
	}
	dp[0][0]=maxn;
	fore(i,0,n){
		for(int k=i; k>=0; k--)for(int s=100*k; s>=0; s--)if(dp[k][s]>=0){
			if(dp[k+1][s+a[i]]>=0) continue;
			dp[k+1][s+a[i]]=i;
		}
	}
	S/=2;
	ll u=-1,K=-1;
	fore(i,0,n+1) if(dp[i][S]>=0) {u=dp[i][S]; K=i;}
	if(u<0){
		cout<<"-1\n"; return 0;
	}
	bool vis[n]; mset(vis,0);
	vv ids;
	while(u<maxn){
		ids.pb(u);
		vis[u]=1;
		S-=a[u];
		K--;
		u=dp[K][S];
	}
	vv  ids2;
	fore(i,0,n) if(!vis[i]) ids2.pb(i);
	ll s1=0,s2=0;
	ll l=0,r=0;
	// show(ids);
	// show(ids2);
	fore(i,0,n){
		if(s1<=s2){
			s1+=a[ids[l]];
			cout<<a[ids[l++]]<<" ";
		}
		else{
			s2+=a[ids2[r]];
			cout<<a[ids2[r++]]<<" ";
		}
	}
	cout<<"\n";
	return 0;
}