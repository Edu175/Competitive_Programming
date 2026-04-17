#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=2e5+5;
vv v[3][3];
ll x[maxn],y[maxn],n;
ll wh(ll a){
	if(a<=n/3) return 0;
	if(a<=2*n/3) return 1;
	return 2;
}
struct tr{
	ll a,b,c;
};
bool check(vv &p){
	fore(i,0,3) if(!SZ(v[i][p[i]])) return false;
	return true;
}
ll calc(tr t){
	ll Mx=x[t.a],mx=x[t.a],My=y[t.a],my=y[t.a];
	Mx=max(Mx,x[t.b]),mx=min(mx,x[t.b]);
	My=max(My,y[t.b]),my=min(my,y[t.b]);
	
	Mx=max(Mx,x[t.c]),mx=min(mx,x[t.c]);
	My=max(My,y[t.c]),my=min(my,y[t.c]);
	return Mx-mx+My-my;
}
int main(){
	JET
	cin>>n;
	fore(i,0,n){
		cin>>x[i]>>y[i];
		v[wh(x[i])][wh(y[i])].pb(i);
	}
	vv p={0,1,2};
	vector<tr> r;
	do{
		while(check(p)){
			r.pb((tr){v[0][p[0]].back(),v[1][p[1]].back(),v[2][p[2]].back()});
			fore(i,0,3) v[i][p[i]].pop_back();
		}
	}while(next_permutation(ALL(p)));
	ll res=0;
	for(auto t:r){
		res+=calc(t);
	}
	cout<<res*2<<"\n";
	for(auto t:r){
		cout<<t.a+1<<" "<<t.b+1<<" "<<t.c+1<<"\n";
	}
	return 0;
}