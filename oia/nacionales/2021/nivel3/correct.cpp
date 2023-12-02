#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll c,m; cin>>c>>m;
	vector<ii> a(m);
	fore(i,0,m){
		ll l,r; cin>>l>>r;
		a[i]={l,r};
	}
	vector<ll> us(m);
	vector<ii>ev;
	fore(i,0,m){
		cin>>us[i];
		if(us[i]){
			ev.pb({a[i].fst,1});
			ev.pb({a[i].snd,-1});
		}
	}
	ll flag=1;
	sort(ALL(ev));
	ll k=0;
	for(auto [i,s]:ev){
		k+=s;
		if(k>c)flag=0;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}
