#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	ll s=0;
	set<ll>st;
	// st.insert(0);
	ll cnt=0;
	fore(i,0,n){
		ll x=a[i];
		s+=x;
		cnt+=st.count(s-sum/2);
		st.insert(s);
		// cout<<s<<" s\n";
	}
	// cout<<sum/2<<" mitad\n";
	if(cnt>=2&&sum%2==0)cout<<"Y\n";
	else cout<<"N\n";
	return 0;
}