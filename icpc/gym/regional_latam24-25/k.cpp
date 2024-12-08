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
	ll k; cin>>k; string s; cin>>s;
	ll n=SZ(s);
	if(k==2){
		string a(n,'0'), b(n,'1');
		fore(i,0,n){
			if(i&1) {a[i]='1'; b[i]='0';}
		}
		ll A=0; ll B=0;
		fore(i,0,n){
			if(s[i]==a[i]) A++;
			else B++;
		}
		if(A<B) cout<<n-B<<" "<<b;
		else cout<<n-A<<" "<<a;
		return 0;
	}
	ll a=1, u=-1,cnt=0;
	fore(i,1,n){
		if(s[i]==s[i-1]) a++;
		else {u=i-1; a=1;}
		if(a==k){
			if(u!=-1&&s[u]==s[i]) {swap(s[u],s[u-1]); a--; continue;}
			s[i]=(s[i]-'0'?'0':'1');
			cnt++;
			a=1;
			u=i;
		}
	}
	cout<<cnt<<" "<<s<<"\n";
	return 0;
}
//3 01000011000001100000011
//4 01001011001001101000111