#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937_64 rng(rd());

int main(){JET;
	ll n; cin>>n;
	cout<<n<<"\n";
	ll P=1e5;
	ll prev=-1;
	fore(i,0,n){
		ll now=(rng()%P==0);
		if(prev&&now)now=0;
		prev=now;
		cout<<now<<" ";
	}
	cout<<"\n";
	fore(i,0,n){
		ll now=(rng()%P!=0);
		if(prev&&now)now=0;
		prev=now;
		cout<<now<<" ";
	}
	cout<<"\n";
}