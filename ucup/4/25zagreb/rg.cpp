#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	cout<<"1\n";
	ll N,Q,V; cin>>N>>Q>>V;
	auto get=[&](){
		ll ret=rng()%(2*V+1);
		ret-=V;
		return ret;
	};
	ll n=rng()%N+1,q=rng()%Q+1;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<get()<<" ";;cout<<"\n";
	fore(i,0,q)cout<<get()<<" ";;cout<<"\n";
	return 0;
}