#include<bits/stdc++.h>
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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ll n; cin>>n;
	ll a[n]; iota(a,a+n,0);
	vector<ii> s;
	fore(i,0,n) fore(j,0,i) s.pb({i,j});
	vector<vector<ii>> R;
	do{
		iota(a,a+n,0);
		fore(i,0,SZ(s)){
			swap(a[s[i].fst],a[s[i].snd]);
		}
		ll f=1;
		fore(i,0,n) f&=(a[i]==i);
		if(f && s[0]==(ii){1,0}){R.pb(s);}
	}while(next_permutation(ALL(s)));
	for(auto S: R){
		for(auto [i,j]: S){
			cout<<"("<<i<<","<<j<<") ";
		}
		cout<<"\n";
	}
}