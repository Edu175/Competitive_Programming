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

int main(){
	JET
	int n; cin>>n;
	if(n<4){
		cout<<"-1\n";
		return 0;
	}
	cout<<n+1<<"\n";
	cout<<1<<" "<<2<<"\n";
	cout<<1<<" "<<3<<"\n";
	cout<<1<<" "<<4<<"\n";
	cout<<2<<" "<<4<<"\n";
	cout<<2<<" "<<3<<"\n";
	fore(i,5,n+1){
		cout<<1<<" "<<i<<"\n";
	}
}