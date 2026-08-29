#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	string N,M; cin>>M>>N;
	string MN=M+N;
	ll k=0; vv ids;
	fore(i,0,SZ(MN)){
		if(MN[i]=='*'){
			ids.pb(i);
			k++;
		}
	}
	fore(mk,0,1<<k){
		fore(i,0,k) MN[ids[i]]='0'+(mk>>i&1);
		M=MN.substr(0,SZ(M)); N=MN.substr(SZ(M),SZ(N));
		ll n=0;
		fore(i,0,SZ(N)){
			n<<=1;
			if(N[i]=='1') n|=1;
		}
		if(!n) continue;
		ll p=1;
		ll m=0;
		for(ll j=SZ(M)-1; j>=0; j--){
			if(M[j]=='1') m+=p, m%=n;
			p*=2;p%=n;
		}
		if(!m){
			cout<<M<<"\n";
			return 0;
		}
	}
	assert(!k);
	cout<<M<<"\n";
	return 0;
}