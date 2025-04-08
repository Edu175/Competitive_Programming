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

ll mex(vv a){
	set<ll>st;
	for(auto i:a)st.insert(i);
	ll ret=0;
	while(st.count(ret))ret++;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll m=mex(a);
		if(m==0){
			ll mx=sp.back()-2*a[1],mn=-sp.back()+2*(a[0]+a[n-1]);
			fore(i,1,n-1)mx=max(mx,sp.back()-2*a[i]);
			cout<<mn<<" "<<mx<<"\n";
			continue;
		}
		vv pos[m];
		fore(i,0,n)if(a[i]<m)pos[a[i]].pb(i);
		ll L=-1,R=n+5; // []
		fore(c,0,m){
			L=max(L,pos[c][0]+1);
			R=min(R,pos[c].back());
		}
		ll good=1;
		fore(c,0,m){
			ll q=lower_bound(ALL(pos[c]),R)-lower_bound(ALL(pos[c]),L);
			good&=q>=1;
		}
		
		if(L>=R||!good){
			cout<<"-1 -1\n";
			continue;
		}
		// mn
		ll mn=sp.back()-2*(sp[R]-sp[L]);
		// cout<<<<" ";
		
		set<ll>st;
		
		fore(c,0,m)st.insert(pos[c][0]+1);
		ll res=mn;
		fore(i,0,n){ // itero l
			ll good=i>=L&&i<R;
			if(i>=R)break;
			
			ll r=*st.rbegin();
			if(r>R)break;
			
			if(good)res=max(res,sp.back()-2*(sp[r]-sp[i]));
			
			if(a[i]>=m)continue;
			
			st.erase(i+1);
			
			st.insert(*upper_bound(ALL(pos[a[i]]),i)+1);
			
		}
		cout<<mn<<" "<<res<<"\n";
	}
	return 0;
}
