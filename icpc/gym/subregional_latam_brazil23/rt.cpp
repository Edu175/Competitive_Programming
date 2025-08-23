#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef ll tf;
typedef vector <tf> poly;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const tf MOD=998244353;

ll mulmod(ll a, ll  b){
	return a*b%MOD;
}
ll pm(ll a, ll b){
	ll res=1ll;
	while(b){
		if(b&1)res=mulmod(res,a);
		a=mulmod(a,a);b/=2;
	}
	return res;
}
random_device rd;
mt19937 rng(rd());
int main(){
	bool y=true;	
	ll x=1;
	while(y){
		x=998244350;
		while(x==0 || x==1) x=rand()%MOD;
		ll r=x;
		ll k=1;
		while(r!=1){
			k++;
			r=mulmod(r,x);
		}
		if(k==MOD-1) y=false;
		else cout<<"LOLO";
	}
	cout<<x<<"\n";
}