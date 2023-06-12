#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
const ll MAXN=3e5+5, MAXS=1e15;

ll n,k;
ll a[MAXN];

bool can(ll x){
	vector<ll> p(n),s(n);
	priority_queue<ll>pq;
	ll sum=0;
	fore(i,0,n){
		if(sum+a[i]<=x)sum+=a[i],pq.push(a[i]);
		else if(SZ(pq)&&a[i]<pq.top())sum+=a[i]-pq.top(),pq.pop(),pq.push(a[i]);
		p[i]=SZ(pq);
	}
	while(SZ(pq))pq.pop();
	sum=0;
	for(ll i=n-1;i>=0;i--){
		if(sum+a[i]<=x)sum+=a[i],pq.push(a[i]);
		else if(SZ(pq)&&a[i]<pq.top())sum+=a[i]-pq.top(),pq.pop(),pq.push(a[i]);
		s[i]=SZ(pq);
	}
	//cout<<x<<":\n"<<p<<"\n"<<s<<"\n";
	ll flag=0;
	fore(i,0,n-1){
		if(p[i]+s[i+1]>=k)flag=1;
	}
	if(p[n-1]>=k||s[0]>=k)flag=1;
	return flag;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		//cout<<can(0)<<"\n"; continue;
		ll l=1, r=MAXS;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
