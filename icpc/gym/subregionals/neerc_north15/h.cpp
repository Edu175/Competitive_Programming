#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("hash.in","r",stdin);     freopen("hash.out","w",stdout);
	#endif
	ll n; cin>>n;
	vector<string> r;
	fore(mk,0,n){
		string s;
		fore(i,0,10){
			if(mk>>i&1)s+="ed";
			else s+="fE";
		}
		s+="Hs";
		r.pb(s);
	}
	for(auto i:r)cout<<i<<"\n";
	return 0;
}