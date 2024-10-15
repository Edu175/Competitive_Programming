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

bool sup(set<ll> a, set<ll>b){
	for(auto i:b)if(!a.count(i))return 0;
	return 1;
}

bool is_sub(vv a, vv b){ // <=
	ll j=0;
	fore(i,0,SZ(b)){
		if(j<SZ(a)&&a[j]==b[i])j++;
	}
	return j==SZ(a);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		auto dc=[&](vv a){
			set<ll>st;
			for(auto i:a)st.insert(i);
			return st;
		};
		auto blo=[&](vv a){
			vv b;
			for(auto i:a)if(!SZ(b)||i!=b.back())b.pb(i);
			return b;
		};
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		if(k==1){
			if(is_sub(blo(b),blo(a)))cout<<"Yes\n";
			else cout<<"No\n";
			continue;
		}
		if(!sup(dc(a),dc(b))){cout<<"No\n";continue;}
		if(a==b){cout<<"Yes\n";continue;}
		ll mind=n+5;
		vv pos(n,-2*n-5);
		fore(i,0,n){
			mind=min(mind,i-pos[b[i]]);
			pos[b[i]]=i;
		}
		if(k>=mind)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
