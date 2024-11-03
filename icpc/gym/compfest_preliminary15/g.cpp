#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
// test 17 de mierda

vector<ii> upds[MAXN];
ll n;
ll can(ll k){
	priority_queue<ii>pq;
	fore(i,0,n){
		for(auto j:upds[i])pq.push(j);
		if(SZ(pq)&&-pq.top().fst<i)return 0;
		ll ki=k;
		while(SZ(pq)&&ki>0){
			auto [r,v]=pq.top(); pq.pop();
			ll q=min(v,ki);
			ki-=q,v-=q;
			if(v)pq.push({r,v});
		}
	}
	return !SZ(pq);
}

int main(){
	JET
	cin>>n;
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n){
		ll l=i-b[i],r=i+b[i];
		l=max(l,0ll);
		r=min(r,n-1);
		if(a[i])upds[l].pb({-r,a[i]});
	}
	ll l=0,r=1e9+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}