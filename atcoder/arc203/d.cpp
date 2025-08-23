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

ll bor(ll prim, ll elem){
	if(prim==0)return 0;
	return 1+(elem==0);
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	
	set<ll>st;
	ll adj=0,cnt=count(ALL(a),1);
	auto good=[&](ll i){return i>=0&&i+1<n&&!a[i]&&!a[i+1];};
	auto agr=[&](ll i){
		if(!good(i))return;
		auto [it,bo]=st.insert(i);
		if(!bo)return;
		adj+=st.count(i-1)+st.count(i+1);
	};
	auto sac=[&](ll i){
		if(good(i))return;
		if(!st.count(i))return;
		st.erase(i);
		adj-=st.count(i-1)+st.count(i+1);
	};
	
	auto query=[&]()->ll{
		if(cnt==n)return n;
		ll sz=SZ(st);
		if(!sz){
			ll res=2;
			if(!a[0]&&!a.back()&&cnt){
				res++;
			}
			return res;
		}
		ll tr=sz-1-adj;
		
		ll bl=tr+1;
		
		ll res=2*bl + tr;
		res+=bor(*st.begin(),a[0]);
		res+=bor(n-1-(*st.rbegin()+1),a.back());
		return res;
	};
	fore(i,0,n)agr(i);
	
	ll q; cin>>q;
	while(q--){
		ll p; cin>>p; p--;
		
		cnt-=a[p];
		a[p]^=1;
		
		sac(p); agr(p);
		sac(p-1); agr(p-1);
		cnt+=a[p];
		
		cout<<query()<<"\n";
	}
	return 0;
}
