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
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>oc(n);
		fore(i,0,n){
			ll x; cin>>x; x--;
			oc[x]++;
		}
		sort(ALL(oc));
		reverse(ALL(oc));
		ll sum=0,res=0;
		fore(i,0,n)if(oc[i]){
			sum+=oc[i];
			res=max(res,sum/(i+1)*(i+1));
		}
		cout<<res<<"\n";
	}
	return 0;
}
