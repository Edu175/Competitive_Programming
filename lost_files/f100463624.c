#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v){cout<<messi<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;

vector<ll> divs[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	fore(i,1,MAXN)for(ll j=i;j<MAXN;j+=i)divs[j].pb(i);
}

int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		map<ll,ll>c;
		ll a[n];
		fore(i,0,n)cin>>a[i],c[a[i]]++;
		ll res=0;
		fore(i,0,n){
			//cout<<i<<" "<<a[i]<<": ";
			for(auto d:divs[a[i]]){
				if(d==a[i]){
					res+=(c[a[i]]-1)*(c[a[i]]-2);
					continue;
				}
				ll b=a[i]/d;
				if(a[i]%(b*b)!=0)continue;
				res+=c[d]*c[a[i]/(b*b)];
				//cout<<"{ "<<d<<" "<<a[i]/(b*b)<<": "<<c[d]<<" "<<c[a[i]/(b*b)]<<" } ";
			}
			//cout<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
