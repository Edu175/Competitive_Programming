#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll unos(const string &a){return count(ALL(a),'1');}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll k=__lg(n)+1;
		vector<string> a(k);
		fore(i,0,k)cin>>a[i];
		sort(ALL(a),[&](const string &a, const string &b){
			return unos(a)>unos(b);
		});
		vv vis(n+1); vis[0]=1;
		ll good=1;
		fore(i,0,n){
			ll x=0;
			fore(j,0,k)x|=ll(a[j][i]-'0')<<j;
			good&=x<=n&&!vis[x];
			if(x<=n)vis[x]=1;
		}
		if(!good){
			cout<<"0\n";
			continue;
		}
		ll res=1,q=0;
		fore(i,0,SZ(a)){
			q++;
			res*=q;
			if(i==SZ(a)-1||unos(a[i])!=unos(a[i+1]))q=0;
		}
		cout<<res<<"\n";
	}
	return 0;
}
