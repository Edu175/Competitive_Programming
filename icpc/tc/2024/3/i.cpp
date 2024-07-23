#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
const ll f0=75, c1=34, c2=32, c3=2; 
const ll c=c1+c2+c3;
const ll MAXN=53;
const string s0="What are you doing at the end of the world? Are you busy? Will you save us?", s1="What are you doing while sending \"", s2="\"? Are you busy? Will you send \"", s3="\"?";
ll cuenta(ll n){
	return 75*(1ll<<(n))+68*((1ll<<(n))-1);
}
void solve(bool &y, ll &n, ll &k){
	if(y) return;
	if(n>0){
		if(k<=c1){
			cout<<s1[k-1];
			y=true; return;
		}
		k-=c1;
		if(n>MAXN || k<=cuenta(n-1)){
			n--;
			solve(y,n,k);
			return;
		}
		k-=cuenta(n-1);
		if(k<=c2){
			cout<<s2[k-1];
			y=true; return;
		}
		k-=c2;
		if(n>MAXN || k<=cuenta(n-1)){
			n--; solve(y,n,k);
			y=true; return;
		}
		k-=cuenta(n-1);
		if(k<=c3){
			cout<<s3[k-1];
			y=true; return;
		}
		cout<<"."; y=true; return;
	}
	if(k<=75) cout<<s0[k-1];
	else cout<<".";
	y=true;
	return;
}
int main(){
	JET
	short int q; cin>>q;
	while(q--){
		bool y=false;
		ll n,k; cin>>n>>k;
		solve(y,n,k);
	}
	cout<<"\n";
	
	
	

	return 0;
}