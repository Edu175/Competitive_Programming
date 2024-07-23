#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto dfjgh:v)cout<<dfjgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll solve(vector<ll>a, vector<ll>b){
	sort(ALL(a)); sort(ALL(b));
	ll n=SZ(a),m=SZ(b),res=0,sum=0;
	auto esta=[&](ll x){
		auto it=lower_bound(ALL(a),x);
		return it!=a.end()&&*it==x;
	};
	fore(i,0,m)sum+=esta(b[i]);
	// imp(a); imp(b); cout<<sum<<"\n";
	fore(i,0,m){
		sum-=esta(b[i]);
		ll q=upper_bound(ALL(a),b[i])-a.begin();
		ll p=b[i]-q;
		ll c=upper_bound(ALL(b),p)-b.begin();
		// cout<<b[i]<<": "<<q<<" "<<p<<": "<<c<<"\n";
		ll resi=i+1-c+sum;
		res=max(resi,res);
	}
	return res;
}

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m),la,lb,ra,rb;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]<0)la.pb(-a[i]);
			else ra.pb(a[i]);
		}
		fore(i,0,m){
			cin>>b[i];
			if(b[i]<0)lb.pb(-b[i]);
			else rb.pb(b[i]);
		}
		ll res=solve(la,lb)+solve(ra,rb);
		cout<<res<<"\n";
		
	}
}