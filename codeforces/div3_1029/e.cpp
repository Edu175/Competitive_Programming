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
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		vector<vector<ll>> pos(n);
		fore(i,0,n){
			if(i&1)swap(a[i],b[i]);
			pos[a[i]].pb(i);
			pos[b[i]].pb(i);
		}
		ll res=0;
		fore(c,0,n){
			auto &v=pos[c];
			fore(i,0,SZ(v))fore(j,0,2){
				if(i+j+1>=SZ(v))break;
				ll p=v[i],q=v[i+j+1];
				set<ii>st;
				fore(y,0,2)fore(w,0,2){
					if((y?a:b)[p]==(w?a:b)[q])st.insert({y,w});
				}
				if(q-p==1)st.erase({0,0}),st.erase({1,1});
				if(SZ(st))res=max(res,p+1);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
