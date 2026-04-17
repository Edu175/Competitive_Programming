#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	string rta = "4";
	ll i = 1, j = 0;		
	while(SZ(rta) < 3*n*(n+1)/2 - n){
		while(i<n) rta.pb('4'), i++;
		rta.pb('0'), j++;
		while(i>j) rta+="20", i--;
	}
	fore(i,0,n)rta.pb('2');
	cout<<rta<<"\n";
	return 0;
}