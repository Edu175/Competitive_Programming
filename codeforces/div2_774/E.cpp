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
const ll MAXN=1e6+5;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}
bool can(ll k, ll n, ll r){
	ll p=1;
	fore(i,0,k){
		p*=r;
		if(p>n)return 0;
	}
	return p<=n;
}
ll root(ll k, ll n){
	if(k>log2(n))return 1;
	ll l=2,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(k,n,m))l=m+1;
		else r=m-1;
	}
	return r;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	init_sieve();
	/*cout<<root(n,m)<<"\n";
	cout<<fixed<<setprecision(15)<<pow(m,1.0/n)<<"\n";
	return 0;*/
	ll res=n;
	fore(j,2,m+1){
		ll d=cr[j];
		if(d==-1)d=j;
		res+=n-root(d,n);
		//res+=n-ll(pow(n,1.0/d));
		//cout<<j<<": "<<d<<" "<<root(d,n)<<" = "<<n-root(d,n)<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
