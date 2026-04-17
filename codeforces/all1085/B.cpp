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
	ll t; cin>>t;
	while(t--){
		ll n,m,l; cin>>n>>m>>l;
		vv a(n),is(l);
		fore(i,0,n)cin>>a[i],a[i]--,is[a[i]]=1;
		vv b(m);
		ll q=n;
		fore(i,0,l){
			sort(ALL(b));
			reverse(ALL(b));
			b.resize(min((ll)SZ(b),q+1));
			b.back()++;
			sort(ALL(b));
			if(is[i])b.back()=0,q--;
		}
		sort(ALL(b));
		cout<<b.back()<<"\n";
	}
	return 0;
}
