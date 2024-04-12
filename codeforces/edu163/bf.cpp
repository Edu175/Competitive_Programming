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
	ll n; cin>>n;
	ll res=2*n+5;
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	vector<vector<ll>> ks[res];
	do{
		ll k=0;
		fore(i,0,n)fore(j,i+1,n)k=max(k,j-i+abs(p[i]-p[j]));
		res=min(res,k);
		ks[k].pb(p);
	}
	while(next_permutation(ALL(p)));
	cout<<res<<"\n";
	cout<<"("<<SZ(ks[res])<<")\n";
	imp(ks[res]);
	return 0;
}
