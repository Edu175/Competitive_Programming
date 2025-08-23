#include "worldmap.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define imp1(v) {for(auto i:v)cout<<i+1<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXK=240;

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii der={0,1};
ii aba={1,0};

void achica(vector<vector<int>> &a){
	ll mxv=-1,mxh=-1;
	fore(i,0,SZ(a))fore(j,0,SZ(a[i]))if(a[i][j]!=-1){
		mxv=max(mxv,i);
		mxh=max(mxh,j);
	}
	ll k=max(mxv,mxh)+1;
	a.resize(k);
	fore(i,0,k)a[i].resize(k);
}

vector<vector<int>> create_map(int N, int M, vector<int> A, vector<int> B) {
	ll n=N;
	vector<set<ll>> g(n);
	fore(i,0,M){
		A[i]--,B[i]--;
		g[A[i]].insert(B[i]);
		g[B[i]].insert(A[i]);
	}
	auto in=[&](ii p){return p.fst>=0&&p.snd>=0;};
	auto av=[&](ii p){p.fst--,p.snd++;return p;};
	auto circ=[&](ii p){
		swap(p.fst,p.snd);
		p.fst++,p.snd++;
		return p;
	};
	auto revCirc=[&](ii p){ // revertir
		p.fst--,p.snd--;
		swap(p.fst,p.snd);
		return p;
	};
	auto avif=[&](ii p){
		p=av(p);
		if(!in(p))p=circ(p);
		return p;
	};
	auto revAvif=[&](ii p){ // revertir
		if(p.snd==0)p=revCirc(p);
		p.fst++,p.snd--;
		return p;
	};
	vector<vector<int>> ans(MAXK,vector<int>(MAXK,-1));
	auto put=[&](ii p, ll x){
		// cerr<<"put "<<p.fst<<","<<p.snd<<" "<<x+1<<"\n";
		ans[p.fst][p.snd]=x;
	};
	ll x=0;
	ans[0][0]=x;
	ii p={1,0};
	while(1){
		auto &st=g[x];
		// cerr<<"x: "<<x+1<<": ";
		// imp1(st)
		while(SZ(st)>1){
			ll y=*st.begin();
			st.erase(y); g[y].erase(x);
			put(p,y);
			put(p+der,x);
			put(p+aba,x);
			p=avif(p);
		}
		if(!SZ(st))break;
		// cerr<<"ended "<<p.fst<<","<<p.snd<<"\n";
		ll y=*st.begin();
		st.erase(y); g[y].erase(x);
		ii q=p,u=revAvif(p)+der;
		while(1){
			put(q,y);
			if(q==u+der)break;
			q=avif(q);
		}
		p=avif(u);
		x=y;
	}
	achica(ans);
	ll k=SZ(ans);
	fore(i,0,k)fore(j,0,k){
		if(ans[i][j]==-1)ans[i][j]=x;
		ans[i][j]++; // 1-indexed
	}
	// cerr<<" end test\n";
	return ans;
}
