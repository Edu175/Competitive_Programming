#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll S=256,Z=S+5;
ll n,k;
int a[Z][Z][Z];
int sp[Z][Z][Z];
void precalc(){
	fore(x,1,Z)fore(y,1,Z)fore(z,1,Z)
		sp[x][y][z]=sp[x][y][z-1]+a[x-1][y-1][z-1];
	fore(x,1,Z)fore(y,1,Z)fore(z,1,Z)sp[x][y][z]+=sp[x][y-1][z];
	fore(x,1,Z)fore(y,1,Z)fore(z,1,Z)sp[x][y][z]+=sp[x-1][y][z];
}
ll query(ll x, ll y, ll z, ll m){ // query on size-m cube x,y,z
	//m++;
	ll res=sp[x+m][y+m][z+m]
	-sp[x+m][y+m][z]-sp[x+m][y][z+m]-sp[x][y+m][z+m]
	+sp[x+m][y][z]+sp[x][y+m][z]+sp[x][y][z+m]
	-sp[x][y][z];
	//cout<<"query "<<x<<","<<y<<","<<z<<" "<<m<<" = "<<res<<"\n";
	return res;
}
pair<bool,vector<ll>> can(ll m){
	//cout<<"\n\ncan "<<m<<"\n";
	fore(i,0,S-m+1)fore(j,0,S-m+1)fore(h,0,S-m+1){
		if(query(i,j,h,m)>=k)return {1,{i,j,h}};
	}
	return {0,{}};
}

int main(){FIN;
	cin>>n>>k;
	vector<ll> x(n),y(n),z(n);
	fore(i,0,n){
		cin>>x[i]>>y[i]>>z[i];
		a[x[i]][y[i]][z[i]]++;
	}
	precalc();
	ll l=0,r=S;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m).fst)r=m-1;
		else l=m+1;
	}
	//cout<<l<<"\n";
	auto v=can(l).snd;
	vector<ll>res;
	fore(i,0,n)if(SZ(res)<k&&
	x[i]>=v[0]&&x[i]<v[0]+l&&
	y[i]>=v[1]&&y[i]<v[1]+l&&
	z[i]>=v[2]&&z[i]<v[2]+l)res.pb(i+1);
	imp(res);
	return 0;
}
