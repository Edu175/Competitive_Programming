#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,D,K; cin>>N>>D>>K;
	ll n = rng()%N+2;
	multiset<ll> ms;
	fore(i,0,n) fore(j,0,(rng()%D) * 2) ms.insert(i);
	bool can = 1;
	vector<ii> ar;
	while(SZ(ms)){
		ll x = rng()%(SZ(ms));
		auto it = ms.begin();
		fore(i,0,x) it++;
		while(it != ms.end() && *it == *ms.begin())it++;
		if(it == ms.end()){
			can = 0;
			break;
		}
		ll i = *it, j = *ms.begin();
		ar.pb({i,j});
		ms.erase(ms.find(i)); ms.erase(ms.find(j));
	}
	if(!can){
		cout<<2<<" "<<1<<" "<<1<<"\n"<<1<<" "<<2<<" "<<1<<"\n";
		return 0;
	}
	cout<<n<<" "<<SZ(ar)<<" "<<K<<"\n";
	for(auto [x,y] : ar){
		cout<<x+1<<" "<<y+1<<" "<<rng()%K+1<<"\n";
	}
	
	return 0;
}