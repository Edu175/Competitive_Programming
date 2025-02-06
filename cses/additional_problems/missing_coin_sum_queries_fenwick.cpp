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
const ll MAXN=2e5+5;
typedef ii node;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
ll ftS[MAXN+1];
void upd(int i0, node v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v.fst,ftS[i]+=v.snd;
}
node get(int i0){ // get sum of range [0,i0)
	node r={0,0};
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r.fst+=ft[i],r.snd+=ftS[i];
	return r;
}
node operator-(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
node get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<ii>sa;
	fore(i,0,n)sa.pb({a[i],i});
	sort(ALL(sa));
	vv sum(q),zs(q);
	vector<ii>qs;
	
	fore(_,0,q){
		ll l,r; cin>>l>>r; l--;
		qs.pb({l,r});
	}
	vv ids(q); iota(ALL(ids),0);
	
	while(SZ(ids)){
		sort(ALL(ids),[&](const int &i, const int &j){
			return sum[i]<sum[j];
		});
		vv prox;
		ll po=0;
		fore(t,0,n+1){
			while(po<SZ(ids)&&(t==n||sum[ids[po]]+2<=sa[t].fst)){
				ll i=ids[po];
				auto [c,sumi]=get_sum(qs[i].fst,qs[i].snd);
				if(c!=zs[i]){
					prox.pb(i);
					zs[i]=c,sum[i]=sumi;
				}
				po++;
			}
			if(t<n)upd(sa[t].snd,{1,sa[t].fst});
		}
		// fore(t,0,n)upd(sa[t].snd,{-1,-sa[t].fst});
		mset(ft,0);
		mset(ftS,0);
		swap(ids,prox);
	}
	for(auto i:sum)cout<<i+1<<"\n";
	return 0;
}