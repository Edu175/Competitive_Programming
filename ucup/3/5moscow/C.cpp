#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

ll lgt(ll n){
	ll res=__lg(n);
	res+=1-((n&-n)==n);
	return res;
}
bool good(ll l, ll r, ll n, ll p, ll z){
	// cout<<"good "<<l<<","<<r<<" "<<n<<" "<<p<<" "<<z<<endl;
	ll best=lgt(n);
	ll N=1ll<<best;
	assert(N>=4);
	ll h=N/2;
	assert(h%2==0);
	if(p>=h)return good(r,l,n,n-1-p,z);
	
	// ll d=N-n;
	// p+=d;
	// if(p>=h)return 1;
	// if(wantr)return 0;
	// if(l==z)return 1;
	// p+d>=h/2||l==z;
	
	ll tot=z*(n-2)+l+r;
	ll ex=lgt(p+1);
	ll w=1ll<<ex;
	w=w*z-(z-l);
	
	ll now=ex+lgt((tot+w-1)/w);
	assert(now>=best);
	return now==best;
}


ll cuenta(ll l, ll r, ll n){ // 1d, [l,r)
	
	if(l>=r)return INF;
	
	ll z=r-l;
	ll cost=lgt((n+z-1)/z);
	// cout<<"cuenta "<<l<<","<<r<<" "<<n<<": "<<z<<" "<<cost<<"\n";
	if(l==0||n-r==0)return cost;
	ll sl=l%z;
	if(!sl)sl=z;
	ll p=(l+z-1)/z;
	
	ll sr=(n-r)%z;
	if(!sr)sr=z;
	ll np=p+1+(n-r+z-1)/z;
	
	ll gd=good(sl,sr,np,p,z);
	
	cost=lgt(np);
	ll res=cost+!gd;
	// cout<<"was good? "<<gd<<"\n";
	return res;
}

int main(){
    JET
	ll n,m; cin>>n>>m;
	vector<vv> a(n,vv(m));
	
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		a[i][j]=c=='1';
	}
	ll res=INF;
	
	auto cand=[&](ll i0, ll j0, ll i1, ll j1){ // [,] both
		ll curi=cuenta(i0,i1+1,n);
		ll curj=cuenta(j0,j1+1,m);
		ll cur=curi+curj;
		// if(cur<INF)cerr<<"cand "<<i0<<","<<j0<<" "<<i1<<","<<j1<<": "<<cur<<"\n\n";
		res=min(res,cur);
	};
	
	vv h(m);
	fore(i,0,n){
		fore(j,0,m){
			h[j]++;
			if(!a[i][j])h[j]=0;
		}
		stack<ii> s;
		s.push({-2,-1});
		// for(auto i:h)cout<<i<<" ";;cout<<"\n";
		h.pb(0);
		fore(j,0,m+1){
			ll v=h[j];
			while(s.top().fst>=v){
				auto [w,asd]=s.top(); s.pop();
				ll id=s.top().snd;
				// cout<<j<<": "<<id<<" "<<w<<"\n";
				// cout<<s.top().fst<<","<<s.top().snd<<"\n";
				cand(i-w+1,id+1,i,j-1);
			}
			s.push({v,j});
		}
		h.pop_back();
	}
	
	cout<<res<<"\n";
    return 0;
}
