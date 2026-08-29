#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

ll rnd(ll r){ // [0,r]
	return rng()%(r+1);
}

int main(){
	JET
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-2)+3; cout<<n<<"\n";
	cout<<rnd(V)<<" "<<rnd(V)<<"\n";
	fore(i,0,n-1)cout<<rnd(V)<<" ";;cout<<"\n";
	return 0;
}