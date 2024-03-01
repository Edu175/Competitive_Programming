#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cerr<<edu<<" "; cerr<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll MAXN=19;
ll g[MAXN];
ll n;
ll ppc(ll x){return __builtin_popcountll(x);}
string bin(ll x){
	string s;
	while(x)s.pb('0'+x%2),x/=2;
	s+="b";
	reverse(ALL(s));
	return s;
}
ll bfs(ll x){
	ll rem=(1ll<<n)-1;
	set<ll>v={x};
	ll res=0;
	rem^=1ll<<x;
	cerr<<"bfs "<<x<<"\n";
	while(SZ(v)){
		cerr<<bin(rem)<<" ";
		imp(v);
		ll mx=*v.begin();
		for(auto x:v)if(ppc(g[x]&rem)>ppc(g[mx]&rem))mx=x;
		v.erase(mx);
		//rem^=1ll<<mx;
		cerr<<mx<<" mx ("<<ppc(g[mx]&rem)<<")\n";
		if(!ppc(g[mx]&rem))res++,cerr<<"hoja";
		fore(i,0,n)if(((g[mx]&rem)>>i)&1){
			v.insert(i);
			rem^=1ll<<i;
			cerr<<i<<" ";
		}
		cerr<<"\n";
	}
	cerr<<"end bfs "<<res<<"\n\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i]=0;
		fore(i,0,n)fore(j,0,n){
			char c; cin>>c;
			if(c=='1'){
				g[i]|=1ll<<j;
				if(i<j)cout<<i<<" "<<j<<"\n";
			}
		}
		ll mx=0;
		fore(i,0,n)mx=max(mx,bfs(i));
		//cerr<<mx<<"\n";
		cout<<n-1-mx<<"\n";
	}
	return 0;
}
