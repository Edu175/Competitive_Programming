#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
// ll cant=0;
ll f(vector<ii> a){ // estan even
	// if(++cant>200)exit(0);
	// cerr<<"f "; impr(a)
	if(!SZ(a)){
		// cerr<<"end vacio\n";
		return 0;
	}
	set<ll> rs;
	for(auto i:a)rs.insert(i.fst%6);
	if(SZ(rs)>1){
		// cerr<<"end invalid\n";
		return INF;
	}
	ll _r=*rs.begin(); _r=(6-_r)%6;
	for(auto &i:a)i.fst=(i.fst+_r)/6;
	
	// cerr<<"parcial "; impr(a)
	
	// 1 ahead in 6
	ll res=INF;
	fore(r,0,7){
		// cerr<<"VAMOS CON "<<r<<" ===\n";
		vector<ii> b;
		for(auto i:a){
			i.fst+=r;
			if(i.fst%7==0)b.pb({i.fst/7,i.snd});
		}
		if(res<r)break;
		ll got=f(b);
		if(got<INF)got=((got*7)+r)*6+_r;
		res=min(res,got);
	}
	// cerr<<"end\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<ii> b(n);
		fore(i,0,n)cin>>a[i],b[i]={a[i],i};
		ll res=f(b);
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
