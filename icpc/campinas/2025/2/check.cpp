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
ll exp(ll a, ll b){
	ll r=1;
	while(b){
		if(b&1)r*=a;
		a*=a,b>>=1;
	}
	return r;
}

int main(){
	JET
	ll n; cin>>n;
	ll t; cin>>t;
	n=exp(10,n);
	n--;
	cout<<t<<"\n";
	random_device rd;
	mt19937 rng(rd());
	fore(i,0,t){
		ll k=rng()%n;
		k++;
		cout<<k<<"\n";
	}
	return 0;
}