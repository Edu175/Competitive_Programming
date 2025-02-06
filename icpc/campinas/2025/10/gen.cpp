#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	TUCUTUCUTUCUTUCU
	ll n,m,V; cin>>n>>m>>V;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n){
		fore(j,0,m)cout<<rng()%V+1<<" ";
		cout<<"\n";
	}
	return 0;
}