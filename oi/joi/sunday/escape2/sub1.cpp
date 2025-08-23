#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=17;

ll F[K][MAXN],D[MAXN];
map<ii,ll>mp;
ii amp[MAXN];
ll cv(ii a){return mp[a];}
ii cv(ll a){return amp[a];}
int main(){FIN;
	ll n,t; cin>>n>>t;
	vector<ii>a(n);
	fore(i,0,n-1){
		ll m; cin>>m;
		assert(m==1);
		cin>>a[i].fst>>a[i].snd;
	}
	vector<ll>c(n);
	fore(i,0,n-1){
		c[i]=(a[i+1].fst-a[i].snd+t)%t;
	}
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--,e--;
		ll res=0;
		fore(i,s,e){
			if(i+1<e)res+=c[i];
			res+=a[i].snd-a[i].fst;
		}
		cout<<res<<"\n";
	}
	return 0;
}
