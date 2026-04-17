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
	ll t; cin>>t;
	while(t--){
		ll n,h,k; cin>>n>>h>>k;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].snd-=a[i].fst;
		sort(ALL(a));
		do{
			ll c=0,hi=h;
			for(auto [x,y]:a)if(hi>=x){
				hi+=y;c++;
			}
			if(k>=n-c){
				cout<<"Y\n";
				goto arafue;
			}
		}while(next_permutation(ALL(a)));
		cout<<"N\n";
		arafue:
		assert(1);
	}
	return 0;
}