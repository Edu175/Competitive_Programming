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
const ll C=1e9;

ll dis(ii a, ii b){return abs(a.fst-b.fst)+abs(a.snd-b.snd);}

ii P1={C,C},P2={C,-C};
ll ult;
ll move(char c, ll k){
	cout<<"? "<<c<<" "<<k<<endl;
	ll ret; cin>>ret;
	ult=ret;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll d1=100*C,d2=d1;
		fore(i,0,n){
			d1=min(d1,dis(a[i],P1));
			d2=min(d2,dis(a[i],P2));
		}
		move('U',C);
		move('U',C);
		move('R',C);
		move('R',C);
		ll q1=ult-d1+2*C;
		fore(_,0,4)move('D',C);
		ll q2=ult-d2+2*C;
		ll y=q1-q2+4*C;
		assert(y%2==0); y/=2;
		ll x=q1-y;
		x-=2*C;
		y-=2*C;
		cout<<"! "<<x<<" "<<y<<endl;
	}
	return 0;
}
