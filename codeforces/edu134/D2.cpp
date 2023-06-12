#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"| "
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll n;
ll a[MAXN], b[MAXN];
bool can(ll x){
	map<ll,ll>mp;
	fore(i,0,n)mp[b[i]&x]++;
	fore(i,0,n){
		ll xored=(a[i]&x)^x;
		if(!mp[xored])return 0;
		mp[xored]--;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll bit=32;
		ll res=0;
		while(bit>=0){
			ll m=res+(1ll<<bit);
			if(can(m))res=m;
			bit--;
		}
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
