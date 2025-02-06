#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool check(ll x){
	ll x2=x;
	while(x2>0){
		if(x2%10==0) return false;
		if(x%(x2%10)!=0) return false;
		x2/=10;
	}
	return true;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	ll rta=0;
	fore(i,n,m+1){
		if(check(i))rta++;
	}
	cout<<rta<<"\n";
	return 0;
}