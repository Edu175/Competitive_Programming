#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v){for(auto i:v) cout << (i==INF?"INF":to_string(i)) << " ";cout << "\n";}
#define impr(v){for(auto i:v) cout << i.fst<<","<<i.snd << " ";cout << "\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1005,INF=1e14;

void expand(vv &a){ // mantain necessary info for even queries
	// convolution, /2
	ll n=SZ(a);
	vv b(2*n-1,0);
	fore(i,0,n)fore(j,0,n)b[i+j]=max(b[i+j],a[i]+a[j]);
	fore(i,0,n)a[i]=b[2*i];
}

int main(){FIN;
	ll n,s; cin>>n>>s;
	vv a(MAXV,0);
	a[0]=0;
	fore(i,0,n){
		ll v,c; cin>>v>>c;
		a[v]=max(a[v],c);
	}
	vector<ii> qs={{s,0}};
	ll res=INF;
	while(1){
		// imp(a);
		// impr(qs);
		// cout<<"\n"; // era max xd
		if((SZ(qs)==1&&qs[0].fst==0))break;
		vector<ii> b;
		for(auto [i,c]:qs){
			if(i&1){
				fore(j,0,SZ(a))if((j&1)&&j<=i)b.pb({i-j,c+a[j]});
			}
			else b.pb({i,c});
		}
		sort(ALL(b));
		qs.clear();
		for(auto i:b){
			assert(i.fst%2==0);
			i.fst/=2;
			if(SZ(qs)&&qs.back().fst==i.fst)qs.pop_back();
			qs.pb(i);
		}
		expand(a);
	}
	res=qs[0].snd;
	cout<<res<<"\n";
	return 0;
}
