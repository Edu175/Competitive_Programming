#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=45;
ll n;

// ll is[MAXN]; // is free
string s(MAXN,'.');
vv is;
bool good(ll n){
	ll cant=0;
	fore(i,0,n){
		cant+=is[i];
		if(2*cant<i+1)return 0;
	}
	return 1;
}
vector<string> ans;
void f(ll i){ // llamo si es good
	if(i==n){
		ans.pb(s.substr(0,n));
		return;
	}
	auto doit=[&](char c){
		auto _is=is;
		s[i]=c;
		ll m=i+1;
		fore(k,1,m+5){
			ll p=m-2*k;
			if(p<0)break;
			is[p]&=s.substr(p,k)!=s.substr(p+k,k); // if tle do hashing
		}
		if(good(m))f(i+1);
		is=_is;
	};
	doit('0');
	doit('1');
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("free.in","r",stdin);
	freopen("free.out","w",stdout);
	#endif
	JET
	cin>>n;
	is=vv(n,1);
	f(0);
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}