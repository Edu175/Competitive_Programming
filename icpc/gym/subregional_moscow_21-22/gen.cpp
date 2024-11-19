#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N; cin>>N;
	int n = rng()%N+1;
	// cout<<n<<"\n";
	fore(i,0,n){
		int x = rng()%7;
		if(x==0) cout<<"I";
		if(x==1) cout<<"V";
		if(x==2) cout<<"X";
		if(x==3) cout<<"L";
		if(x==4) cout<<"C";
		if(x==5) cout<<"D";
		if(x==6) cout<<"M";
	}
}