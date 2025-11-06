#include<bits/stdc++.h>
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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	set<string> st;
	fore(i,0,n){
		string s;
		cin>>s;
		string s1="";
		bool b = true;
		bool ar = false;
		for(auto x:s){
			if((x== '+') && !ar) b = false;
			if(x == '@'){
				b = true;
				ar = true;
			}
			if(x == '.'){
				if(ar) s1.pb(x);
				continue;
			}
			if(b)s1.pb(x);
		}
		st.insert(s1);
	}
	// for(auto x:st) cout<<x<<"\n";
	cout<<SZ(st)<<"\n";
	return 0;
}