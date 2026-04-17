#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ll n; cin>>n;
	cin.ignore();
	map<string,string> mp;
	fore(i,0,n){
		string s;
		getline(cin,s);
		// cout<<s<<"\n";
		string s1 = s;
		reverse(ALL(s1));
		while(SZ(s1) && (s1.back()>'Z'|| s1.back()<'A')) s1.pop_back();
		reverse(ALL(s1));
		mp[s1] = s;		
	}
	for(auto [x,y] :mp) cout<<y<<"\n";
	return 0;
}