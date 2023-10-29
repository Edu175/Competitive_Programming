#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	ll res=1,v=(s[0]!='?');
	fore(i,1,n){
		if(s[i]=='?')res=(res*i)%MOD;
	}
	cout<<v*res<<"\n";
	while(q--){
		ll k; cin>>k; k--;
		char c; cin>>c;
		if(!k)v=(c!='?'),s[k]=c;
		else{
			if(s[k]=='?')res=res*fpow(k,MOD-2)%MOD;
			s[k]=c;
			if(s[k]=='?')res=res*k%MOD;
		}
		cout<<res*v<<"\n";
	}
	return 0;
}
