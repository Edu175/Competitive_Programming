#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXL=18;

#define cf __builtin_ctzll

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	#endif
	vv pot10(MAXL),pot5(MAXL);
	pot10[0]=pot5[0]=1;
	fore(i,1,SZ(pot10))pot10[i]=pot10[i-1]*10;
	fore(i,1,SZ(pot5))pot5[i]=pot5[i-1]*5;
	
	ll k; cin>>k; k--;
	ll _k=k;
	vector<vector<ii>> a(2);
	a[0]={{0,0}};
	a[1]={{1,0}};
	fore(L,2,MAXL){
		if(k<SZ(a[1])){
			cout<<a[1][k].fst<<"\n";
			return 0;
		}
		k-=SZ(a[1]);
		vector<vector<ii>> prox(2);
		ll idx=L-1;
		fore(w,0,2)for(auto [v,s]:a[w]){
			if(cf(s)>=L){
				prox[0].pb({v,s});
				v+=pot10[idx];
				s+=(pot5[idx]-1)<<idx;
				prox[1].pb({v,s});
			}
		}
		swap(a,prox);
	}
	cerr<<_k-k<<" pasaron\n";
	assert(0);
	return 0;
}