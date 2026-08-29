#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)
const ll LG=24;

vv sos(ll k, vv a){
	fore(j,0,k)fore(mk,0,1ll<<k){
		if(mk>>j&1)addig(a[mk],a[mk^(1ll<<j)]);
	}
	return a;
}
void neg(vv &a){
	vv b(SZ(a));
	ll all=SZ(a)-1;
	fore(i,0,SZ(a))b[i^all]=a[i];
	a=b;
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	ll D=n+m-1;
	vv zs(D);
	vector<vector<ii>> pos(D); 
	fore(i,0,n)fore(j,0,m){
		zs[i+j]++;
		pos[i+j].pb({i,j});
	}
	fore(d,0,D)reverse(ALL(pos[d]));
	ll res=0;
	fore(_,0,1){
		vector<vv> dps(2);
		for(ll d=D-1;d>=0;d--){
			ll w=d&1;
			auto &me=dps[w];
			ll z=zs[d];
			me=vv(1ll<<z);
			if(d==D-1){
				fill(ALL(me),1);
				// cerr<<"dp "<<d<<": "; show(me)
				continue;
			}
			ll z2=zs[d+1];
			auto otr=dps[w^1];
			if(w==!_)neg(otr);
			vv sto=sos(z2,otr);
			fore(mk,0,SZ(me)){
				ll ped=0;
				fore(i,0,z-1)if((mk>>i&1)&&(mk>>(i+1)&1))ped|=1ll<<i;
				if(pos[d][0].fst+1<n){ // add pri
					ll pri=mk&1;
					ped=2*ped+pri;
				}
				if(pos[d].back().snd+1<m){ // add ult
					ll ult=mk>>(z-1)&1;
					ped|=(ult)<<(z2-1);
				}
				me[mk]=sto[ped];
			}
			if(w==!_)neg(me);
			// cerr<<"dp "<<d<<": "; show(me)
		}
		ll cur=add(dps[0][0],dps[0][1]);
		res=add(res,cur);
	}
	res=mul(res,2);
	cout<<res<<"\n";
	return 0;
}
