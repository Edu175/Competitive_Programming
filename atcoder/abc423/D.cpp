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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<array<ll,3>> h;
	priority_queue<ii> q;
	fore(i,0,n){
		ll a,b,c; cin>>a>>b>>c;
		h.pb({a,b,c});
	}
	ll cant=0,t=0;
	fore(i,0,n){
		auto [a,b,c]=h[i];
		t=max(t,a);
		while(SZ(q)&&(-q.top().fst<=t||cant+c>k)){
			cant-=q.top().snd;
			t=max(t,-q.top().fst);
			q.pop();
		}
		cout<<t<<"\n";
		cant+=c;
		q.push({-(t+b),c});
	}
	return 0;
}
