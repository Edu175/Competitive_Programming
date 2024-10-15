#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv t(n); fore(i,0,n) cin>>t[i];
	sort(ALL(t));
	ll m=n>>1;
	m-=!(n&1);
	//cout<<"m: "<<m<<"\n";
	cout<<t[m];
	fore(i,1,(n+1)/2+1){
	//	cout<<"i: "<<i<<"\n";
		if(m+i<n)	cout<<" "<<t[m+i];
		if(m-i>=0) cout<<" "<<t[m-i];
	}
	cout<<"\n";
}