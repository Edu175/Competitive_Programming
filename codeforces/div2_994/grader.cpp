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

ll ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){FIN;
	// ifstream pingo;   pingo.open("pre", ios::in);
	// ofstream pone;   pone.open("out", ios::out);
	ll n=8,p=5,k=6; //pingo>>n>>p>>k; // 0 idx
	// n=1ll<<n;
	// pone<<n<<" n"<<"\n";
	cout<<"1"<<endl;
	// <<n<<endl;
	return 0;
	// ll qs=0;
	// while(1){
	// 	char ty; cin>>ty;
	// 	if(ty=='!'){
	// 		ll ans; cin>>ans;
	// 		if(ans==k)pone<<"OK\n";
	// 		else pone<<"WA\n";
	// 		pone<<"answered "<<ans<<"\n";
	// 		break;
	// 	}
	// 	qs++;
	// 	ll l,r; cin>>l>>r; l--;
	// 	ll ret=(r-l)>=k;
	// 	if(l<=p&&p<r)ret^=1;
	// 	// pone<<" query "<<ty<<" "<<qs<<": "<<l+1<<" "<<r<<": "<<ret<<"\n";
	// 	cout<<ret<<endl;
	// }
	// pone<<"Made "<<qs<<" queries\n";
	return 0;
}

// (./a < fifo) | (./g > fifo)