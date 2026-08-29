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
ll subm(ll a, ll b){a-=b; return a<0?a+mod:a;}
ll mulm(ll a, ll b){return a*b%mod;}
ll fp(ll a, ll e){
	ll r=1;
	for(;e;e>>=1){
		if(e&1)r=mulm(r,a);
		a=mulm(a,a);
	}
	return r;
}

int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,k; cin>>n>>k; 
		ll g=gcd(n,k);
		ll a=subm(fp(2,n/g),2);
		ll L=mulm(g+1,fp(addm(a,1),g));
		ll R=mulm(mulm(a,g),fp(addm(a,1),g-1));
		cout<<subm(L,R)<<"\n";
	}
	return 0;
}