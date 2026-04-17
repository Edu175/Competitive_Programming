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

vv vals;
vv oc;
ll k;
ll get_ans(){
	auto occ=oc;
	ll bad=0,hay=0,did=0;
	ll l=0,r=SZ(occ)-1;
	while(l<=r){
		if(!occ[l]){l++;continue;}
		if(!occ[r]){--r;continue;}
		if(l==r&&!did){
			occ[l]--; did=1;
			continue;
		}
		// if(l==r&&occ[l]==1){hay=1;break;}
		if(vals[l]*vals[r]<=k){
			hay=1;
			if(l==r)break;
			ll q=min(occ[l],occ[r]);
			occ[l]-=q;
			occ[r]-=q;
			continue;
		}
		bad+=occ[r];
		occ[r]=0;
	}
	ll res=(bad+1)/2;
	// cerr<<"query\n";
	// imp(vals)
	// imp(oc)
	// cout<<bad<<": "<<res<<"\n\n";
	return res;
}
vv a; // of ids
void add(ll i){oc[a[i]]++;}
void remove(ll i){oc[a[i]]--;}
int n,sq,nq; // size, sqrt(size), #queries
struct qu{int l,r,id;}; // HILT -> ll ord;
qu qs[MAXN]; ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
  if(a.l/sq!=b.l/sq) return a.l<b.l;
  return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
  fore(i,0,nq)qs[i].id=i; // HILT -> qs[i].ord = hilbertOrder(qs[i].l, qs[i].r);
  sq=sqrt(n)+.5; sort(qs,qs+nq,qcomp); int l=0,r=0;
  fore(i,0,nq){
    qu q=qs[i];
    while(l>q.l)add(--l);
    while(r<q.r)add(r++);
    while(l<q.l)remove(l++);
    while(r>q.r)remove(--r);
    ans[q.id]=get_ans();
  }
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>nq>>k;
		vals.clear();
		fore(i,1,k+1){
			ll j=k/i;
			if(i>j)break;
			vals.pb(i);
			if(j!=i)vals.pb(j);
		}
		sort(ALL(vals));
		oc=vv(SZ(vals));
		vv b(n);
		a=vv(n);
		fore(i,0,n){
			cin>>b[i];
			ll p=lower_bound(ALL(vals),b[i])-vals.begin();
			a[i]=p;
		}
		fore(i,0,nq){
			cin>>qs[i].l>>qs[i].r; qs[i].l--;
		}
		mos();
		fore(i,0,nq)cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
