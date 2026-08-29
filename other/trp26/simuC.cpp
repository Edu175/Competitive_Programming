#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// random_device rd;
mt19937 rng(175);
const ll TRIES=1000;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(a));
	sort(ALL(b));
	if(a==b){
		cout<<"EMPATE\n";
		return 0;
	}
	vector<uniform_int_distribution<int>> as(n),bs(m);
	fore(i,0,n)as[i]=uniform_int_distribution<int>(1,a[i]);
	fore(i,0,m)bs[i]=uniform_int_distribution<int>(1,b[i]);
	ll cnt=0;
	fore(_,0,TRIES){
		ll val=0;
		fore(i,0,n)val+=as[i](rng);
		fore(i,0,m)val-=bs[i](rng);
		if(val>0)cnt++;
		if(val<0)cnt--;
		// cerr<<"try "<<_+1<<": "<<val<<"\n";
	}
	if(cnt>0)cout<<"ALICE\n";
	if(cnt<0)cout<<"BOB\n";
	if(cnt==0)cout<<"EMPATE\n";
	return 0;
}
