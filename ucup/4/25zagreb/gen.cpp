#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	int n,q,V; cin>>n>>q>>V;
	cout<<n<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" "<<"LR"[rng()&1]<<"\n";
	cout<<q<<"\n";
	fore(i,0,q){
		ll l=rng()%n,r=rng()%n;
		if(l>r)swap(l,r);
		cout<<l+1<<" "<<r+1<<"\n";
	}
	return 0;
}