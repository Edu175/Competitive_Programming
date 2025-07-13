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

bool good(ii a, ii b, ii c){
	// vertical todos
	ll ve=1;
	ll h=a.fst+b.fst+c.fst,w=a.snd;
	ve&=w==b.snd&&w==c.snd;
	ve&=h==w;
	// el otro
	w=a.snd,h=a.fst+b.fst;
	ll otr=c.fst==b.fst;
	otr&=b.snd+c.snd==w;
	otr&=h==w;
	return ve||otr;
}
void sw(ii &a){swap(a.fst,a.snd);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ii a,b,c; cin>>a.fst>>a.snd>>b.fst>>b.snd>>c.fst>>c.snd;
		ll res=good(a,b,c);
		sw(a);
		sw(b);
		sw(c);
		res|=good(a,b,c);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
