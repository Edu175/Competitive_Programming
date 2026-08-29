#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vv> mat;
typedef array<ll,3> Top; // i,j,wh

map<mat,vector<Top>> dp;
mat get_op(ll k){ // k in [1,4]
	mat ret(2,vv(2,1));
	fore(i,0,2)fore(j,0,2)if((--k)==0)ret[i][j]=0;
	return ret;
}
void precalc(ll n, ll m){
	ll cant=(n-1)*(m-1);
	ll old=SZ(dp);
	// ll pot5=1; fore(_,0,cant)pot5*=5;
	// cerr<<"precalc "<<n<<" "<<m<<"\n";
	fore(mk,0,1ll<<(4*cant)){
		ll mkp=mk;
		mat a(n,vv(m));
		vector<Top> ops;
		fore(i,0,n-1)fore(j,0,m-1)fore(wh,1,5){
			ll is=mkp%2; mkp/=2;
			if(!is)continue;
			ops.pb({i,j,wh});
			auto op=get_op(wh);
			fore(i2,0,2)fore(j2,0,2)a[i+i2][j+j2]^=op[i2][j2];
		}
		if(!dp.count(a)||SZ(ops)<SZ(dp[a]))dp[a]=ops;
	}
	ll nue=SZ(dp)-old;
	// cerr<<"nue "<<nue<<"\n";
	assert(nue==(1ll<<(n*m))); // puedo hacer toda grilla de n*m
}

int main(){
    JET
	fore(n,2,4)fore(m,2,4)precalc(n,m);
	for(auto [a,b]:dp){
		ll n=SZ(a),m=SZ(a[0]);
		assert(SZ(b)<=n*m);
	}
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		mat a(n,vv(m));
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			a[i][j]=c-'0';
		}
		vv rs(n/2,2),cs(m/2,2);
		if(n&1)rs.back()=3;
		if(m&1)cs.back()=3;
		auto ors=rs;
		auto ocs=cs;
		fore(i,1,SZ(ors))ors[i]+=ors[i-1];
		fore(j,1,SZ(ocs))ocs[j]+=ocs[j-1];
		ors.insert(ors.begin(),0);
		ocs.insert(ocs.begin(),0);
		vector<Top> ops;
		fore(id_i,0,SZ(rs))fore(id_j,0,SZ(cs)){
			ll zi=rs[id_i],i0=ors[id_i];
			ll zj=cs[id_j],j0=ocs[id_j];
			mat bl(zi,vv(zj));
			fore(i,0,zi)fore(j,0,zj)bl[i][j]=a[i0+i][j0+j];
			auto got=dp[bl];
			assert(SZ(got)<=zi*zj);
			for(auto op:got){
				op[0]+=i0;
				op[1]+=j0;
				ops.pb(op);
			}
			// cerr<<"["<<i0<<","<<i0+zi<<") ["<<j0<<","<<j0+zj<<"):\n";
			// fore(i,0,zi){
			// 	fore(j,0,zj)cout<<bl[i][j];
			// 	cout<<"\n";
			// }
			// for(auto [i,j,wh]:got)cout<<i<<","<<j<<" "<<wh<<"\n";
			// cout<<"\n";
		}
		assert(SZ(ops)<=n*m);
		cout<<SZ(ops)<<"\n";
		for(auto [i,j,wh]:ops){
			auto op=get_op(wh);
			vector<ii> all;
			fore(i2,0,2)fore(j2,0,2)if(op[i2][j2])
				all.pb({i+i2,j+j2});
			for(auto [x,y]:all){
				cout<<x+1<<" "<<y+1<<" ";
				a[x][y]^=1;
			}
			cout<<"\n";
		}
		// fore(i,0,n){
		// 	fore(j,0,m)cout<<a[i][j];
		// 	cout<<"\n";
		// }
		// cout<<endl;
		fore(i,0,n)fore(j,0,m)assert(!a[i][j]);
	}
    return 0;
}
