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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int c,d;
		cin>>c>>d;
		if(c==0 && d==0){
			cout<<0<<"\n";
			continue;
		}
		ll rta=1;
		fore(i,0,c) rta*=26;
		fore(i,0,d) rta*=10;
		cout<<rta<<"\n";
	}
	return 0;
}