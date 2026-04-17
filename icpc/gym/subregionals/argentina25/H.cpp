#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll dame(vv a, ll n){ // -1 if invalid
	ll cuad=0,r=-1;
	if(SZ(a)%2==0){
		r=sqrtl(n);
		if(r*r!=n)return -1;
		cuad=1;
	}
	set<ll>st(ALL(a));
	vv out;
	for(auto i:st){
		if(n%i)return -1;
		ll j=n/i;
		if(!st.count(j))out.pb(j);
	}
	if(cuad&&!st.count(r))out.pb(r);
	if(SZ(out)!=1)return -1;
	return out[0];
}

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	if(a==vv(1,1)){
		cout<<"*\n";
		return 0;
	}
	sort(ALL(a));
	ll x=a.back();
	ll res=dame(a,x);
	if(res==-1){
		assert(a[0]==1);
		x=a[1]*a.back();
		assert(dame(a,x)==(res=x));
	}
	cout<<x<<" "<<res<<"\n";
	return 0;
}