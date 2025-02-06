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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll n;
vv a;

ll mn=-1,mx=-1;

void f(ll p, ll s, ll acum){
	if(p==n){
		// cout<<"f "<<p<<" "<<s<<" "<<acum<<"\n";
		if(s==0){
			if(mn==-1||acum<mn)mn=acum;
			if(mx==-1||acum>mx)mx=acum;
		}
		return;
	}
	// cout<<(min(s,a[p])+1)<<" lim\n";
	fore(c,0,(min(s,a[p])+1)){
		// cout<<"c "<<c<<"\n";
		ll ab=a[p]-c,now=s-c+ab;
		f(p+1,now,max(acum,now));
	}
}

int main(){
	JET
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	f(0,0,0);
	cout<<mn<<"\n"<<mx<<"\n";
	return 0;
}