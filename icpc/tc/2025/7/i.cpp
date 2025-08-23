#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld INF=1e9;
const ld eps=1e-7;
ll n,k; 
typedef pair<ld,ll> node;

bool can(ld *b){
	// fore(i,0,n+1) cout<<b[i]<<" ";;cout<<"b\n";
	vector<node> r;
	ll p[n+1];
	mset(p,-1);
	fore(i,0,n+1){
		if(b[i]<-eps) continue;
		ll it=upper_bound(ALL(r),(node){b[i]+eps,-1})-r.begin();
		if(it==SZ(r)) r.pb(node({b[i],i}));
		else r[it]=node({b[i],i});
		it--;
		if(it>=0) p[i]=r[it].snd;
	}
	ll u=n;
	ll c=0;
	do{
		c++;
		assert(u<=n);
		assert(u>=0);
		// cout<<u<<" "<<b[u]<<"u,b\n";
		u=p[u];
	}while(u!=-1);
	// fore(i,0,n+1) cout<<p[i]<<" ";;cout<<"p\n";
	// cout<<SZ(r)<<"\n";
	
	// for(auto xd: r) cout<<xd.fst<<" ";;cout<<"r\n";
	// cout<<c<<"c\n";
	return c>=k+1;
}
int main(){
	JET
	cin>>n>>k;
	ld a[n];
	fore(i,0,n) cin>>a[i];
	ld l=0.,r=INF;
	ld b[n+1];
	b[0]=0.;
	while((r-l)>=eps){
		ld m=(l+r)/2;
		// cout<<m<<"m\n";
		fore(i,0,n) b[i+1]=b[i]+ld(a[i])-m;
		if(can(b)) l=m;
		else r=m;
	}
	// cout<<"test\n";
	// fore(i,0,n) b[i+1]=b[i]+ld(a[i])-1.9;
	// cout<<can(b)<<"can\n";
	cout<<fixed<<setprecision(7)<<l<<"\n";
	return 0;
}
// -1u
// 0 -0.7 0.6 -0.1 0.2 0.5 0.8 0.1 
// -1 -1 1 1 3 4 5 3 p
// 5
// -0.7 -0.1 0.1 0.5 0.8 r
// -1u
// 0
// 0


