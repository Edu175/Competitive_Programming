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
const ll K=18;

struct BL{
	ll n;
	vector<vv> F,V;
	BL(vector<ii> a):n(SZ(a)),F(K,vv(n+1)),V(K,vv(n+1)){
		a.pb({n,0}); // to,w
		fore(i,0,n+1)F[0][i]=a[i].fst,V[0][i]=a[i].snd;
		fore(k,1,K)fore(x,0,n+1){
			ll fa=F[k-1][x];
			F[k][x]=F[k-1][fa];
			V[k][x]=V[k-1][x]+V[k-1][fa];
		}
	}
	ii get(ll p, ll r){ // ult pos <p, weight
		ll val=0;
		for(ll k=K-1;k>=0;k--){
			if(F[k][p]<r){
				val+=V[k][p];
				p=F[k][p];
				// cout<<"salto "<<k<<"\n";
			}
		}
		return {p,val};
	}
	
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,z; cin>>n>>z; z++; // >=
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv to(n);
		fore(i,0,n){
			to[i]=lower_bound(ALL(a),a[i]+z)-a.begin();
		}
		// imp(to)
		vector<ii> ini(n);
		fore(i,0,n)ini[i]={to[i],1};
		BL sol(ini);
		ini.back()={n,0};
		auto cond0=[&](ll x, ll y){
			return x==y;
		};
		auto cond1=[&](ll x, ll y){
			return sol.F[0][x]==y;
		};
		fore(i,0,n-1){
			ll x=i,y=i+1,w=0;
			for(ll k=K-1;k>=0;k--){
				ll fax=sol.F[k][x];
				ll fay=sol.F[k][y];
				if(!cond0(fax,fay)&&!cond1(fax,fay)){
					w+=sol.V[k][x];
					w+=sol.V[k][y];
					x=fax;
					y=fay;
				}
			}
			assert(!cond0(x,y));
			if(!cond1(x,y)){
				ll fax=sol.F[0][x];
				ll fay=sol.F[0][y];
				w+=sol.V[0][x];
				w+=sol.V[0][y];
				x=fax;
				y=fay;
			}
			ll ta=y;
			if(!cond0(x,y)){
				assert(cond1(x,y));
				w++;
			}
			ini[i]={ta,w};
		}
		BL dob(ini);
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			if(r-l==1){
				cout<<"1\n";
				continue;
			}
			ll res=2;
			auto [x0,d0]=dob.get(l,r);
			res+=d0;
			auto [x1,d1]=sol.get(x0,r);
			res+=d1;
			auto [x2,d2]=sol.get(x0+1,r);
			res+=d2;
			if(x0==r-1){
			    assert(!d1&&!d2);
			    res--;
			}
			// cout<<x0<<" "<<x1<<" "<<x2<<"\n";
			// cout<<d0<<" "<<d1<<" "<<d2<<"\n";
			
			cout<<res<<"\n";
		}
	}
	return 0;
}
