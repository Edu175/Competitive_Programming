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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(2*n);
		vector<ll>pos[n];
		fore(i,0,n*2)cin>>a[i],a[i]--,pos[a[i]].pb(i);
		vector<ii>s;
		fore(i,0,n)s.pb({pos[i][0]-pos[i][1],i});
		sort(ALL(s));
		for(auto [sus,i]:s)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
