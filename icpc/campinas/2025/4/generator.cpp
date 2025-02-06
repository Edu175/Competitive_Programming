#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
random_device rd;
mt19937 rng(rd());
int main(){
	ll MAXN, MAXA; cin>>MAXN>>MAXA;
	MAXN-=2;
	MAXA--;
	ll n=rng()%MAXN+2;
	cout<<n<<"\n";
	fore(i,0,n){
		ll k=rng()%MAXA+1;
	}
}