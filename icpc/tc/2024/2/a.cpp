#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto sdljg:v)cout<<sdljg<<" ";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		ll flag=1;
		fore(i,0,n)flag&=a[i]==i;
		if(flag){
			cout<<n-2<<"\n";
			continue;
		}
		set<ll>l,r;
		map<ii,ll>mp;
		// fore(i,0,n)if()r.insert(a[i]);
		ll res=0,ext=0;
		auto agrego=[&](ll i, ll j){
			if(i>j)swap(i,j);
			mp[{i,j}]++;
		};
		// imp(a); cout<<"\n";
		fore(i,0,n){
			r.erase(a[i]);
			if(i)if(a[i-1]>i)l.insert(a[i-1]);
			
			l.erase(i);
			if(i)if(p[i-1]>i)r.insert(i-1);
			
			// cout<<i<<": "; imp(l); cout<<"| "; imp(r); cout<<"\n";
			
			if(a[i]==i){
				if(SZ(l)+SZ(r)==0)ext++;
				else if(SZ(l)==1){
					assert(SZ(r)==1);
					agrego(p[*l.begin()],p[*r.begin()]);
				}
				//else nada
			}
			else {
				if(SZ(l)+SZ(r)==0)agrego(i,p[i]);
			}
		}
		for(auto i:mp)res=max(res,i.snd);
		cout<<res+ext<<"\n";
	}
}