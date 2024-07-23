#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e3;
ll a[MAXN];
ll h,n;
bool can(ll m){
	priority_queue <ll> b;
	fore(i,0,m) {
		b.push(a[i]);
	}
	ll hc=0;
	while(!b.empty() || hc<=h){
		if(hc+b.top()<=h){
			hc+=b.top();
			b.pop();
			if(b.empty()) continue;
			if(!b.empty()) b.pop();
		}
		else break;
	}
	return b.empty();
}

int main(){
	JET
	 cin>>n>>h;
	fore(i,0,n) {
		cin>>a[i];
	}
	ll l=0, r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}