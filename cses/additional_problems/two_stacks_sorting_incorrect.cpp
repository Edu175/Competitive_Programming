#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vv s[2]; s[0].pb(n+5),s[1].pb(n+5);
	vv ans(n);
	ll nxt=0;
	auto put=[&](ll w){
		if(s[w].back()==nxt){
			s[w].pop_back(),nxt++;
			return 1;
		}
		return 0;
	};
	auto fail=[&](){cout<<"IMPOSSIBLE\n";exit(0);};
	fore(i,0,n){
		while(put(0)||put(1));
		ll v=a[i],c=(v>s[0].back())+(v>s[1].back());
		ll sw=s[0].back()>s[1].back();
		if(c==2)fail();
		s[c^sw].pb(v);
		ans[i]=c^sw;
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}