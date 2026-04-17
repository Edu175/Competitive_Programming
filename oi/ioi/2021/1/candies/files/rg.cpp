#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fjhg:v)cout<<fjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	ll N,Q,V; cin>>N>>Q>>V;
	ll n=rng()%N+1,q=rng()%Q+1;
	cout<<n<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
	cout<<q<<"\n";
	fore(i,0,q){
		ll u=rng()%n,v=rng()%n;
		if(u>v)swap(u,v);
		ll w=(rng()%(2*V+1)-V);
		cout<<u<<" "<<v<<" "<<w<<"\n";
	}
}