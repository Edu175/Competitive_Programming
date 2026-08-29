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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vv pos(2,-1);
		fore(i,0,SZ(s)){
			ll ty=s[i]-'0';
			if(pos[ty]==-1)pos[ty]=i;
		}
		set<ll> ban={pos[0],pos[1]};
		string ret;
		fore(i,0,SZ(s))if(!ban.count(i))ret.pb(s[i]);
		cout<<ret<<"\n";
	}
	return 0;
}
