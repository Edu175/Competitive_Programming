#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
	ll cs[28];
	ll ct[28];
	
int main(){
	JET
	string s,t;
	getline(cin,t);
	getline(cin,s);
	string r;
	fore(i,0,SZ(t)){
		if(t[i]!=' ') ct[t[i]-'a']++;
		else ct[27]++;
	}
	fore(i,0,SZ(s)){
		if(s[i]!=' ') cs[s[i]-'a']++;
		else cs[27]++;
	}
	fore(i,0,27){
		if(cs[i]!=ct[i]) r.pb(i+'a');
	}
	if(cs[27]!=ct[27]) r.pb(' ');
	cout<<r<<"\n";
	
}