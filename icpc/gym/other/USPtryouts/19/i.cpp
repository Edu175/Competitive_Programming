#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	JET
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].snd*=-1;
	sort(ALL(a),[&](ii a, ii b){
		return a.snd>b.snd;
	});
	ll s=0,res=-1e10;
	fore(i,0,n){
		s+=a[i].fst,res=max(res,s+a[i].snd);
	}
	cout<<res<<"\n";
	return 0;
}