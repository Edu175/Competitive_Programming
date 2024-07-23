#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
const ll mod=998244353;
ll mul(ll a,ll b){
	return a*b%mod;
}
ll fpow(ll a, ll b){
	if(b==0) return 1ll;
	ll res=fpow(a,b/2);
	if(b&1) return mul(res,mul(res,a));
	else return mul(res,res);
	
}
ll fc[MAXN], fci[MAXN];
void factos(){
	fc[0]=1;
	fore(i,1,MAXN) fc[i]=mul(fc[i-1],i);
	fci[MAXN-1]=fpow(fc[MAXN-1],mod-2);
	for(ll i=MAXN-2;i>=0; i--) fci[i]=mul(fci[i+1],(i+1));
}
int main(){
	JET
	int t; cin>>t;
	factos();
	while(t--){
		int n; cin>>n;
		vector<char>a(n);
		ll q=0,z=0,c=0;
		fore(i,0,n){
			cin>>a[i];
			a[i]-='0';
			if(!a[i])z++,c+=q/2,q=0;
			else q++;
		}
		c+=q/2;
		cout<<mul(fc[z+c],mul(fci[c],fci[z]))<<"\n";
	}
	return 0;
}