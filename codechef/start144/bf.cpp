#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),pos(n);
		fore(i,0,n)cin>>a[i];//,a[i]--,pos[a[i]]=i;
		auto get=[&](ll n){
			vector<ll>ret;
			// cout<<"go "<<n<<"\n";
			auto rec=[&](ll l, ll r, auto &&rec){
				// cout<<"rec "<<l<<","<<r<<"\n";
				if(l<0&&r>=n)return;
				ll go=0;
				if(l<0)go=1;
				else if(r>=n)go=0;
				else go=a[r]<a[l];
				ret.pb(a[go?r:l]);
				if(go)r++;
				else l--;
				rec(l,r,rec);
			};
			ll mn=0;
			fore(i,0,n)if(a[i]<a[mn])mn=i;
			ret.pb(a[mn]);
			rec(mn-1,mn+1,rec);
			// imp(ret);
			return ret;
		};
		vector<pair<vector<ll>,ll>>h;
		fore(i,0,n)h.pb({get(i+1),i+1});
		sort(ALL(h));
		for(auto &i:h){
			cout<<i.snd<<": ";
			imp(i.fst);
		}
		cout<<"\n";
	}
	return 0;
}
