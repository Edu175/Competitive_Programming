#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	vv b(n);
	ll cant=0;
	set<ll> st;
	fore(r,0,n-1+m){
		if(r<n)st.insert(r);
		ll l=r-m;
		if(l>=0)cant-=b[l];
		st.erase(l);
		while(SZ(st)&&cant<k){
			auto i=*st.rbegin();
			ll q=min(k-cant,a[i]-b[i]);
			b[i]+=q;
			cant+=q;
			res+=q;
			if(a[i]==b[i])st.erase(i);
		}
	}
	cout<<res<<"\n";
	return 0;
}