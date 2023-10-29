#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;

ll f(vector<ll>a){
	ll l=(a[1]+a[0])/2,r=(a[3]+a[2])/2;
	return r-l;
}

int main(){FIN;
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i],a[i]*=2;
		sort(ALL(a));
		ll res=0;
		if(n==5){
			res=max(f({a[0],a[1],a[2],a[4]}),f({a[0],a[2],a[3],a[4]}));
		}
		else res=f({a[0],a[1],a[n-2],a[n-1]});
		cout<<fixed<<setprecision(15)<<res/2.0<<"\n";
	}
	return 0;
}
