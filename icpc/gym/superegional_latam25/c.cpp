#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll n,k;
ll a[MAXN];
bool can(ll m){
	vv b(n);
	fore(i,0,n){
		b[i]=a[i]>=m;
	}
	ll cnt=0;
	fore(i,0,n){
		if(b[i])cnt=0;
		else {
			cnt++;
			if(cnt>k)return 0;
		}
	}
	return 1;
}

int main(){
	JET
	cin>>k>>n;
	fore(i,0,n)cin>>a[i];
	ll l=-100,r=100;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}