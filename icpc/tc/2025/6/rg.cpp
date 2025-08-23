#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,M,V; cin>>N>>M>>V;
	ll n=rng()%(N-1)+2; cout<<n<<" ";
	ll m=rng()%(M)+1; cout<<m<<" ";
	ll s=rng()%n,t=rng()%(n-1);
	if(t>=s)t++;
	cout<<s+1<<" "<<t+1<<"\n";
	
	fore(i,0,m){
		ll s=rng()%n,t=rng()%(n-1);
		if(t>=s)t++;
		cout<<s+1<<" "<<t+1<<" "<<rng()%V+1<<"\n";
	}
	
	return 0;
}