#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	

const ll MAXN=2e5+5;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	vector<vector<vector<ll>>>pos(MAXN);
	fore(i,0,n){
		cin>>a[i];
		pos[a[i]].resize(2);
		pos[a[i]][i&1].pb(i);
	}
	ll res=0;
	fore(i,0,n/*-(k+1)/2+1*/){
		ll l=max(i,k-1-i),r=min(i+k,n-(i-(n-k))); //[l,r)
		if(!(l<r))continue;
		vector<ll>&v=pos[a[i]][i&1];
		ll s=lower_bound(ALL(v),r)-v.begin();
		ll e=lower_bound(ALL(v),l)-v.begin();
		//cout<<i<<" "<<a[i]<<": "<<v<<" "<<l<<" "<<r<<": "<<s<<" "<<e<<" = "<<s-e<<"\n";
		res+=s-e;
	}
	//cout<<(k+1)/2*(n-k+1)<<" "<<res<<"\n";
	res=(k+1)/2*(n-k+1)-res;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
