#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;


ll C(ll n, ll k){
	return (n|k)==n;
}

int main(){
	JET
	ll n,k,q; cin>>n>>k>>q;
	vv d(n);
	fore(i,1,n){
		ll p; cin>>p; p--;
		d[i]=d[p]+1;
	}
	vv val(n);
	fore(i,0,n)val[i]=C(d[i]+k-1,k-1);
	// fore(i,0,n){
	// 	cout<<val[i]<<" ";
	// }cout<<"\n";
	while(q--){
		vv s(n);
		ll res=0;
		fore(i,0,n){
			cin>>s[i];
			if(val[i])res^=s[i];
		}
		// cout<<"query "<<q<<": ";
		// cout<<"= ";
		cout<<res<<"\n";
	}
	return 0;
}


/*
3 2 1
1 2 
1 1 0 


1 0 1 
0


*/