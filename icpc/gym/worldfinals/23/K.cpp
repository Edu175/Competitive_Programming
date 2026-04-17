#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
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
	string s; cin>>s;
	string r(1,s[0]);
	fore(i,1,SZ(s)) if(s[i]!=s[i-1]) r.pb(s[i]);
	while(SZ(r)>3) fore(i,0,2)r.pop_back();
	cout<<r<<"\n";
	return 0;
}