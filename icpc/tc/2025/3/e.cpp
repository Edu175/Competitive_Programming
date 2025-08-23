#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int maxn = 4e5;
ll v[maxn];
int main(){
	JET
	string s;
	cin>>s;
	// s.pb('#');
	// v[0] = 1;
	string r ="";
	// r.pb((s[0]));
	fore(i,0,SZ(s)){
		if(SZ(r)==0)r.pb(s[i]);
		else if(r.back()==s[i]) r.pop_back();
		else r.pb(s[i]);
	}
	cout<<r<<"\n";
	return 0;
}