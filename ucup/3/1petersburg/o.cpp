#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
typedef pair<ld,ld> dd;
typedef pair<dd,dd> mx;
mx operator*(mx A, mx B){
	mx R;
	R.fst.fst=A.fst.fst*B.fst.fst+A.fst.snd*B.snd.fst;
	R.fst.snd=A.fst.fst*B.fst.snd+A.fst.snd*B.snd.snd;
	R.snd.fst=A.snd.fst*B.fst.fst+A.snd.snd*B.snd.fst;
	R.snd.snd=A.snd.fst*B.fst.snd+A.snd.snd*B.snd.snd;
	return R;
}
mx pm(mx A, ll n){
	mx R=mx({dd({1.,0.}),dd({0.,1.})});
	while(n){
		if(n&1) R=R*A;
		A=A*A;
		n>>=1;
	}
	return R;
}
int main(){FIN;
	ld a,b,x1,xn; ll n;
	cin>>a>>b>>n>>x1>>xn;
	mx M=mx({dd({a,b}),dd({1.,0.})});
	M=pm(M,n-2);
	ld x2=(xn-M.fst.snd*x1)/M.fst.fst;
	cout<<x1<<"\n"<<x2<<"\n";
	fore(i,0,n-2){
		x1=a*x2+b*x1;
		cout<<x1<<"\n";
		swap(x1,x2);
	}
	return 0;
}
