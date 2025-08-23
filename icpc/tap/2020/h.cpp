#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll n,k;
ll w[60];
ll dp[60][60][2];
ll dig;
ll f(ll d, ll c, bool b){
	if(d<0) return c==k;
	ll &r=dp[d][c][b];
	if(r!=-1) return r;
	r=0;
	fore(i,0,(b?((dig>>d)&1ll)+1:2)){
		r+=f(d-1,c+i,b&&i==((dig>>d)&1));
	} 
	return r;
}
ll cnt(ll x){
	mset(dp,-1);
	dig=x;
	return f(__lg(x),0,1);
}
ll calc(ll x){
	ll l=0, r=1ll<<n;
	while(l<=r){
		ll m=(l+r)>>1;
		ll k=0;
		fore(i,0,n) if(m&(1ll<<i)) k+=w[i];
		if(k<x) l=m+1;
		else r=m-1; 
	}
	return cnt(r);
}
int main(){
	JET
	cin>>n>>k;
	fore(i,0,n) cin>>w[i];
	sort(w,w+n);
	ll l,r; cin>>l>>r; r++;
	cout<<calc(r)-calc(l)<<"\n";	
	return 0;
}