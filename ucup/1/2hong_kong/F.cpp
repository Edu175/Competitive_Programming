#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

string a;
ll n;

string suma(string a,string b){
	string res = "";
	if(SZ(a) < SZ(b)) swap(a,b);
	reverse(ALL(a));reverse(ALL(b));
	bool carry = 0;
	fore(i,0,SZ(a)){
		ll aux_a = a[i]-'0', aux_b = i>=SZ(b) ? 0 : b[i] - '0';
		ll aux = aux_a + aux_b + carry;
		res.pb('0'+aux%10);
		if(aux >= 10) carry = 1;
		else carry = 0;
	}
	if(carry) res.pb('0'+1);
	reverse(ALL(res));
	return res;
}

string les(string a, string b){
	if(a == "#") return b;
	if(b == "#") return a;
	if(SZ(a) < SZ(b)) return a;
	if(SZ(b) < SZ(a)) return b;
	return min(a,b);
}


string f(int x, int k, int ant, bool b){
	string r ="#";
	// cout<<"entra a "<<x<<" "<<k<<" "<<ant<<" "<<b<<"\n";
	if(k==-1){
		if(x == n) return "";
		else return r;
	}
	if(x+ant-1 <= n && !b && ant>1){
		// cout<<x<<" "<<ant-1<<endl;
		string op1 = a.substr(x,ant-1);
		string s1 = f(x+ant-1,k-1,ant-1,0);
		if(s1 != "#") r = les(r,suma(op1,s1));		
	}
	if(x+ant <= n){
		string op2 = a.substr(x,ant);
		string s2 = f(x+ant,k-1,ant,0);
		if(s2!="#") r = les(r,suma(op2,s2));
	}
	if(x+ant+1<=n && !b){
		string op3 = a.substr(x,ant+1);
		string s3 = f(x+ant+1,k-1,ant+1,0);
		if(s3 != "#") r  = les(r,suma(op3,s3));
	}
	return r;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		a.resize(n);
		fore(i,0,n) cin>>a[i];
		ll l = max(0ll,(n+k)/(k+1) - 3);
		ll r = n/(k+1)+3+1;
		string res = "#";
		fore(i,l,r)res = les(res,f(0,k,i,1));
		cout<<res<<"\n";
	}
	
	return 0;
}