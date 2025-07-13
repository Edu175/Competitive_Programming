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
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		vv sp(n+1);
		vector<vector<ii>> pos(n);
		fore(i,0,n){
			pos[a[i]].pb({i,0});
			pos[b[i]].pb({i,1});
			if(i&1)swap(a[i],b[i]);
			sp[i+1]=sp[i]+a[i]==b[i];
		}
		auto get=[&](ll p, ll q, ll same)->ll{
			if(p==q)return p+1+sp[n]-sp[q+1];
			ll cant=sp[q]-sp[p+1];
			ll dif=q-p-1;
			dif-=cant,same^=cant&1;
			if(dif==0&&same){
				if(!cant)return 0;
				cant--,dif++,same^=1;
			}
			return p+1+sp[n]-sp[q+1]+cant;
		};
		
	}
	return 0;
}
