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

ll n,m;
ll mod(ll n, ll m){
	return (n%m+m)%m;
}
vv a,b;

// ll get(ll off, ll k){
// 	ll l=0,r=n-1;
// 	while(l<=r){
		
// 	}
// }

bool good(vector<ii>a){
	vv vis(n);
	ll L=-1,R=-1;
	for(auto &[l,r]:a){
		while(L>l||R>r)l+=n,r+=n;
		L=l,R=r;
	}
	ll mx=max(L,R);
	ll po=0;
	for(auto [l,r]:a){
		while(po<=mx&&(vis[po%n]||po<l))po++;
		if(po>=r)return 0;
		vis[po%n]=1;
	}
	return 1;
}
void rev(auto &a){
	reverse(ALL(a));
	for(auto &[l,r]:a){
		r--;
		
		l=2*n-1-l;
		r=2*n-1-r;
		swap(l,r);
		
		r++;
	}
}
bool can(ll k){
	vector<ii>ran(n);
	ll l=lower_bound(ALL(b),m-a[0])-b.begin();
	ll r=lower_bound(ALL(b),m-a[0]+k)-b.begin();
	ran[0]={l,r};
	fore(i,1,n){
		ll s=m-a[i],e=m-a[i]+k;
		while(l<2*n&&b[l]<s)l++;
		while(r<2*n&&b[r]<e)r++;
		ran[i]={l,r};
	}
	vv sz(n);
	ll mn=0;
	fore(i,0,n){
		auto &[l,r]=ran[i];
		sz[i]=r-l;
		// l=mod(l,n);
		// r=mod(r,n);
		if(sz[i]<sz[mn])mn=i;
	}
	// cout<<"can "<<k<<": ";
	// for(auto i:ran)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	rotate(ran.begin(),ran.begin()+mn,ran.end());
	
	// cerr<<"cand0: ";;for(auto i:ran)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ll fg=good(ran);
	
	rev(ran);
	
	rotate(ran.begin(),ran.begin()+n-1,ran.end());
	// cerr<<"cand1: ";;for(auto i:ran)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	fg|=good(ran);
	
	// cout<<fg<<"\n\n";
	return fg;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		a=b=vv(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		
		reverse(ALL(a)); // lo pense al reves
		fore(i,0,n)b.pb(b[i]+m);
		
		// if(m<500)fore(i,0,m)can(i);
		ll l=-1,r=m;
		while(r-l>1){
			ll h=(l+r)/2;
			if(can(h))r=h;
			else l=h;
		}
		// cout<<n<<": "<<SZ(b)<<"\n";
		// imp(a)
		// imp(b)
		cout<<l<<"\n";
	}
	return 0;
}
