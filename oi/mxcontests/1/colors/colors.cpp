#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

set<ll>st;
ll ask(ll c){
	// cout<<"ask "<<c+1<<endl;
	
	// assert(!st.count(c));
	st.insert(c);
	cout<<"? "<<c+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll ask(ll a, ll b){
	ask(a); return ask(b);
}
void bf(ll n){
	ask(0);
	ll col=0,res=1;
	for(ll i=n-1;i>0;i--){
		ll c=col+(i%2==n%2?-i:i);
		if(!ask(c)){
			res=i+1;
			break;
		}
		col=c;
	}
	cout<<"= "<<res<<endl;
	exit(0);
}
int main(){FIN;
	ll n; cin>>n;
	if(n<=64)bf(n);
	ll l=1,r=n-1,did=0;
	while(l<=r){
		ll m=(l+r)/2;
		if(!did)m=n-10;
		did=1;
		ll p=n/2-m/2;
		if(st.count(p)||st.count(p+m)){
			fore(i,0,n-m)if(!st.count(i)&&!st.count(i+m)){
				p=i;break;}
		}
		// cout<<l<<","<<r<<": m "<<m<<": "<<p<<","<<p+m<<"\n";
		if(ask(p,p+m))r=m-1;
		else l=m+1;
	}
	cout<<"= "<<l<<endl;
	return 0;
}