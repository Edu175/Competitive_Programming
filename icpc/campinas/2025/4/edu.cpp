#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
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
	ll n,m,k,V; cin>>n>>m>>k>>V;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,m)cout<<rng()%n+1<<" ";;cout<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
	cout<<k<<"\n";
	fore(i,0,k){
		ll l=rng()%m+1,r=rng()%n+1;
		if(l<r)swap(l,r);
		cout<<l<<" "<<r<<" "<<rng()%V+1<<"\n";
	}
	return 0;
}