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

ll par(ll p){
	if(p==0)return 0;
	ll pot=1ll<<(63-__builtin_clzll(p));
	return 1^par(p-pot);
}

int main(){FIN;
	string s; cin>>s;
	string t=s;
	for(auto &i:t){
		if('A'<=i&&i<='Z')i+='a'-'A';
		else i-='a'-'A';
	}
	auto get=[&](ll w, ll i){
		if(w)return t[i%SZ(t)];
		return s[i%(SZ(s))];
	};
	ll q; cin>>q;
	while(q--){
		ll p; cin>>p; p--;
		cout<<get(par(p/SZ(s)),p)<<" ";
	}
	cout<<"\n";
	return 0;
}
