#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=2e9;

vector<ll> divs(ll n){
	vector<ll>r;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)r.pb(i),r.pb(n/i);
		if(i*i==n)r.pop_back();
	}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll m=1;
		fore(i,0,n)m=min(INF,lcm(m,a[i]));
		sort(ALL(a)); reverse(ALL(a));
//		imp(a); cout<<m<<" dd\n";
		if(m>a[0]){
			cout<<n<<"\n";
			continue;
		}
		set<ll>st;
		ll res=0;
		for(auto x:a){
			for(auto d:divs(x))if(!st.count(d)){
				st.insert(d);
				ll resi=0,m=1,flag=1;
				for(auto y:a)if(d%y==0){
					m=min(INF,lcm(m,y));
					resi++;
					flag&=y!=d;
				}
				if(flag&&m==d)res=max(res,resi);
			}
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
