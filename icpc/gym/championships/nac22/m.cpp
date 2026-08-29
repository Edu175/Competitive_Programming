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

ll m[5];
ll add(){
	for(ll i=4; i>=0; i--){
		if(m[i]==25) m[i]=0;
		else{
			m[i]++;
			return i;
		}
	}
	assert(0);
	return -1;
}
void addmod(char &c){
	c+=1;
	if(c>'z') c='a';
}
// ll dif(string &s, string &t){
// 	assert(SZ(s)==SZ(t));
// 	ll r=0;
// 	fore(i,0,SZ(s)) r+=(s[i]==t[i]);
// 	return r;
// }
// bool check(vector<string> &v){
// 	ll n=SZ(v),k=SZ(v[0]);
// 	fore(i,1,n){
// 		if(dif(v[i-1],v[i])!=k-1) return false;
// 		fore(j,0,i-1){
// 			if(dif(v[j],v[i])>=k-1) return false;
// 		}
// 	}
// 	return true;
// }
int main(){
	JET
	ll n; cin>>n;
	string s(10,'a');
	vector<string> v={s};
	while(SZ(v)<n){
		ll i=add();
		addmod(s[2*i+1]);
		v.pb(s);
		addmod(s[2*i]);
		v.pb(s);
	}
	// assert(check(v));
	// cout<<"YES\n";
	fore(i,0,n) cout<<v[i]<<"\n";
	return 0;
}