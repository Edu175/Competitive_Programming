#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	ll t; cin>>t;
	fore(i,0,t){
		string s; cin>>s;
		if(s=="WIN" || s=="LOSE") return 0;
		int n,k; cin>>n>>k;
		if(n/2<=k) cout<<"SKIP\n";
		else cout<<"PLAY\n";
	}
}