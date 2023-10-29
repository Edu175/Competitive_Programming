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
	ll n,m; cin>>n; m=n/2;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ii> b;
	for(ll i=1;i<n;i+=2)b.pb({a[i],a[i+1]});
	vector<ll>sp(m+1);
	fore(i,1,m+1)sp[i]=sp[i-1]+b[i-1].snd-b[i-1].fst;
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r;
		ii p={l,-1};
		ll s=upper_bound(ALL(b),p)-b.begin()-1;
		p={r,-1};
		ll e=lower_bound(ALL(b),p)-b.begin()-1;
		if(e<0){
			cout<<"0\n";
			continue;
		}
		ll res=0;
		if(e>=0&&s+1<e)res=sp[e]-sp[s+1];
		if(s==e)l=max(l,b[s].fst),r=min(r,b[e].snd),res+=r-l;
		else{
			if(s>=0&&b[s].snd>l)res+=b[s].snd-l;
			if(b[e].snd>=r)res+=r-b[e].fst;
			else res+=b[e].snd-b[e].fst;
		}
		cout<<max((ll)0,res)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
