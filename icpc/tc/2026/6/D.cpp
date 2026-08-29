#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

pair<vv,vv> can(vector<vv> a, ll pri, ll idx){
	ll n=SZ(a),m=SZ(a[0]);
	vv r(n),c(m);
	r[0]=pri;
	fore(j,0,m)a[0][j]^=pri;
	vv ptt(m);
	fore(i,idx,m)ptt[i]=1;
	fore(j,0,m)if(a[0][j]!=ptt[j])c[j]=1,ptt[j]=1;
	ll did = idx<m;
	fore(i,1,n){
		fore(j,0,m)a[i][j]^=c[j];
		ll cnt=count(ALL(a[i]),1);
		if(cnt==0||cnt==m){
			r[i]=did ^ (cnt==m);
			fore(j,0,m)a[i][j]^=r[i];
			continue;
		}
		ll wh=-1;
		fore(bo,0,2){
			vv tmp=a[i];
			fore(j,0,m)tmp[j]^=bo;
			auto sd=tmp; sort(ALL(sd));
			if(tmp==sd)wh=bo,a[i]=tmp;
		}
		if(wh==-1||did)return {{},{}};
		did=1;
		r[i]=wh;
	}
	return {r,c};
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vv> a(n,vv(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(pri,0,2)fore(idx,0,m+1){
		auto [r,c]=can(a,pri,idx);
		if(SZ(r)){
			cout<<"YES\n";
			fore(i,0,n)cout<<r[i];;cout<<"\n";
			fore(i,0,m)cout<<c[i];;cout<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
