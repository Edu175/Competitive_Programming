#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll V=2.5e5+5;
typedef bitset<V> mask;
const ll B=9000;

int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n),c(n);
	mask P;
	vector<vv> pos(n);
	fore(i,0,n){
		cin>>a[i]>>c[i];
		c[i]--;
		pos[c[i]].pb(i);
		p[a[]]
	}
	vector<mask> all(V);
	ll small=0,big=0;
	fore(c,0,n){
		auto &vec=pos[c];
		if(!SZ(vec))continue;
		if(SZ(vec)<B){
			small++;
			fore(id0,0,SZ(vec))fore(id1,id0+1,SZ(vec)){
				ll i=vec[id0],j=vec[id1];
				if(a[i]>a[j])swap(i,j);
				all[a[j]]
			}
		}
		else {
			big++;
			
		}
	}
	cerr<<"small "<<small<<"\n";
	cerr<<"big "<<big<<"\n";
	fore(wh,1,z){
		auto &tot=tots[wh];
		auto m=ms[wh];
		vv P(V);
		fore(i,1,m)P[a[i-1]]++;

		// fore(d,0,28)cout<<tot[d]<<" ";;cout<<"\n";

		fore(c,0,n)if(SZ(pos[c])){
			auto &vec=pos[c];
			if(is[c]){
				vv p(V);
				for(auto i:vec){
					if(i+1>=m)break;
					p[a[i]]++;
				}
				auto re=calcDist(p,bc[c]);
				// cout<<"resto big "<<c<<": ";
				// fore(d,0,28)cout<<re[d]<<" ";;cout<<"\n";
				
				fore(i,0,V)tot[i]-=re[i];
			}
			else {
				fore(id0,0,SZ(vec)){
					if(vec[id0]+1>=m)break;
					fore(id1,0,SZ(vec)){
						ll i=vec[id0],j=vec[id1];
						ll d=a[j]-a[i];
						if(d<=0)continue;
						// cerr<<"resto small "<<c<<": "<<i<<" "<<j<<": "<<d<<"\n";
						tot[d]--;
					}
				}
			}
		}
		// fore(d,0,28)cout<<tot[d]<<" ";;cout<<"\n";
		// cout<<"\n";
	}
	
	while(q--){
		ll d; cin>>d;
		ll res=0;
		fore(wh,1,z){
			if(tots[wh][d]){
				res=ms[wh];
				break;
			}
		}
		double ans=res/2.;
		cout<<ans<<"\n";
	}
	
	return 0;
}