#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ask(ll c, ll r){
	if(c==0)return r;
	cout<<"? "<<c<<" "<<r+1<<endl;
	ll ret; cin>>ret; ret--;
	return ret;
}

int main(){
	JET
	ll n; cin>>n;
	ll B=sqrt(n)+.5;
	ll x=ask(n,0);
	// cerr<<B<<" B\n";
	auto getz=[&](){
		vv pos(n,-1);
		fore(i,0,B){
			ll y=ask(i,x);
			if(pos[y]!=-1){
				assert(y==x);
				return i;
			}
			pos[y]=i;
		}
		// cerr<<"done pos\n";
		ll p=B;
		while(1){
			p=min(p,n);
			ll y=ask(p,x);
			if(pos[y]!=-1)return p-pos[y];
			p+=B;
		}
		assert(0);
	};
	ll z=getz();
	// cerr<<z<<" z\n";
	ll d=z-(x+1)%z;
	ll y=ask(d,x);
	assert(ask(x+1,y)==x);
	cout<<"! "<<x+1<<" "<<y+1<<endl;
	return 0;
}

