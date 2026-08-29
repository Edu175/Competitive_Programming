#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

int main(){
	JET
	ll n; cin>>n;
	string s; cin>>s;
	vv a(n);
	fore(i,0,n)a[i]=s[i]-'0';
	vv p3(n+5); p3[0]=1;
	fore(i,1,SZ(p3))p3[i]=mul(3,p3[i-1]);
	ll sdn=0,sd=0;
	ll res=0;
	fore(i,0,n){
		ll coef=p3[max(0ll,i-1)];
		ll sum=mul(coef,a[i]);
		
		ll concat=add(mul(sdn,10),mul(sd,a[i]));
		ll prod=mul(sdn,a[i]);
		
		ll cur=add(concat,add(prod,sum));
		
		ll agr=mul(cur,p3[max(0ll,n-1-i-1)]);
		res=add(res,agr);
		
		// cerr<<i<<":\n";
		// cout<<concat<<" "<<prod<<" "<<sum<<"\n";
		// cout<<cur<<": "<<agr<<"\n";
		
		sd=add(sd,add(coef,sdn));
		sdn=cur;
		
		// cerr<<sdn<<" "<<sd<<"\n\n";
	}
	cout<<res<<"\n";
	return 0;
}

