#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=5e6;

inline ll remtz(ll a){
	return a>>__builtin_ctz(a);
}
ll gcd_odd(ll a, ll b){
	while(a!=b){
		if(a<b)swap(a,b);
		a=remtz(a-b);
	}
	return a;
}
ll gcd(ll a, ll b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd_odd(remtz(a),remtz(b))<<min(__builtin_ctz(a),__builtin_ctz(b));
}

ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>b,v;
		for(ll i=n-1;i>=0;i--){
			vector<ll>vi={a[i]};
			for(auto m:v){
				m=lcm(m,a[i]);
				if(m>MAXV)break;
				if(m!=vi.back())vi.pb(m);
			}
			v=vi;
			for(auto m:v)b.pb(m);
		}
		vector<bool> vis(SZ(b)+5);
		for(auto i:b)if(i<SZ(vis))vis[i]=1;
		ll res=1;
		fore(i,1,SZ(vis))if(!vis[i]){res=i;break;}
		cout<<res<<"\n";
	}
	return 0;
}
