#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ll MAXV=1e4+5;
vector<ii> rans;
vector<ld> tot;
ll n;
bool in(ll t, ll l, ll r){return l<=t&&t<r;}

int main(){
	JET
	cin>>n;
	rans.resize(n); tot.resize(n);
	fore(i,0,n)cin>>rans[i].fst>>rans[i].snd,rans[i].snd++;
	fore(i,0,n)tot[i]=rans[i].snd-rans[i].fst;
	vv pot3(n+3,1); fore(i,1,SZ(pot3))pot3[i]=pot3[i-1]*3;
	
	ld res=0;
	
	fore(mk,0,pot3[n]){
		vv typ(n);
		ll mki=mk;
		fore(i,0,n)typ[i]=mki%3,mki/=3;
		ll c1=count(ALL(typ),1);
		ll c2=count(ALL(typ),2);
		if(c2>1)continue;
		if(c1==0)continue;
		if(c2==0&&c1==1)continue;
		fore(t,1,MAXV){
			ld prob=1;
			fore(i,0,n){
				auto [l,r]=rans[i];
				ld cur=1;
				if(typ[i]==1)cur=in(t,l,r)/tot[i];
				else if(typ[i]==2){
					cur=max(r-max(t+1,l),0ll)/tot[i];
				}
				else {
					assert(typ[i]==0);
					ll len=min(t,r)-l;
					len=max(len,0ll);
					cur=len/tot[i];
				}
				prob*=cur;
			}
			res+=prob*t;
			// if(prob){
			// 	for(auto i:typ)cerr<<i;;cerr<<": ";
			// 	cerr<<t<<": "<<prob<<": "<<prob*t<<"\n";
			// }
		}
	}
	
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}