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
const ll MAXN=2e5+5;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	
ll l,r,n;
ll a[MAXN];
vector<ll>b;
ll check(vector<ll>&v){
	vector<ll>mk(n,0); fore(i,0,n)mk.pb(1);
	ll ret=1;
	do{
		ll s=0,p=1;
		fore(i,0,2*n){
			if(mk[i])s+=v[i];
			else p*=v[i];
		}
		if(s!=p)ret=0;
	}
	while(next_permutation(ALL(mk)));
	return ret;
}
vector<pair<ll,vector<ll>>>ans;
void f(ll p){
	if(p==2*n){
		//cout<<b<<"\n";
		if(check(b)){
			ll d=0;
			fore(i,0,2*n)d+=abs(a[i]-b[i]);
			ans.pb({d,b});
		}
		return;
	}
	fore(i,l,r+1)b[p]=i,f(p+1);
}
int main(){FIN;
	cin>>n;
	fore(i,0,2*n)cin>>a[i];
	ll mini=a[0],maxi=a[0];
	ll res; cin>>res;
	fore(i,0,2*n)maxi=max(maxi,a[i]),mini=min(mini,a[i]);
	l=mini,r=maxi;
	b.resize(2*n);
	f(0);
	sort(ALL(ans));
	for(auto i:ans){
		cout<<i.fst<<": "<<i.snd<<"\n";
	}
	/*vector<ll>db(4,2);
	cout<<check(db)<<"\n";*/
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
