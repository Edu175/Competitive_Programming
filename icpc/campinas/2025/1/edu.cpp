#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,M,Q; cin>>N>>M>>Q;
	ll n=N,m=M,q=Q;
	cout<<n<<" "<<m<<" "<<q<<"\n";
	vv per(n); iota(ALL(per),1);
	fore(i,1,n){
		cout<<per[rng()%i]<<" "<<per[i]<<" "<<rng()%m+1<<"\n";
	}
	string s="ZB";
	fore(_,0,q){
		ll ty=rng()&1;
		cout<<s[ty]<<" ";
		if(!ty){
			cout<<rng()%n+1<<"\n";
		}
		else {
			cout<<rng()%(n-1)+1<<" "<<rng()%m+1<<"\n";
		}
	}
}