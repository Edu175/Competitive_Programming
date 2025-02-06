#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


int main(){
	JET
	vv v(3);
	fore(i,0,3) cin>>v[i];
	sort(ALL(v));
	if(v[0]==v[2]){
		cout<<"YES\n";
		return 0;
	}
	reverse(ALL(v));
	if(v[1]==v[2] && v[1]+v[2]==v[0]){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}