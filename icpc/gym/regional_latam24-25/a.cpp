#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
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
	string s; cin>>s;
	int a[27];mset(a,0);
	fore(i,0,SZ(s)){
		a[s[i]-'A']++;
	}
	ll aux=0;
	fore(i,0,27) if(a[i]) aux++;
	cout<<SZ(s)-aux<<"\n";
	return 0;
}