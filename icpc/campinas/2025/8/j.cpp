#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll K=18;
ll n;
ll out(ll v){
	return v==-1||v==n;
}
struct BinL{
	ll F[K][1<<K],V[K][1<<K];
	ll oper(ll a, ll b, ll pot){
		return max(a+pot,b);
	}
	void init(vv a, vv v){
		fore(i,0,n)F[0][i]=a[i],V[0][i]=v[i]+1;
		fore(k,1,K)fore(i,0,n){
			if(out(F[k-1][i])){F[k][i]=V[k][i]=-1;continue;}
			F[k][i]=F[k-1][F[k-1][i]];
			V[k][i]=oper(V[k-1][i],V[k-1][F[k-1][i]],1ll<<(k-1));
			// cout<<V[k][i]<<"\n";
		}
	}
	ll query(ll p, ll l, ll r){
		ll val=0,_p=p;
		// cerr<<"query "<<l<<","<<r<<" "<<p<<"\n";
		for(ll k=K-1;k>=0;k--){
			ll to=F[k][p];
			if(l<=to&&to<r){
				val=oper(val,V[k][p],1ll<<k);
				// cerr<<"jump "<<k<<": "<<V[k][p]<<"\n";
				p=to;
			}
		}
		// cout<<val<<" val\n";
		if(p==_p)assert(val==0);
		return val;
	}
};


int main(){
	JET
	ll q; cin>>n>>q;
	vv a(n),pos(n);
	fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]]=i;
	
	vv le(n),ri(n); // primer mayor
	for(ll i=n-1;i>=0;i--)
		for(ri[i]=i+1;ri[i]!=n&&a[ri[i]]<=a[i];ri[i]=ri[ri[i]]);
	fore(i,0,n)
		for(le[i]=i-1;le[i]!=-1&&a[le[i]]<=a[i];le[i]=le[le[i]]);
	
	vv dpl(n),dpr(n);
	fore(i,0,n){
		ll p=pos[i];
		ll l=le[p],r=ri[p];
		ll now=max(dpl[p],dpr[p]);
		if(l!=-1)dpr[l]=max(dpr[l],1+now);
		if(r!=n)dpl[r]=max(dpl[r],1+now);
	}
	BinL left,right;
	left.init(le,dpl);
	right.init(ri,dpr);
	// cout<<"dpl: ";; fore(i,0,n)cout<<dpl[i]<<" ";;cout<<"\n";
	// cout<<"dpr: ";; fore(i,0,n)cout<<dpr[i]<<" ";;cout<<"\n";
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=max(right.query(l,l,r),left.query(r-1,l,r));
		cout<<res<<"\n";
	}
	
	return 0;
}

/*

dpl: 0 0 1 0 0 4 
dpr: 3 0 2 1 0 0 

*/