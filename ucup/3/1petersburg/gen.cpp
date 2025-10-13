#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll S=1e9;

vv get(ll n){
	ll s=S-n;
	vv bar={0,s};
	fore(i,0,n-1)bar.pb(rng()%(s+1));
	sort(ALL(bar));
	vv a;
	fore(i,1,SZ(bar))a.pb(bar[i]-bar[i-1]+1);
	assert(SZ(a)==n&&accumulate(ALL(a),0ll)==S);
	return a;
}

int main(){FIN;
	ll N;  cin>>N;
	ll n=N;
	// ll n=rng()%N+1;
	cout<<2*n<<"\n";
	vv a=get(n);
	for(auto i:get(n))a.pb(i);
	shuffle(ALL(a),rng);
	for(auto i:a)cout<<i<<" ";;cout<<"\n";
	return 0;
}
