#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=998244353;
const ll MAXN=2e5+5;
ll F[MAXN], Fi[MAXN];
ll addm(ll a, ll b){
	a+=b;
	return a<mod?a:a-mod;
}
ll subm(ll a, ll b){
	a-=b;
	return a<0?a+mod:a;
}
ll mulmod(ll a, ll b){
	return a*b%mod;
}
ll pm(ll a, ll n){
	if(!n) return 1ll;
	ll r=pm(a,n/2);
	if(n&1) return mulmod(r,mulmod(r,a));
	return mulmod(r,r);
}
//ll pot[MAXN];
int main(){
	JET
	F[0]=1ll; fore(i,1,MAXN) F[i]=mulmod(F[i-1],i);
	Fi[MAXN-1]=pm(F[MAXN-1],mod-2);
	fore(i,1,MAXN) Fi[MAXN-1-i]=mulmod(Fi[MAXN-i],(MAXN-i));
//	pot[0]=1ll; fore(i,1,MAXN) pot[i]=mulmod(pot[i-1],2);
	ll n,k; cin>>n>>k;
	ll res=1ll;
	ll s=1ll;
	
	fore(i,1,min(n,k)+1) {ll a=subm(mulmod(F[i],pm(i+1,k+1-i)),s);s=addm(a,s); res=addm(res,mulmod(a,mulmod(F[n],Fi[n-i])));}
	cout<<res<<"\n";
	return 0;
}
// no se que me crei antes
// ponga queso vamo jere ponga queso -titos quotes