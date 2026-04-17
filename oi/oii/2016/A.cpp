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
typedef int ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n; n/=2;
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<ll>es(n);
	fore(i,0,n){
		ll x; cin>>x; x--;
		es[x]=i,x=i;
	}
	fore(i,0,n)a[i]=es[a[i]];
	es.clear();
	ll res=0;
	STree st(n);
	fore(i,0,n){
		st.upd(a[i],1);
		res+=st.query(a[i]+1,n);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
