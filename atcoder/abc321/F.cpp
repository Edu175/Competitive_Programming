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
typedef pair<ll,ll> ii;
const ll MOD=998244353;

int main(){FIN;
	ll q,k; cin>>q>>k;
	vector<ll>a(k+1);
	a[0]=1;
	while(q--){
		char c; cin>>c;
		ll x; cin>>x;
		vector<ll>b(k+1);
		if(c=='+'){
			fore(i,0,k+1)if(i+x<=k)b[i+x]=a[i];
			fore(i,0,k+1)a[i]=(a[i]+b[i])%MOD;
		}
		else {
			fore(i,0,k+1){
				a[i]=(a[i]-b[i]+MOD)%MOD;
				if(i+x<=k)b[i+x]=a[i];
			}
		}
		cout<<a[k]<<"\n";
	}
	return 0;
}
