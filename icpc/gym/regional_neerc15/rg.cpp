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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());


int main(){
	ll W,N; cin>>W>>N;
	cout<<W<<" "<<N<<"\n";
	fore(i,0,N){
		int x = rng()%W;
		if(!x) x++;
		cout<<x<<" ";
		int y = rng() % ((ll)1e9);
		if(rng()%2)cout<<-y;
		else cout<<y;
		cout<<"\n";
	}
}