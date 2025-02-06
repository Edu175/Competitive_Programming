#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll MAXN=1e6+10;
ll cr[MAXN];
void init(){
	fore(i,2,MAXN){if(!cr[i])for(ll j=i*i; j<MAXN; j+=i)cr[j]=i;}
}
vi fact(ll n){
	vi r;
	while(cr[n]){
		ll p=cr[n];
		r.pb({p,0});
		while(n%p==0){n/=p; r.back().snd++;}
	}
	if(n>1)r.pb({n,1});
	return r;
}
ll d(ll a, ll b){
	ll g=gcd(a,b);
	vi A=fact(a/g); vi B=fact(b/g);
	ll r=0;
	for(auto [p,q]:A) r+=q;
	for(auto [p,q]:B) r+=q;
	return r;
}
const ll INF=1e15;
int main(){
	init();
	ll n; cin>>n;
	ll a[n]; fore(i,0,n) cin>>a[i];
	fore(i,0,n){
		ll M=INF; ll r=INF;
		fore(j,0,n)if(j!=i){
			ll ds=d(a[i],a[j]);
			if(ds<=M){M=ds; r=min(r,j);}
		}
		cout<<r+1<<"\n";
	}
}