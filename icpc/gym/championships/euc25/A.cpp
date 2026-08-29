#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y+1<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=50;
ll ar[maxn][maxn];
struct tr{
	ll a,b,c;
};
ll N;
vv operator+(const vv &a, const vv &b){
	vv r;
	for(auto x:a) r.pb(x);
	for(auto x:b) r.pb(x);
	return r;
}
void add(ll i, ll j, ll k, vector<vv> &r){
	vv p;
	fore(l,0,N)if(l!=i&&l!=j&&l!=k){
		p.pb(l);
	}
	vv pr=p;
	reverse(ALL(p));
	if(ar[i][j]==ar[j][k]&&ar[j][k]==ar[k][i]){
		vv t={i,j,k};
		if(ar[i][j]<0) reverse(ALL(t));
		r.pb(t+p); r.pb(pr+t);
		
		rotate(t.begin(),t.begin()+1,t.end());
		r.pb(t+p); r.pb(pr+t);
		rotate(t.begin(),t.begin()+1,t.end());
		r.pb(t+p); r.pb(pr+t);
	}
	else{
		vector<ii> a;
		vv all={i,j,k};
		for(auto x:all){
			ll d=0;
			for(auto y:all)if(x!=y&&ar[x][y]==1)d++;
			a.pb({d,x});
		}
		sort(ALL(a));
		reverse(ALL(a));
		vv t; for(auto i:a)t.pb(i.snd);
		r.pb(t+p); r.pb(pr+t);
	}
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	N=n;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--,b--;
		ar[a][b]=1;
		ar[b][a]=-1;
	}
	vector<tr> v;
	fore(i,0,n)fore(j,0,n) if(i!=j&&!ar[i][j]){
		ar[i][j]=1; ar[j][i]=-1;
	}
	vector<vv> r;
	fore(i,1,n)fore(j,1,i){
		add(0,j,i,r);
	}
	cout<<"YES\n";
	if(n==2){
		cout<<"1\n";
		if(ar[0][1]==1){
			cout<<"1 2\n";
		}
		else{
			cout<<"2 1\n";
		}
		return 0;
	}
	cout<<SZ(r)<<"\n";
	for(auto &rt:r){
		show(rt);
	}
	return 0;
}