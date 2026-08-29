#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ld ev(ld N, ld M, ld K){
	return K/(N+M);
}
int main(){
	JET
	ll n; cin>>n;
	ll A,k; cin>>A>>k;
	string s,t; cin>>s>>t;
	ll G=0,B=0,C1=0,uu=0;
	ld rta=0.L;
	fore(i,0,n){
		if(s[i]=='0'&&t[i]=='0'){
			G++;
		}
		if(s[i]=='0' && t[i]=='1') C1++;
		if(s[i]=='1' &&t[i]=='0') B++;
		if(s[i]=='1'&&t[i]=='1') uu++;
	}
	if(A >= G+C1 || k>=B+G){
		cout<<n<<"\n";
		return 0;
	}
	
	rta=uu+B+C1;
	ld e1=ev(G,B,k),e2=ev(G,C1,A);
	rta+=ld(G)*(e1+e2-e1*e2);
	
	cout<<fixed<<setprecision(16)<<rta<<"\n";
	return 0;
}