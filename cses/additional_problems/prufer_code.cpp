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
	ll n; cin>>n;
	vector<ll>oc(n),a(n);
	fore(i,0,n-2)cin>>a[i],a[i]--,oc[a[i]]++;
	set<ll>h;
	fore(i,0,n)if(oc[i]==0)h.insert(i);
	vector<ii>ed;
	fore(i,0,n-2){
		ll x=*h.begin();
		ed.pb({x,a[i]});
		h.erase(x);
		oc[a[i]]--;
		if(oc[a[i]]==0)h.insert(a[i]);
	}
	assert(SZ(h)==2);
	ed.pb({*h.begin(),*next(h.begin())});
	for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
	return 0;
}
