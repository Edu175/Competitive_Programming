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
const ll MOD=1e9+7;
#define bint __int128

struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint>h,pi;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(SZ(s)+1);pi.resize(SZ(s)+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	ll a[m];
	fore(i,0,m)cin>>a[i],a[i]--;
	Hash h(s);
	ll e=n;
	if(m)e=a[0]+n-(a[m-1]+SZ(s));
	ll flag=1;
	fore(i,1,m){
		if(a[i]-(a[i-1]+SZ(s))>=0)e+=a[i]-(a[i-1]+SZ(s));
		else if(h.get(a[i]-a[i-1],SZ(s))!=h.get(0,a[i-1]+SZ(s)-a[i]))flag=0;
	}
	ll res=0;
	if(flag){
		res=1;
		fore(i,0,e){
			res=res*26%MOD;
		}
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
