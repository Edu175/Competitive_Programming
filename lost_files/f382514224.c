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
#define bint __int128

bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
struct Hash{
	vector<ll>pi,h,pt;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1),pt.resize(SZ(s)+1);
		pi[0]=PI; h[0]=0, pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(p*s[i-1]+h[i-1])%MOD;
			pi[i]=pi[i-1]*PI%MOD;
			p=p*P%MOD;
			pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		return (h[e]-h[s]+MOD)%MOD*pi[s]%MOD;
	}
};
ll add(ll a, ll b){
	ll ret=a+b;
	if(ret>=MOD)return ret-MOD;
	return ret;
}
int main(){FIN;
	string s; cin>>s; ll n=SZ(s);
	Hash h(s);
	vector<ll>res;
	fore(i,1,n+1){
		bint a=h.get(0,i),r=n-n%i, b=h.get(0,r);
		ll flag=(h.get(0,n-r)==h.get(r,n));
		ll p=0;
		for(ll j=0;j+i<=n;j+=i)p=add(p,h.pt[j]);
		if(a*p%MOD!=b)flag=0;
		if(flag)res.pb(i);
	}
	imp(res);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

