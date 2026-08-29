#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll n=5e5;
random_device rd;
mt19937 rng(rd());
const ll MAXW=1e9;
int main(){
	JET
	cout<<n<<" "<<n<<"\n";
	fore(i,1,n){
		ll v=rng()%i+1;
		ll w=rng()%MAXW+1;
		cout<<v<<" "<<w<<"\n";
	}
	fore(i,0,n){
		ll u=rng()%n+1;
		ll r=rng()%n+1;
		ll l=rng()%r+1;
		cout<<u<<" "<<l<<" "<<r<<"\n";
	}
	
	return 0;
}