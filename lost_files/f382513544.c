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
const ll MAXN=1e7,MXN=1e12;

vector<ll>pr;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0){
		pr.pb(i);
		for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
	}
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}
int main(){//FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll p=0,q=0;
		for(ll i=0;pr[i]<MAXN;i++){
			if((n%pr[i])==0){
				if(n%(pr[i]*pr[i])==0)p=pr[i],q=n/(pr[i]*pr[i]);//,cout<<"p\n";
				else q=pr[i],p=sqrt(n/q);//,cout<<"q\n";
				break;
			}
		}
		if(p||q){
			cout<<p<<" "<<q<<"\n";
			continue;
		}
		for(ll i=0;pr[i]*pr[i]<MXN;i++){
			if((n%(pr[i]*pr[i]))==0)p=pr[i],q=n/(pr[i]*pr[i]);
		}
		cout<<p<<" "<<q<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
