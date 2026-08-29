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

ll calc(vv a, ll s){
	ll n=SZ(a);
	vv b(n);
	ll mx=0;
	for(ll i=(s-1+n)%n;i!=s;i=(i-1+n)%n){
		mx=max(mx,a[i]);
		b[i]=mx;
	}
	mx=0;
	for(ll i=(s+1)%n;i!=s;i=(i+1)%n){
		mx=max(mx,a[(i-1+n)%n]);
		b[i]=min(b[i],mx);
	}
	ll res=accumulate(ALL(b),0ll);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv ans(n);
		ll mx=max_element(ALL(a))-a.begin();
		ans[mx]=calc(a,mx);
		a[mx]++;
		// ll vm=a[mx];
		// rotate(a.begin(),a.begin()+mx,a.end());
		// a.pb(vm);
		vector<ii> sa;
		fore(i,0,n)sa.pb({a[i],i});
		sort(ALL(sa));
		
		vv l(n+1),r(n+1);
		fore(i,0,n)l[i]=(i-1+n)%n,r[i]=(i+1)%n;
		
		vv sw(n+1);
		
		auto agr=[&](ll l, ll r, ll v, auto &&agr)->void { // [l,r)
			if(l>r){
				agr(l,n,v,agr);
				agr(0,r,v,agr);
				return;
			}
			// if(l<=0)cerr<<"agr "<<l<<","<<r<<": "<<v<<"\n";
			sw[l]+=v;
			sw[r]-=v;
		};
		
		for(auto [asd,i]:sa)if(i!=mx){
			l[r[i]]=l[i];
			r[l[i]]=r[i];
			// cerr<<i<<": "<<l[i]<<","<<r[i]<<"\n";
			agr(l[i]+1,i+1,(r[i]-i+n)%n*a[i],agr);
			agr(i+1,r[i]+1,(i-l[i]+n)%n*a[i],agr);
		}
		ll acum=0;
		fore(i,0,n){
			acum+=sw[i];
			if(i!=mx)ans[i]+=acum;
		}
		show(ans)
	}
	return 0;
}
