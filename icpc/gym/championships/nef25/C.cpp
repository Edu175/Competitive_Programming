#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size()) 
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cerr<<x<<" ";cerr<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll id=0;
vector<vv> sac;
ll QUERIES=0;
ll m;
ll ask(ll p, ll e){
	assert(++QUERIES<=8*m);
	cout<<"? "<<p<<" "<<e+1<<endl;
	// sac.pb(sac[p]); sac.back().pb(e+1); // remember to comment
	// cerr<<"sac: "; show(sac.back());
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	id++;
	return ret;
}

void answer(vv a){
	cout<<"! ";
	for(auto i:a)cout<<i<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
}

int main(){
    // JET
	ll t; cin>>t;
	while(t--){
		QUERIES=0;
		cin>>m;
		vv bag={0}; // bag.back() is always 0
		vv ans(m,-2);
		id=0; sac={{}};
		vv pos(m,-1);
		ll ex=0;
		fore(i,0,m){
			// cerr<<i<<": "; show(bag)
			ll l=-1,r=SZ(bag);
			ll u=-1;
			while(r-l>1){
				ll h=(l+r)/2;
				if(ask(bag[h],i))r=h,u=id;
				else l=h;
			}
			if(r==SZ(bag)){ // nadie dijo que si
				ans[i]=-1;
				continue;
			}
			if(r==14){
				ans[i]=0;
				if(ask(ex,i))ex=id;
				continue;
			}
			bag[r]=u;
			if(bag.back())bag.pb(0);
			pos[i]=r;
		}
		bag.back()=ex;
		// cerr<<"final: ";show(bag)
		fore(i,0,m)if(ans[i]==-2){
			ll l=pos[i],r=SZ(bag);
			while(r-l>1){
				ll h=(l+r)/2;
				if(ask(bag[h],i))r=h;
				else l=h;
			}
			ans[i]=r;
			if(ans[i]>14)ans[i]=0;
		}
		answer(ans);
	}
    return 0;
}
