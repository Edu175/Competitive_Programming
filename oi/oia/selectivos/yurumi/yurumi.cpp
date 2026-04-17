#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define forr(i,a,b) for(ll i=b-1,oia=a;i>=oia;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) cout<<"{ ";for(auto messi:v)cout<<messi<<" ";cout<<"} ";
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
/*#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")*/
const ll MAXN=4005;

bool a[MAXN][MAXN];
ll n,m;
vector<ll> rows[MAXN],cols[MAXN];

int main(){FIN;
	ifstream cin;   cin.open("yurumi.in", ios::in);
	ofstream cout; cout.open("yurumi.out", ios::out);
	ll k; cin>>n>>m>>k;
	fore(_,0,k){
		ll i,j; cin>>i>>j; i--,j--;
		a[i][j]=1;
	}
	ll dp[n+5][m+5]={};
	forr(i,0,n)forr(j,0,m)if(!a[i][j]){
		ll &x=dp[i][j];
		x=min(dp[i+1][j],dp[i][j+1]);
		if(!a[i+x][j+x])x++;
		rows[i]=max(rows[i],{x,i,j});
		cols[j]=max(cols[j],{x,i,j});
	}
	forr(i,0,n)rows[i]=max(rows[i],rows[i+1]);
	forr(j,0,m)cols[j]=max(cols[j],cols[j+1]);
	//fore(i,0,n){imp(rows[i]);}cout<<"\n";
	//fore(j,0,m){imp(cols[j]);}cout<<"\n";
	ll sum=0,r0=0,c0=0,r1=0,c1=0;
	fore(i,0,n)fore(j,0,m){
		ll x=dp[i][j];
		auto vr=rows[i+x],vc=cols[j+x];
		//cout<<i<<" "<<j<<": "<<i+x<<" "<<j+x<<"\n";
		if(SZ(vr)&&x+vr[0]>sum)sum=x+vr[0],r0=i,c0=j,r1=vr[1],c1=vr[2];
		if(SZ(vc)&&x+vc[0]>sum)sum=x+vc[0],r0=i,c0=j,r1=vc[1],c1=vc[2];
	}
	cout<<r0<<" "<<c0<<" "<<dp[r0][c0]<<"\n";
	cout<<r1<<" "<<c1<<" "<<dp[r1][c1]<<"\n";
	return 0;
}
