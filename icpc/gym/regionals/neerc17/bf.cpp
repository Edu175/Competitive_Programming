#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll sq(ll a){return a*a;}
int main(){
    JET
	ll q; cin>>q;
	vector<array<ll,3>>qs(q);
	vector<ii>sa;
	fore(i,0,q){
		ll ty,x,y; cin>>ty>>x>>y;
		sa.pb({x,i});
		qs[i]={ty,x,y};
	}
	auto good=[&](ll i, ll j){ // j circulo
		assert(j<q);
		assert(qs[i][0]==2&&qs[j][0]==1);
		return sq(qs[i][1]-qs[j][1])+sq(qs[i][2]-qs[j][2]) < 
			sq(qs[j][2]);
	};
	vv vis(q);
	fore(i,0,q){
		auto [ty,x,y]=qs[i];
		if(ty==2){
			vv ans
			fore(j,0,i)if(!used)
		}
	}
	STree stNeg(vals);
	auto my_upd=[&](ll i, bool pongo){
		ll v=pongo?pos[i]:q; // NEUT
		st.upd(pos[i],v);
		stNeg.upd(pos[i],v);
	};
	fore(i,0,q){
		auto [ty,x,y]=qs[i];
		if(ty==1)my_upd(i,1);
		else {
			ll ans=-1;
			auto cand=[&](ll j){
				if(good(i,j))ans=j;
			};
			auto doit=[&](ll fg){
				vv volve;
				while(1){
					ll p=st.query
						((fg?pos[i]+1:0),(fg?st.n:pos[i]));
					if(p==st.NEUT)break;
					ll ip=sa[p].snd;
					ll bad=st.vals[p]<=(fg?-1:1)*qs[i][1];
					if(bad)break;
					cand(ip);
					my_upd(ip,0);
					volve.pb(ip);
				}
				for(auto i:volve)if(i!=ans)my_upd(i,1);
				volve.clear(); //
			};
			doit(0);
			if(ans==-1)doit(1);
			if(ans!=-1)ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}