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
ll pot(ll n){
	map<int,int>f=fact(n);
	ll g=0;
	for(auto i:f){
		g=gcd(g,i.snd);
	}
	return g;
}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b;
		b=b*b,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	init_sieve();
	ll res=m-1;
	fore(g,2,log2(n)+1){
		vector<ll>u(m,0);
		ll c=0;
		for(ll j=2;fpow(j,g)<=n;j++)c+=(pot(fpow(j,g))==g);
		fore(e,2,g+1){
			if(g%e!=0)continue;
			fore(d,1,e){
				for(ll j=d,q=0;q<m/e;j+=d,q++)u[j]=1;
			}
		}
		/*cout<<g<<" "<<c<<": ";
		imp(u);*/
		ll resi=0;
		for(auto j:u)resi+=j;
		//cout<<c*resi<<"\n\n";
		res+=c*resi;
	}
	cout<<n*m-res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

