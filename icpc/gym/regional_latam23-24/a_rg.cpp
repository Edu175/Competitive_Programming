#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
	
	// for K, I think
	// ll n,k; cin>>n>>k;
	// cout<<n<<" "<<k<<"\n";
	// fore(i,0,n)cout<<rng()%k+1<<" ";
	// cout<<"\n";

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
int main(){
	ET;
	ll N,Q,V; cin>>N>>Q>>V;
	ll n=rng()%N+1;
	
	vv ss=getDistinct(n,V),ps=getDistinct(n,V);
	sort(ALL(ss)); sort(ALL(ps)); reverse(ALL(ps));
	cout<<n<<"\n";
	fore(i,0,n)cout<<ss[i]<<" "<<ps[i]<<"\n";
	ll q=rng()%Q+1; cout<<q<<"\n";
	while(q--){
		ll ty=rng()&1;
		if(ty){
			cout<<"s "<<rng()%n+1<<"\n";
		}
		else {
			cout<<"c "<<rng()%V+1<<" "<<rng()%V+1<<"\n";
		}
	}
}