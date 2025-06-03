#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll n; cin>>n;
	vector<vv>a(n,vv(n));
	// fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	fore(i,0,n)fore(j,0,n)a[i][j]=rng()&1;
	// fore(i,0,n)fore(j,0,n)a[i][j]=(i+j)&1;
	ll cant=0;
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j];
		cout<<"\n";
	}
	fore(mk,0,1<<n)fore(mk2,0,1<<n){
		ll good=1;
		vector<vv>sums(2);
		fore(sw,0,2)fore(i,0,n){
			if(!good)break;
			ll sum=0;
			fore(j,0,n){
				ll i_=i,j_=j;
				if(sw)swap(i_,j_);
				sum+=(mk>>i_&1)^(mk2>>j_&1)^a[i_][j_];
			}
			sums[sw].pb(sum);
			if(sum>=n/2){good=0;break;}
		}
		cant+=good;
		if(good){
			cout<<mk<<" "<<mk2<<"\n";
			imp(sums[0])
			imp(sums[1])
		}
	}
	cout<<cant<<"\n";
	return 0;
}
