#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i+1<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

ll k;

bool check(vv &a){
	ll n=SZ(a);
	vv per(k); iota(ALL(per),0);
	do{
		ll j=0;
		fore(i,0,n){
			if(j>=k)break;
			j+=per[j]==a[i];
		}
		if(j<k)return 0;
	}while(next_permutation(ALL(per)));
	return 1;
}

int main(){
	ET;
	cin>>k;
	ll pot=1;
	fore(n,14,k*k+3){
		cerr<<n<<endl;
		pot*=k;
		fore(mk,0,pot){
			vv a; ll mki=mk;
			fore(i,0,n)a.pb(mki%k),mki/=k;
			if(check(a)){
				imp(a)
				exit(0);
			}
		}
	}
}