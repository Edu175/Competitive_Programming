#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){
	ll n; 
	srand(ll(&n));
	cin>>n;
	string s; cin>>s;
	string res;
	/*ll r=rand()%n;
	fore(i,0,r)res+=s[0];
	fore(i,r,n)res+=s[1];
	cout<<s<<"\n"<<res<<"\n";
	return 0;*/
	fore(i,0,n){
		res.pb(s[rand()%SZ(s)]);
	}
	cout<<s<<"\n"<<res<<"\n";
	return 0;
}
