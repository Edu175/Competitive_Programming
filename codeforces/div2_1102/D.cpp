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
typedef vector<bool> mask;

void operator^=(mask &a, mask b){
	fore(i,0,SZ(a)){
		a[i]=a[i]^b[i];
	}
}

ll get(mask l, mask r, ll k, ll n){
	vector<array<ll,3>> a;
	a.pb({1,2,1});
	vv cant(4);
	cant[1]++;
	cant[2]++;
	fore(_,0,k){
		vector<array<ll,3>> prox;
		for(auto [l,r,q]:a){
			ll m=l^r;
			prox.pb({l,m,q});
			prox.pb({m,r,q});
			cant[m]+=q;
		}
		sort(ALL(prox));
		a.clear();
		for(auto [l,r,q]:prox){
			if(SZ(a)&&a.back()[0]==l&&a.back()[1]==r)a.back()[2]+=q;
			else a.pb({l,r,q});
		}
	}
	vector<mask> nums(4,mask(n));
	fore(i,0,2)fore(j,0,2){
		auto &res=nums[i+2*j];
		if(i)res^=l;
		if(j)res^=r;
	}
	ll res=0;
	fore(i,0,4){
		ll val=count(ALL(nums[i]),0)*count(ALL(nums[i]),1);
		// cerr<<"val "<<i<<": "<<val<<"\n";
		// show(nums[i])
		res+=val*cant[i];
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		mask l(n),r(n);
		fore(i,0,n){
			char c; cin>>c;
			l[i]=c-'0';
		}
		fore(i,0,n){
			char c; cin>>c;
			r[i]=c-'0';
		}
		cout<<get(l,r,k,n)<<"\n";
	}
	return 0;
}
