#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=2e5+5,B=1000;

ii NEUT={0,0};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
void operator+=(ii &a, ii b){a=a+b;}
ii ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, ii v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ii get(int i0){ // get sum of range [0,i0)
	ii r=NEUT;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
ii get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}
struct qu{
	ll s,e,i,j,t;
};
int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	//imp(a);
	vector<int>sp[B];
	fore(x,1,B){
		sp[x].resize(n+1);
		fore(i,1,n+1)sp[x][i]=sp[x][i-1]+a[i-1]%x;
	}
	vector<vector<ii>>qs(q);
	vector<qu>ev[n+1];
	vector<ll>ans(q);
	vector<ll>xs(q);
	fore(i,0,q){
		ll l,r,x; cin>>l>>r>>x; l--;
		//cout<<"\n l r x "<<l<<","<<r<<" "<<x<<"\n";
		if(x<B)ans[i]=sp[x][r]-sp[x][l];
		else {
			for(ll s=0;s<MAXN;s+=x){
				ll e=min(MAXN,s+x);
				ev[r].pb(qu({s,e,i,SZ(qs[i]),1}));
				ev[l].pb(qu({s,e,i,SZ(qs[i]),-1}));
				qs[i].pb({0,0});
			}
			xs[i]=x;
		}
	}
	fore(i,0,n+1){
		for(auto q:ev[i]){
			ii rq=get_sum(q.s,q.e);
			if(q.t==-1)rq.fst=-rq.fst,rq.snd=-rq.snd;
			qs[q.i][q.j]+=rq;
		}
		if(i<n)upd(a[i],{a[i],1});
	}
	fore(i,0,q){
		if(xs[i]){
			ll res=0;
			for(ll s=0,j=0;s<MAXN;s+=xs[i],j++){
				ii &rq=qs[i][j];
				res+=rq.fst-s*rq.snd;
			}
			cout<<res<<" ";
		}
		else cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
