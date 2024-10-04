#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b; i<ioi; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfhg:v)cout<<kdfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll oc[MAXN][3][3];
ll num(char a){
	if(a=='A')return 0;
	if(a=='C')return 1;
	return 2;
}
void init(string a, string b){
	ll n=SZ(a);
	fore(i,1,n+1){
		fore(j,0,3)fore(k,0,3)oc[i][j][k]=oc[i-1][j][k];
		oc[i][num(a[i-1])][num(b[i-1])]++;
	}
}
int get_distance(int s, int e){
	ll c[3][3]; e++;
	mset(c,0);
	fore(j,0,3)fore(k,0,3){
		c[j][k]=oc[e][j][k]-oc[s][j][k];
	}
	ll res=0;
	// fore(i,0,3){
	// 	imp(c[i]);
	// }
	fore(i,0,3)fore(j,i+1,3){
		ll &a=c[i][j];
		ll &b=c[j][i];
		ll q=min(a,b);
		res+=q;
		a-=q,b-=q;
	}
	// cout<<res<<"\n";
	// fore(i,0,3){
	// 	imp(c[i]);
	// }
	ll q=min({c[0][1],c[1][2],c[2][0]});
	res+=2*q;
	c[0][1]-=q,c[1][2]-=q,c[2][0]-=q;
	
	q=min({c[2][1],c[1][0],c[0][2]});
	res+=2*q;
	c[2][1]-=q,c[1][0]-=q,c[0][2]-=q;
	
	fore(i,0,3)fore(j,0,3)if(i!=j&&c[i][j])res=-1;
	return res;
}
