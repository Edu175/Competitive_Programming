#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll V=1ll<<31;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		set<ll> st;
		while(SZ(st)<n-2){
			ll v=rng()%(V-5)+5;
			st.insert(v);
		}
		ll x=0;
		for(auto i:st)x^=i;
		if(st.count(x))st.erase(x);
		else st.insert(x);
		if(SZ(st)==n-3){
			fore(v,1,4)st.insert(v);
		}
		else st.insert(0);
		for(auto i:st)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}