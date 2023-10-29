#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n;cin>>n;vector<ll>f(n);vector<ll>p(n);
		multiset<ll>st;
		map<ll,pair<ll,vector<ll>>>m;
		vector<ll>z;
		fore(i,0,n)cin>>f[i];
		fore(i,0,n)cin>>p[i],st.insert(p[i]);
		fore(i,1,n+1)if(st.count(i)==0)z.pb(i);
		set<ll>st0;
		for(auto i:st)if(st.count(i)==1)st0.insert(i);
		for(auto i:z){
			m[i].snd.pb(i);
			m[i].fst=f[i-1];
			ll x=i;
			while(st0.count(x)==0){
				x=p[x-1];
				m[i].snd.pb(x);
				m[i].fst=max(m[i].fst,f[x-1]);
			}
			swap(i,(m[i].fst));
		}
		sort(ALL(m));
		set<ll>st1;
		ll res;
		ll maxi;
		for(auto i:m){
			ll y=i.snd.snd[0];
			maxi=f[y-1];
			while(y>0&&st1.count(y)==0){
				maxi=max(maxi,f[y-1]);
				st1.insert(y);
				y=p[y-1];
				res+=maxi;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
