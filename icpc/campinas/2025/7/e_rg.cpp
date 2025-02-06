#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

ii get(ii a){
	if(a==ii({0,0}))return a;
	ll g=gcd(a.fst,a.snd);
	a.fst/=g;
	a.snd/=g;
	return a;
}

int main(){
	JET
	ll N,V; cin>>N>>V;
	ll n=rng()%N+1;
	// assert(V*V>=n);
	set<ii>st={{0,0}};
	vector<ii>all;
	vv pera(2*V+1),perb(2*V+1);
	iota(ALL(pera),-V); iota(ALL(perb),-V);
	shuffle(ALL(pera),rng); shuffle(ALL(perb),rng);
	for(auto i:pera)for(auto j:perb){
		ii a={i,j};
		auto d=get(a);
		ii md={-d.fst,-d.snd}; 
		if(!st.count(md))all.pb(a);
		st.insert(d);
	}
	shuffle(ALL(all),rng);
	assert(n<=SZ(all));
	cout<<n<<"\n";
	fore(i,0,n)cout<<all[i].fst<<" "<<all[i].snd<<"\n";
	
	return 0;
}