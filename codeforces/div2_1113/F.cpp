#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll peaks(vector<vv> &a){
	ll n=SZ(a),m=SZ(a[0]);
	vv sr(n),sc(m);
	fore(i,0,n)fore(j,0,m)sr[i]+=a[i][j],sc[j]+=a[i][j];
	ll res=0;
	fore(i,0,n)fore(j,0,m){
		ll sum=sr[i]+sc[j]-2*a[i][j];
		res+=a[i][j]>=sum;
	}
	return res;
}

bool can(vector<vv> a, ll h, ll k){
	for(auto &r:a)for(auto &i:r)i-=h;
	return peaks(a)>=k;
}

const ll R=1e12;
ll generic(vector<vv> &a, ll k){
	ll l=-1,r=R;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(a,m,k))r=m;
		else l=m;
	}
	if(r>=R-100)r=-1;
	return r;
}

bool can2(vv a, ll h, ll k){
	ll n=SZ(a);
	// cerr<<"can2 "<<h<<"\n";
	ll sum=accumulate(ALL(a),0ll);
	for(auto &i:a)i=sum-2*i;
	for(auto &i:a)i-=(n-2)*h;
	// show(a)
	ll q=max(0ll,a[0]);
	if(q>h)return 0;
	a[0]-=q;
	fore(i,1,n)a[i]+=q;
	ll cant=0;
	for(auto i:a)cant+=i<=0;
	// show(a)
	// cerr<<"cant "<<cant<<"\n\n";
	return cant>=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		// 1 1
		vector<vv> A(n,vv(m));
		fore(i,0,n)fore(j,0,m)cin>>A[i][j];
		if(min(n,m)>=2){
			ll res=generic(A,k);
			cout<<res<<"\n";
			continue;
		}
		vv a;
		fore(i,0,n)fore(j,0,m)a.pb(A[i][j]);
		n=SZ(a);
		if(n==1){
			ll res=a[0]>=0?0:-1;
			cout<<res<<"\n";
			continue;
		}
		if(n==2){
			ll res=0;
			if(k==2){
				res=abs(a[0]-a[1]);
			}
			cout<<res<<"\n";
			continue;
		}
		
		ll res=generic(A,k);
		fore(_,0,2){
			ll l=-1,r=R;
			while(r-l>1){
				ll h=(l+r)/2;
				if(can2(a,h,k))r=h;
				else l=h;
			}
			res=min(res,r);
			reverse(ALL(a));
		}
		if(res>=R-100)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
