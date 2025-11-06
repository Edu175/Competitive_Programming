#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<int,int> ii;
const int maxn=1e5+5;
vector<int> h[maxn];
int c[maxn][3];
typedef array<ii,4> nd;

void act(ii x, nd &a){
	if(x.fst<=a[0].fst) return;
	a[0]=x;
	fore(i,1,4) if(a[i-1].fst>a[i].fst) swap(a[i-1],a[i]);
}
#define MINF INT_MIN
#define NO (ii){MINF,MINF}
void dfs(int v){
	c[v][0]=0;
	nd c0={NO,NO,NO,NO},c1=c0;
	int c2=MINF;
	for(auto u:h[v]){
		dfs(u);
		int mx=0;
		fore(i,0,3)mx=max(c[u][i],mx);
		c[v][0]+=mx;
		if(c[u][0]>MINF)act({c[u][0]-mx,u},c0);
		if(c[u][1]>MINF)act({c[u][1]-mx,u},c1);
		if(c[u][2]>MINF)c2=max(c2,c[u][2]); 
	}
	// fore(i,0,4) cout<<c0[i].fst<<" ";;cout<<"c0\n";
	// fore(i,0,4) cout<<c0[i].snd<<" ";;cout<<"c0i\n";
	// fore(j,0,4) cout<<c1[j].fst<<" ";;cout<<"c1\n";
	// fore(j,0,4) cout<<c1[j].snd<<" ";;cout<<"c1i\n";

	if(c0[2].fst>MINF) c[v][1]=c[v][0]+c0[3].fst+c0[2].fst;
	int mx=MINF;
	for(int k=3;k>=0;k--)if(c1[k].fst>MINF)
		for(int i=3;i>=1;i--)if(c0[i].fst>MINF&&c1[k].snd!=c0[i].snd)
			for(int j=i-1;j>=0;j--)if(c0[j].fst>MINF&&c1[k].snd!=c0[j].snd)
				mx=max(mx,c[v][0]+c0[i].fst+c0[j].fst+c1[k].fst);
	c[v][2]=mx;
	mx=c2;
	for(int k=3;k>=0;k--)if(c1[k].fst>MINF)
		for(int i=3;i>=2;i--)if(c0[i].fst>MINF&&c1[k].snd!=c0[i].snd)
			for(int j=i-1;j>=1;j--)if(c0[j].fst>MINF&&c1[k].snd!=c0[j].snd)
				for(int l=j-1;l>=0;l--)if(c0[l].fst>MINF&&c1[k].snd!=c0[l].snd)
				mx=max(mx,c[v][0]+c0[i].fst+c0[j].fst+c1[k].fst+c0[l].fst);
	c[v][0]=max(c[v][0],mx+1);
	// cout<<v<<": ";
	// fore(i,0,3)cout<<c[v][i]<<" ";;cout<<"\n";
}

int main(){
	JET
	int n; cin>>n;
	fore(i,1,n){int p; cin>>p;p--; h[p].pb(i);}
	fore(i,0,n)fore(j,0,4) c[i][j]=MINF;
	dfs(0);
	int mx=0;
	fore(i,0,4) mx=max(mx,c[0][i]);
	cout<<mx<<"\n";
	return 0;
}
// 13
// 13 7 5 1 5 2 5 7 4 2 2 4
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 9: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 2: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 8: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 0 0 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 6: 0 0 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 10: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 11: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 0 0 0 c0
// -2147483648 -2147483648 -2147483648 0 c1
// 1: 0 0 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 0 c0
// -2147483648 -2147483648 -2147483648 0 c1
// 12: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 0 0 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 3: 0 0 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 5: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 -2147483648 c0
// -2147483648 -2147483648 -2147483648 -2147483648 c1
// 7: 0 -2147483648 -2147483648 -2147483648 
// -2147483648 0 0 0 c0
// -2147483648 -2147483648 -2147483648 0 c1
// 4: 0 0 -2147483648 -2147483648 
// -2147483648 -2147483648 -2147483648 0 c0
// -2147483648 -2147483648 -2147483648 0 c1
// 0: 0 -2147483648 -2147483648 -2147483648 
// 0
// edu@ed
