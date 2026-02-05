#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng;
ll n;
ll ask(vv a){
	fore(i,0,n)cout<<a[i];;
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==n)exit(0);
	return ret;
}

vv getrand(){
	vv a;
	fore(i,0,n)a.pb(rng()&1);
	return a;
}

int main(){
	// JET
	// #ifdef ONLINE_JUDGE
	// freopen("jump.in","r",stdin);
	// freopen("jump.out","w",stdout);
	// #endif
	cin>>n;
	vv s=getrand();
	while(!ask(s))s=getrand();
	vv col(n);
	fore(i,0,n-1){
		vv t=s;
		t[i]^=1; t[i+1]^=1;
		col[i+1]=col[i];
		if(ask(t))col[i+1]^=1;
	}
	auto r=s;
	fore(i,0,n)r[i]^=col[i];
	ask(r);
	fore(i,0,n)r[i]^=1;
	ask(r);
	assert(0);
	return 0;
}