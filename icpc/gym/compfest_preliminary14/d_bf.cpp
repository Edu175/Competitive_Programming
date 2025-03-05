#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll MAXS;
ll n;
vv a;
bool can(){
	vv b;
	for(auto v:a){
		ll did=0;
		fore(c,0,v){
			if(!SZ(b)||((v-c)<<c)>b.back()){
				b.pb((v-c)<<c);
				// a.pb(v);
				// cs.pb(c);
				did=1;
				break;
			}
		}
		if(!did)return 0;
	}
	return 1;
}

pair<ll,vv> best;
ll sum=0;
void f(){
	if(sum>best.fst)return;
	if(n==SZ(a)){
		// cout<<"candidate: ";
		// 	for(auto i:a)cout<<i<<" ";
		// 	cout<<"\n";
		if(can()){
			best=min(best,pair<ll,vv>({sum,a}));
			// cout<<"candidate: ";
			// for(auto i:a)cout<<i<<" ";
			// cout<<"\n";
		}
		return;
	}
	fore(i,(SZ(a)?a.back():1),MAXS+1){
		if(i+sum>MAXS)break;
		a.pb(i); sum+=i;
		f();
		a.pop_back(); sum-=i;
	}
}

int main(){
    JET
	cin>>n;
	ll m=(n+6)/2;
	MAXS=m*(m+1);
	best.fst=MAXS+1;
	vv sol={1,2};
	while(SZ(sol)<n){
		ll v=sol.back()+1;
		sol.pb(v);
		sol.pb(v);
	}
	while(SZ(sol)>n)sol.pop_back();
	best.fst=accumulate(ALL(sol),0ll);
	best.snd=sol;
	a.pb(1); sum=1;
	f();
	cout<<best.fst<<"\n";
	for(auto i:best.snd)cout<<i<<" ";;cout<<"\n";
    return 0;
}