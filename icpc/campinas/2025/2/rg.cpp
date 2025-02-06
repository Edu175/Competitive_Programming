#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	cout<<"1\n";
	ll N,M,K; cin>>N>>M>>K;
	ll n=rng()%(N-2)+3,m=rng()%M+1,k=rng()%K+1;
	cout<<n<<" "<<m<<" "<<k<<"\n";
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		if(u>v)swap(u,v);
		cout<<u+1<<" "<<v+1<<"\n";
	}
	return 0;
}