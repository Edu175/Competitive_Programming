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
string tra="RBG";

int main(){
	JET
	ll R,B; cin>>R>>B;
	string a; cin>>a;
	ll n=SZ(a);
	vector<vv>sp(3,vv(n+1));
	fore(h,0,3)fore(i,1,n+1){
		sp[h][i]=sp[h][i-1]+(a[i-1]==tra[h]);
	}
	auto cost=[&](ll l, ll m, ll r){
		ll rs=sp[0][m]-sp[0][l];
		ll bs=sp[1][r]-sp[1][m];
		ll gs0=sp[2][m]-sp[2][l]+sp[1][m]-sp[1][l]+max(0ll,rs-R);
		ll gs1=sp[2][r]-sp[2][m]+sp[0][r]-sp[0][m]+max(0ll,bs-B);
		ll q0=max(R-rs,gs0);
		ll q1=max(B-bs,gs1);
		// cout<<"cost "<<l<<" "<<m<<" "<<r<<": "<<rs<<","<<gs0<<" | "<<bs<<","<<gs1<<": "<<R-rs<<","<<gs0<<" | "<<B-bs
		return q0+q1;
	};
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--;
		ll res=R+B;
		// cout<<"query "<<s<<","<<e<<": ";
		// fore(m,s,e+1)if(m==n||a[m]!='G'){
		// 	ll c=cost(s,m,e);
		// 	res=min(res,c);
		// 	cout<<c<<" ";
		// }
		// cout<<" = ";
		cout<<res<<"\n";
	}
	return 0;
}