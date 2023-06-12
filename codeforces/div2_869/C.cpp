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

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll id[n];
	vector<pair<ll,ll>>c;   //{l,r)
	ll l=0;
	fore(i,1,n){
		if(a[i]>a[i-1])c.pb({l,i}),l=i;
	}
	c.pb({l,n});
	/*for(auto i:c){
		cout<<i.fst<<","<<i.snd<<" ";
	}
	cout<<"\n";*/
	vector<ll>sp(SZ(c)+1);
	fore(i,1,SZ(c)+1)sp[i]=sp[i-1]+1+(c[i-1].snd-c[i-1].fst>1);
	while(q--){
		ll l,r; cin>>l>>r; l--,r--;
		if(l==r){
			cout<<"1\n";
			continue;
		}
		pair<ll,ll>f={l,n+1};
		ll s=lower_bound(ALL(c),f)-c.begin();
		s--;
		f={r,n+1};
		ll e=lower_bound(ALL(c),f)-c.begin();
		e--;
		//cout<<l<<" "<<r<<": "<<s<<" "<<e<<": ";
		ll res=sp[e+1]-sp[s];
		if(c[s].snd-c[s].fst>1&&c[s].snd-1==l)res--;
		if(c[e].snd-c[e].fst>1&&c[e].fst==r)res--;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
