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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fn(ll n){return n*(n+1)/2%MOD;}
ll n,res;
set<vv>st;
ll cnt(vv &a){
	ll inv=0;
	fore(i,0,SZ(a))fore(j,i+1,SZ(a))inv+=a[i]>a[j];
	return inv;
}
map<ii,vector<vv>>mp;
void f(vv a, ll bef){
	if(st.count(a))return;
	st.insert(a);
	ll inv=cnt(a);
	mp[{SZ(a),bef>=2?2:bef}].pb(a);
	if(SZ(a)==n){
		res++;
		imp(a);
		return;
	}
	fore(i,0,SZ(a)+1){
		auto ai=a;
		ai.insert(ai.begin()+i,inv);
		f(ai,inv);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		f({1,1,1,0},0);
		// for(auto [i,h]:mp){
		// 	cout<<i.fst<<","<<i.snd<<":\n";
		// 	for(auto v:h)imp(v);
		// 	cout<<"\n";
		// }
		cout<<res<<" res\n";
	}
	return 0;
}
