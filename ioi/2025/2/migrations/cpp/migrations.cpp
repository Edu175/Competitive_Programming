#include "migrations.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
void tle(bool b){
	if(!b){
		ll start=clock();
		while((clock()-start)<30*CLOCKS_PER_SEC);
		cerr<<"pinga\n";
	}
}
const ll MAXN=1e4+5;

ll fa[MAXN];
int lcadp[MAXN][MAXN];
ll D[MAXN];
ll lca(ll x, ll y){
	auto &res=lcadp[x][y];
	if(res!=-1)return res;
	if(x==y)return res=x;
	if(D[x]>D[y])swap(x,y);
	res=lca(x,fa[y]);
	// if(x<8&&y<8){
	// 	cerr<<"lca "<<x<<","<<y<<": "<<res<<"\n";
	// }
	return res;
}
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll u=0,v=0;
ll actU=1,actV=1;
ll last=0;
ll msg=0;
const ll B=5,M=19;
ll noinfo=0;
vv per={1,0,2,3,4};
ll getd(ll j){ // jesimo digito de msg
	if(noinfo)return 0;
	ll m=msg;
	fore(_,0,j)m/=B;
	return per[m%B];
}
void init(){
	// cerr<<"INIT!!!\n";
	mset(lcadp,-1);
	fa[0]=-1;
}

vector<ii>trad={{0,0},{1,0},{2,0},{0,1},{2,1}}; // no 1,1
int send_message(int N, int i, int Pi) {
	if(i==1)init();
	D[i]=D[Pi]+1;
	fa[i]=Pi;
	
	ll nu=u,nv=v,did=0;
	if(dis(u,i)>dis(u,v))nv=i,did=1;
	else if(dis(i,v)>dis(u,v))nu=i,did=1;
	
	// if(did){
	// 	cerr<<u<<" "<<v<<": "<<nu<<" "<<nv<<"\n";
	// }
	
	actU|=u!=nu; u=nu;
	actV|=v!=nv; v=nv;
	
	ll n=N;
	
	ll s=n-M;
	set<ll> chU={s,  s+12,s+16};
	set<ll> chV={s+6,s+14,s+17};
	
	if(chU.count(i)){
		if(actU)msg=i+1-u;
		else msg=0;
		actU=0; last=i;
	}
	if(chV.count(i)){
		if(actV)msg=i+1-v;
		else msg=0;
		actV=0; last=i;
	}
	if(i<s)return 0;
	
	if(i<n-1)return getd(i-last);
	
	ll msgU=0;
	if(actU)msgU=i+1-u;
	
	ll msgV=0;
	if(actV)msgV=i+1-v;
	
	ll pos=find(ALL(trad),ii({msgU,msgV}))-trad.begin();
	tle(pos<SZ(trad));
	return pos;
}



pair<int, int> longest_path(vector<int> S) {
	ll n=SZ(S);
	
	auto get=[&](vector<ii> rans, ll ult){
		vv msgs;
		vv ind;
		auto add=[&](ll s, ll e){
			ll msg=0;
			ind.pb(s);
			ll pot=1;
			fore(i,s,e)msg+=S[i]*pot,pot*=B;
			msgs.pb(msg);
		};
		for(auto [s,e]:rans)add(s,e);
		msgs.pb(ult);
		ind.pb(n-1);
		ll res=0;
		fore(i,0,SZ(msgs)){
			ll msg=msgs[i];
			if(msg)res=ind[i]-msg+1;
		}
		return res;
	};
	
	ll s=n-M;
	ii par=trad[S.back()];
	ll u=get({{s,s+6},{s+12,s+14},{s+16,s+17}},par.fst);
	ll v=get({{s+6,s+12},{s+14,s+16},{s+17,s+18}},par.snd);
	
	return {u,v};
}
