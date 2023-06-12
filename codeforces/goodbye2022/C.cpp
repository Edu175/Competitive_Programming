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
const ll MAXN=5005;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
}
int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		set<ll>st;
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		ll flag=1;
		if(SZ(st)<n)flag=0;
		fore(d,2,5000){
			if(cr[d]!=-1)continue;
			vector<ll>vis(d,0);
			fore(i,0,n){
				fore(j,i+1,n){
					if((a[i]%d)!=(a[j]%d))continue;
					ll no=(d-(a[i]%d))%d;
					//cout<<a[i]<<" "<<a[j]<<": "<<no<<"\n";
					vis[no]=1;
				}
			}
			ll fi=1;
			for(auto i:vis)if(!i)fi=0;
			if(fi)flag=0;//,cout<<d<<"\n";
			//break;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
