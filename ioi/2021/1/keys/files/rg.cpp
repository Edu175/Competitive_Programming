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
	ll N,M,V; cin>>N>>M>>V;
	ll n=N/*(rng()%(N-1)+2)*/,m=rng()%M; V=min(V,n);
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n)cout<<rng()%V<<" ";;cout<<"\n";
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		cout<<u<<" "<<v<<" "<<rng()%V<<"\n";
	}
}