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
random_device rd;
mt19937 rng(rd());
vv getDistinct(ll k, ll n){
	vv res;
	if(2*k<n){
		set<ll>st;
		while(SZ(st)<k)st.insert(rng()%n+1);
		for(auto i:st)res.pb(i);
		shuffle(ALL(res),rng);
	}
	else {
		vv v(n); iota(ALL(v),1); shuffle(ALL(v),rng);
		fore(i,0,k)res.pb(v[i]);
	}
	return res;
}
int main(){FIN;
	ll N,V; cin>>N>>V;
	ll n=rng()%N+1;
	cout<<"1\n";
	cout<<n<<"\n";
	fore(i,0,n)cout<<rng()%(V+1)<<" ";;cout<<"\n";
	// imp(getDistinct(2*n,V));
	return 0;
}
