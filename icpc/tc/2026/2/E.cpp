#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll n,m; 
const int maxn = 4e5, maxm = 8;
ll a[maxn][maxm];

ll h[1<<maxm];

pair<bool,ii> can(ll k){
	mset(h,-1);
	fore(i,0,n){
		ll aux = 0;
		fore(j,0,m) if(a[i][j] >= k) aux|=(1<<j);
		h[aux] = i;
	}
	fore(i,0,1<<maxm) fore(j,0,1<<maxm){
		if(h[i]>= 0 && h[j] >=0 && (i|j) == (1<<m)-1){
			return {true,{h[i],h[j]}};
		}
	}
	return {false,{-1,-1}};
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n) fore(j,0,m) cin>>a[i][j];
	ll l = 0, r = 1e10;
	while(l<=r){
		ll k = (l+r)/2;
		if(can(k).fst) l = k+1;
		else r = k-1;
	}
	auto [b,p] = can(r);
	assert(b);
	if(p.fst > p.snd) swap(p.fst,p.snd);
	cout<<p.fst+1<<" "<<p.snd+1<<"\n";
	
	return 0;
}