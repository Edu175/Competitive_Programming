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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

int main(){FIN;
	ll B; cin>>B;
	vector<ll>a(1<<B);
	ll n=0;
	fore(i,0,1<<B){
		fore(j,0,16/(1<<B)){
			ll x; cin>>x;
			a[i]+=x;
		}
		n+=a[i];
	}
	imp(a);
	ll res=0;
	fore(mk,0,1ll<<(n+B-1)){
		vector<ll> h(1<<B);
		fore(i,0,n)h[(mk>>i)&((1<<B)-1)]++;
		res+=h==a;
		//cout<<mk<<": "<<h<<"\n";
		if(h==a)cout<<mk<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
