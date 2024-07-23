#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto sdjfh:v)cout<<sdjfh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),zip;
		fore(i,0,n)cin>>a[i],zip.pb(a[i]);
		sort(ALL(zip));
		vv zipp;
		fore(i,0,SZ(zip))if(!i||zip[i]!=zip[i-1])zipp.pb(zip[i]);
		zip=zipp;
		for(auto &i:a){
			i=lower_bound(ALL(zip),i)-zip.begin();
		}
		vector<ll>sweep[n+1];
		vector<ll> ls(m),rs(m);
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--;
			ls[i]=l; rs[i]=r;
			sweep[l].pb(i);
			sweep[r].pb(i);
		}
		vector<ll>le(n),ri(n);
		multiset<ll>st;
		auto erase=[&](ll x){
			st.erase(st.find(x));
		};
		vector<ll>pos[n];
		fore(i,0,n)pos[a[i]].pb(i);
		// imp(a); 
		fore(i,0,n){
			// cout<<i<<":\n";//imp(st);
			for(auto j:sweep[i]){
				if(i==ls[j])st.insert(ls[j]),st.insert(rs[j]);
				else erase(ls[j]),erase(rs[j]);
			}
			// imp(sweep[i]);
			le[i]=i;
			ri[i]=i+1;
			if(SZ(st)){
				le[i]=min(le[i],*st.begin());
				ri[i]=max(ri[i],*st.rbegin());
			}
			// cout<<le[i]<<","<<ri[i]<<" -> ";
			le[i]=*lower_bound(ALL(pos[a[i]]),le[i]);
			ri[i]=*(--lower_bound(ALL(pos[a[i]]),ri[i]))+1;
			// cout<<le[i]<<","<<ri[i]<<"\n\n";
		}
		vector<ll>h[n+1];
		ll bad=n,mx=0,did=0;
		fore(i,0,n)if(le[i]<i||ri[i]>i+1){
			did=1;
			ll l=le[i],m=i,r=ri[i];
			if(l==m)m=r-1;
			if(m==r-1)mx=max(mx,l+1);
			else mx=max(mx,m+1);
			h[l+1].pb(m+1);
			bad=min(bad,m+1); // hay 3
		}
		if(!did){cout<<"0\n";continue;}
		ll res=n+5;
		// cout<<bad<<"\n";
		fore(l,0,bad){
			// cout<<l<<": ";
			// imp(h[l]);
			for(auto i:h[l])mx=max(mx,i);
			res=min(res,mx-l);
		}
		// res=max(res,0ll);
		cout<<res<<"\n";
	}
	return 0;
}