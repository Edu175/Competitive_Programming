#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
int main(){
	JET
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2; cout<<n<<"\n";
	vector<ii>all;
	fore(i,0,V)fore(j,0,V)all.pb({i,j});
	shuffle(ALL(all),rng);
	fore(i,0,n){
		cout<<all[i].fst<<" "<<all[i].snd<<"\n";
	}
	// fore(i,0,n){
	// 	cout<<rng()%(V+1);
	// 	cout<<" ";
	// 	cout<<rng()%(V+1);
	// 	cout<<"\n";
	// }
	return 0;
}