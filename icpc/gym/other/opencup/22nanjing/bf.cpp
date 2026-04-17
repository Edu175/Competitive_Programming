#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll get(vv a){
	ll n=SZ(a),res=0;
	fore(i,0,n)fore(j,0,n){
		if(a[i]<a[j]){
			res++;
			swap(a[i],a[j]);
		}
	}
	return res;
}

int main(){
	JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b;
		fore(i,0,n){
			b.pb(a[i]);
			if(i)cout<<" ";
			cout<<get(b);
		}
		cout<<"\n";
	}
	return 0;
}

