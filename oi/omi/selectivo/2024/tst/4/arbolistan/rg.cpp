#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2;
	vector<ll>u,v,w;
	fore(i,1,n){
		u.pb(rng()%i),v.pb(i),w.pb(rng()%V+1);
	}
	cout<<"1\n\n";
	cout<<n<<"\n";
	imp(u); imp(v); imp(w);
	return 0;
}