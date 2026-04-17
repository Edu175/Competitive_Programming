#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		multiset<ll>st;
		fore(i,l,r)st.insert(a[i]);
		ll mx=0,res=0;
		fore(i,l,r){
			// cout<<i<<": "<<a[i]<<endl;imp(st);
			mx=max(mx,a[i]);
			st.erase(st.find(a[i]));
			if((!SZ(st)||mx<=*st.begin()))res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}