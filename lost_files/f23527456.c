#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	set<ll>st;
		
	fore(i,0,n){
		cin>>a[i],st.insert(a[i]);
	}
	cout<<SZ(st))<<"\n";
	return 0;
}
