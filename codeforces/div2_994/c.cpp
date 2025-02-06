#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y; cin>>n>>x>>y; x--,y--;
		ll s=0,spn=-1,spv=-1;
		if(y-x==1||(x-y+n)%n==1){
			if(n&1)spn=n-1,spv=2;
		}
		else if(n&1){
			if(x%2!=y%2)s=x,spn=(x-1+n)%n,spv=2;
			else s=y,spn=(y-1+n)%n,spv=2;
		}
		else {
			if(x%2==y%2)spn=y,spv=2;
		}
		vv res(n,-1);
		for(ll i=s,c=0;res[i]==-1;i=(i+1)%n,c^=1)res[i]=c;
		if(spn!=-1)res[spn]=spv;
		imp(res);
	}
	return 0;
}
