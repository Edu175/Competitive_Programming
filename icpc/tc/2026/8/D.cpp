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

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii> a(m);
	ll sum=0;
	fore(i,0,m){
		cin>>a[i].fst;
		a[i].fst=min(a[i].fst,n/2);
		a[i].snd=i; sum+=a[i].fst;
	}
	if(sum<n){
		cout<<"-1\n";
		return 0;
	}
	sort(ALL(a)); reverse(ALL(a));
	vv ans(n);
	ll p=0;
	fore(ty,0,2)for(ll i=!ty;i<n;i+=2){
		if(!a[p].fst)p++;
		ans[i]=a[p].snd+1; a[p].fst--;
	}
	show(ans)
	return 0;
}