#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=305;

ll a[MAXN];
ll dp[MAXN][MAXN][2];

ll f(ll l, ll r, ll b){
	ll &res=dp[l][r][b];
	if(res!=-1)return res;
	if(l>=r)return res=0;
	if(b){ //tengo que pintar
		assert(a[l]==a[r-1]);
		res=f(l+1,r-1,0);
		fore(i,l+1,r-1)if(a[i]==a[l]){
			res=min(res,f(l,i+1,1)+f(i,r,1));
		}
	}
	else {
		res=r-l+5;
		fore(i,l,r){
			if(a[i]==a[l])res=min(res,1+f(l,i+1,1)+f(i+1,r,0));
			if(a[i]==a[r-1])res=min(res,1+f(l,i,0)+f(i,r,1));
		}
	}
//	cout<<l<<","<<r<<" "<<b<<": "<<res<<endl;
	return res;
}
vector<pair<ii,ll>>ans;
void build(ll l, ll r, ll b){
	ll &res=dp[l][r][b];
	if(l>=r)return;
	if(b){ //tengo que pintar
		assert(a[l]==a[r-1]);
		if(res==f(l+1,r-1,0)){build(l+1,r-1,0);return;}
		fore(i,l+1,r-1)if(a[i]==a[l]){
			if(res==f(l,i+1,1)+f(i,r,1)){
				build(l,i+1,1),build(i,r,1);
				return;
			}
		}
	}
	else {
		fore(i,l,r){
			if(a[i]==a[l]&&res==1+f(l,i+1,1)+f(i+1,r,0)){
				ans.pb({{l,i+1},a[l]});
				build(l,i+1,1),build(i+1,r,0);
				return;
			}
			if(a[i]==a[r-1]&&res==1+f(l,i,0)+f(i,r,1)){
				ans.pb({{i,r},a[r-1]});
				build(l,i,0),build(i,r,1);
				return;
			}
		}
	}
	assert(0);
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	ll res=f(0,n,0);
	build(0,n,0);
	assert(res==SZ(ans));
	cout<<res<<"\n";
	for(auto [i,c]:ans){
		cout<<i.fst+1<<" "<<i.snd<<" "<<c<<"\n";
	}
	return 0;
}
