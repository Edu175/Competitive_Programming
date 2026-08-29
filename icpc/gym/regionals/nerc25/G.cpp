#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
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
		map<char,vv> pos;
		fore(i,0,SZ(s))pos[s[i]].pb(i);
		ll res=0;
		for(auto [asd,v]:pos){
			res+=SZ(v)*(SZ(v)+1)/2;
			vv b;
			ll q=0;
			fore(i,0,SZ(v)){
				q++;
				if(i==SZ(v)-1||v[i]+1!=v[i+1])b.pb(q),q=0;
			}
			for(auto z:b){
				fore(c,1,z+1)res-=z-c;
			}
		}
		cout<<res+1<<"\n";
	}
	return 0;
}