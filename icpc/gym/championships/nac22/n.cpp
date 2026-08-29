#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
mt19937 rng(175);
char letra(char dif){
	ll prev=dif-'a';
	ll p=(prev+1)%26;
	return 'a'+p;
}

int main(){
	JET
	ll n; cin>>n;
	string s;
	fore(i,0,10)s.pb(letra('z'+1));
	ll prev=10;
	fore(i,0,n){
		cout<<s<<"\n";
		ll p=(prev+1)%10;
		s[p]=letra(s[p]);
		prev=p;
	}
	return 0;
}