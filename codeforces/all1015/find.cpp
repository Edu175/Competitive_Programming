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
const ll MOD=1e9+7,MAXF=1e6+5;
random_device rd;
mt19937 rng(rd());

bool is(ll n){
	for(ll i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}
ll cnt(ll n){return __builtin_ctzll(n);}
int main(){FIN;
	ll l,r; cin>>l>>r;
	ll f=13;
	fore(i,l,r){
		if(is(i)&&cnt(i-1)>=f){
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
