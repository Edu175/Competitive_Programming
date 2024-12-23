#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;
vector<ll> divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}

int main(){FIN;
	divisores();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		fore(i,1,n+1){
			ll x; cin>>x;
			ll g=gcd(i,x);
			a[i-1]=x/g,b[i-1]=i/g;
		}
		vector<ll> v[n+1],qs[n+1];
		fore(i,0,n){
			for(auto d:divs[a[i]])v[d].pb(b[i]);
		}
		// imp(a) imp(b)
		LL res=0;
		fore(i,0,n){
			for(auto d:divs[a[i]])qs[b[i]].pb(d);
		}
		fore(d,1,n+1){
			auto &u=v[d];
			if(!SZ(u))continue;
			sort(ALL(u));
			// cout<<d<<" d:\n"; imp(u);
			auto &qu=qs[d];
			if(!SZ(qu))continue;
			sort(ALL(qu));
			vector<ll>k,h;
			ll q=1;
			fore(i,1,SZ(qu)){
				if(qu[i]==qu[i-1])q++;
				else k.pb(qu[i-1]),h.pb(q),q=1;
			}
			k.pb(qu[SZ(qu)-1]),h.pb(q),q=1;
			qu.clear();
			
			ll j=0;
			fore(i,0,SZ(u)){
				while(j<SZ(k)&&k[j]<u[i])j++;
				if(j<SZ(k)&&k[j]==u[i])res+=h[j];
			}
			// imp(k[d]) imp(h[d]) cout<<"\n";
			u.clear();
		}
		// cout<<res<<" -"<<endl;
		fore(i,0,n)if(b[i]==1)res--;
		// cout<<res<<" par"<<endl;
		assert(res%2==0);
		res/=2;
		cout<<res<<"\n";
		
	}
	return 0;
}
