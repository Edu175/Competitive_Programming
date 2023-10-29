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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>l(k),r(k);
		fore(i,0,k)cin>>l[i],l[i]--;
		fore(i,0,k)cin>>r[i],r[i]--;
		ll j=0;
		vector<ll>to(n);
		fore(i,0,n){
			if(r[j]<i)j++;
			to[i]=r[j]-(i-l[j]);
		}
		//imp(to);
		vector<ii>ev;
		ll q; cin>>q;
		while(q--){
			ll x; cin>>x; x--;
			j=lower_bound(ALL(r),x)-r.begin();
			ll s=x,e=r[j]+l[j]-x;
			if(s>e)swap(s,e);
			e++;
			ev.pb({s,1});
			ev.pb({e,-1});
		}
		sort(ALL(ev));
		j=0;
		ll c=0;
		fore(i,0,n){
			while(j<SZ(ev)&&ev[j].fst<=i)c+=ev[j].snd,j++;
			if(i<to[i]&&(c&1))swap(s[i],s[to[i]]);
			//cout<<i<<" "<<c<<"\n";
		}
		cout<<s<<"\n";
	}
	return 0;
}
