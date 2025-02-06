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

int main(){
	TUCUTUCUTUCUTUCU
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll lnu=-1;
	fore(i,0,n)if(a[i]!=1)lnu=i;
	if(n==1)cout<<"0\n";
	else { // prox
		ll p=n-2;
		auto b=a;
		while(p-1>=0&&b[p-1]==b[n-2])p--;
		// a b[p] le sumo 1
		b[p]++;
		ll sum=-1;
		while(SZ(b)-1>p)sum+=b.back(),b.pop_back();
		fore(i,0,sum)b.pb(1);
		// sort(ALL(b)); reverse(ALL(b));
		for(auto i:b)cout<<i<<" ";;cout<<"\n";
	}
	if(lnu==-1)cout<<"0\n";
	else { // prev
		auto b=a;
		b[lnu]--;
		ll num=b[lnu];
		ll c=n-lnu;
		while(SZ(b)-1>lnu)b.pop_back();
		fore(i,0,c/num)b.pb(num);
		ll rem=c%num;
		if(rem)b.pb(rem);
		for(auto i:b)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}