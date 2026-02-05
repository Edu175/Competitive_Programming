#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("adjustment.in","r",stdin);     freopen("adjustment.out","w",stdout);
	#endif
	ll n,q; cin>>n>>q;
	ll cols = n*(n+1)/2;
	ll rows = cols;
	set<ll> r,c;
	fore(i,1,n+1) r.insert(i),c.insert(i);
	while(q--){
		char k; ll x; cin>>k>>x;
		if(!(k=='R'?r:c).count(x)){
			cout<<0<<"\n";
			continue;
		}
		if(k == 'R'){
			cout<<cols + x*SZ(c)<<"\n";
			rows -= x;
			r.erase(x);
		}
		else{
			cout<<rows + x*SZ(r)<<"\n";
			cols-=x;
			c.erase(x);
		}
	}
	return 0;
}