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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n),b(m),c(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		fore(i,0,m)cin>>c[i];
		priority_queue<ll> pa;
		priority_queue<ii> pw,pl;
		fore(i,0,n)pa.push(-a[i]);
		fore(i,0,m){
			(c[i]==0?pl:pw).push({-b[i],c[i]});
		}
		ll res=0;
		while(SZ(pa)){
			auto x=pa.top(); pa.pop(); x=-x;
			// cout<<x<<" arma\n";
			if(SZ(pw)&&-pw.top().fst<=x){
				auto [b,c]=pw.top(); pw.pop();
				// cout<<-b<<" "<<c<<" mostro\n";
				x=max(x,c);
				pa.push(-x);
				res++;
			}
			else if(SZ(pl)&&-pl.top().fst<=x){
				// cout<<"pl\n";
				pl.pop();
				res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
