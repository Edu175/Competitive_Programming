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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
const ll n=8;
bool allowed(ll i, ll j){
	return i>=0&&i<n&&j>=0&&j<n;
}

int dp[n][n][n][n][n][105][2];
// ll dbg=0;
int f(ll bi, ll bj, ll ni, ll nj, ll pi, ll pj, ll t, ll w){ // gana el player que le toca ?
	// t par => juega blanco
	auto &res=dp[bi][bj][ni][nj][pj][t][w];
	if(res!=-1)return res;
	// dbg|=bi==3&&ni==3&&pi==3&&nj==7&&pj==6&&bj==5;
	// if(dbg){
	// 	cerr<<bi<<","<<bj<<" "<<ni<<","<<nj<<" "<<pi<<","<<pj<<": "<<w<<" ?\n";
		
	// }
	ll reyes=bi==ni&&bj==nj;
	// if(reyes)return res=0; // primero que nada
	
	assert(!reyes);
	
	ll comePeon=pi==ni&&pj==nj;
	if(comePeon&&!w)return res=0; // gana el negro
	
	ll both=bi==pi&&bj==pj; // both blancos!
	if(both){assert(w);return res=1;} // invalid!
	
	if(pj==7&&!w)return res=1; // gana blanco
	if(t==100){
		assert(!comePeon);
		return res=w; // pierde blanco
	}
	// ahogado flawed
	// if(w&&nj==7&&ni==bi&&ni==pi&&pj==6&&bj==5)return res=1; // gana el negro
	
	if(!w){ // juega blanco
		
		// Peon
		// come al negro
		if(nj-pj==1&&abs(ni-pi)==1)return res=1;
		
		// para arriba
		if(nj-pj!=1||ni!=pi){ // si no se superpone con el negro
			if(!f(bi,bj,ni,nj,pi,pj+1,0,w^1))return res=1;
		}
		
		// dos para arriba
		if(pj==1&&(pi!=ni||(nj!=2&&nj!=3))){
			if(!f(bi,bj,ni,nj,pi,pj+2,0,w^1))return res=1;
		}
		
		// Rey
		fore(di,-1,2)fore(dj,-1,2){
			if(di==0&&dj==0)continue;
			ll bi_=bi+di;
			ll bj_=bj+dj;
			if(!allowed(bi_,bj_))continue;
			// if(bi_==pi&&bj_==pj)continue; // NO!! porque capaz como al negro
			ll ti=abs(ni-bi_),tj=abs(nj-bj_);
			if(ti<=1&&tj<=1)continue;
			if(!f(bi_,bj_,ni,nj,pi,pj,t+1,w^1))return res=1;
		}
	}
	else { // juega negro
		// Rey
		ll hay=0;
		fore(di,-1,2)fore(dj,-1,2){
			if(di==0&&dj==0)continue;
			ll ni_=ni+di;
			ll nj_=nj+dj;
			if(!allowed(ni_,nj_))continue;
			if(nj_-pj==1&&abs(ni_-pi)==1)continue;
			ll ti=abs(ni_-bi),tj=abs(nj_-bj);
			if(ti<=1&&tj<=1)continue;
			hay=1;
			if(!f(bi,bj,ni_,nj_,pi,pj,t+1,w^1))return res=1;
		}
		if(!hay)return res=1; // ahogado
	}
	// if(dbg)cerr<<bi<<","<<bj<<" "<<ni<<","<<nj<<" "<<pi<<","<<pj<<": "<<w<<" pierde\n";
	return res=0;
}

int main(){FIN;
	mset(dp,-1);
	ll bi,bj,pi,pj,ni,nj; cin>>bi>>bj>>pi>>pj>>ni>>nj;
	if(f(bi,bj,ni,nj,pi,pj,0,0)){
		cout<<"White Wins\n";
	}
	else {
		cout<<"Draw\n";
	}
	return 0;
}
