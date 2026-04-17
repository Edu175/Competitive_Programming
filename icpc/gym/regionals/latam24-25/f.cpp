#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
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
	ll k,n; cin>>k>>n;
	ll flag=k==n/2;
	auto good=[&](ll k, ll n)->bool{
		if(n==-2)return 0;
		return 2*k-1<=n&&n<=3*k;
	};
	if(!good(k,n)){
		cout<<"*\n";
		return 0;
	}
	string ret(n,'-');
	fore(i,0,n){
		// cout<<i<<": "<<ret<<endl;
		if(good(k-1,n-i-3)){
			ret[i+1]='X';
			i+=2;
		}
		else {
			assert(good(k-1,n-i-2));
			ret[i]='X';
			i++;
		}
		k--;
	}
	cout<<ret<<"\n";
	return 0;
}