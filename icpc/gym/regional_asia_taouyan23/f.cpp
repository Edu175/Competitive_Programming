#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool f(pair<ll,ii> a, pair<ll,ii> b){
	if(b.snd.snd*a.snd.fst==a.snd.snd*b.snd.fst) return a.fst<b.fst;
	return b.snd.snd*a.snd.fst<a.snd.snd*b.snd.fst;
}

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<pair<ll,ii>> a(n);
		fore(i,0,n) cin>>a[i].snd.fst>>a[i].snd.snd;
		fore(i,0,n) a[i].fst=i+1;
		sort(ALL(a),f);
		fore(i,0,n) cout<<a[i].fst<<" ";
		cout<<"\n";
	}
	return 0;
}