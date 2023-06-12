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
const ll MAXN=3e5+5;

vector<ll>divs[MAXN];
void divisores(){
	fore(i,2,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
vector<ll>pf[MAXN];
void prime_factors(){
	fore(i,2,MAXN)if(!SZ(pf[i]))for(int j=i;j<MAXN;j+=i)pf[j].pb(i);
}
ll c[MAXN],p[MAXN][40];
vector<ll>sp[MAXN];
int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	prime_factors();
	sort(a,a+n);
	/*imp(a);
	fore(i,0,10){cout<<i<<": "; imp(pf[i]);}*/
	fore(i,0,n){
		fore(mk,1,1ll<<(SZ(pf[a[i]]))){
			ll q=1;
			fore(j,0,SZ(pf[a[i]]))if(mk&(1ll<<j))q*=pf[a[i]][j];
			p[i][mk]=c[q];
			if(!SZ(sp[q]))sp[q].pb(0);
			sp[q].pb(i+sp[q][SZ(sp[q])-1]),c[q]++;
		}
	}
	/*fore(i,0,MAXN)if(c[i]){
		cout<<i<<": "<<c[i]<<" | "; imp(sp[i]);
	}*/
	//cout<<"\n";
	ll res=0;
	fore(i,0,n){
		//cout<<a[i]<<"("<<i<<"):\n";
		fore(mk,1,1ll<<(SZ(pf[a[i]]))){
			ll q=1,pos=p[i][mk];
			fore(j,0,SZ(pf[a[i]]))if(mk&(1ll<<j))q*=pf[a[i]][j];
			ll cnt=__builtin_popcount(mk);
			ll add=((cnt&1)?1:-1)*(sp[q][c[q]]-sp[q][pos+1]-(i+1)*(c[q]-(pos+1)));
			res+=add;
			//cout<<"\t"<<mk<<" "<<q<<"("<<pos<<") "<<add<<"\n";
		}
	}
	//cout<<res<<"\n";
	cout<<(n*(n-1)*(n-2))/6-res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
