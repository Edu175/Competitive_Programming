#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll sp[MAXN][3][3];
ll a[MAXN],b[MAXN],n;
void init(std::string s, std::string t) {
	n=SZ(s);
	fore(i,0,n){
		if(s[i]=='A')a[i]=0;
		else if(s[i]=='C')a[i]=1;
		else a[i]=2;
		if(t[i]=='A')b[i]=0;
		else if(t[i]=='C')b[i]=1;
		else b[i]=2;
	}
	fore(i,1,n+1){
		fore(j,0,3)fore(h,0,3)sp[i][j][h]=sp[i-1][j][h];
		sp[i][a[i-1]][b[i-1]]++;
	}
}

int get_distance(int l, int r) {
	r++;
	ll c[3][3]={};
	ll q[2][3]={};
	fore(i,0,3)fore(j,0,3){
		c[i][j]=sp[r][i][j]-sp[l][i][j];
		q[0][i]+=c[i][j];
		q[1][j]+=c[i][j];
	}
	ll flag=1;
	fore(i,0,3)if(q[0][i]!=q[1][i])flag=0;
	if(!flag)return -1;
	ll res=2*abs(c[0][1]-c[1][0]);
	// 01 02 12
	res+=min(c[0][1],c[1][0]);
	res+=min(c[0][2],c[2][0]);
	res+=min(c[2][1],c[1][2]);
	return res;
}
