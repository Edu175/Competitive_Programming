#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v).sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define oper min
const int K=18;
ll st[2][K][1<<K]; int n;
void init(int b, vv a){
	fore(i,0,K)fore(j,0,1<<K) st[b][i][j]=5;
	fore(i,0,n)st[b][0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1){
		st[b][k][i]=oper(st[b][k-1][i],st[b][k-1][i+(1<<(k-1))]);
	}
}
ll st_query(int b, int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[b][k][s],st[b][k][e-(1<<k)]);
}
int main(){ET;
	cin>>n; 
	vv a(n+1), b(n+1); a[0]=5;a[n]=5;b[0]=5;b[n]=5;
	vector<vv>sum(2,vv(n+1));
	vv aa,bb;
	sum[0][0]=0; sum[1][0]=0;
	fore(i,1,n) {cin>>a[i]; sum[0][i]=sum[0][i-1]+a[i]; if(a[i]==1) aa.pb(i);}
	fore(i,1,n) {cin>>b[i];sum[1][i]=sum[1][i-1]+b[i];if(b[i]==1) bb.pb(i);}
	init(0,a); init(1,b);
	ll q; cin>>q;
	fore(i,0,n) cout<<sum[0][i]<<" ";; cout<<"\n";
		fore(i,0,n) cout<<sum[1][i]<<" ";; cout<<"\n";
	while(q--){
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		ll h1=max(y1,y2)+1,h2=min(y1,y2)-1,b1=max(x1,x2)+1,b2=min(x1,x2)-1;
		ll r=sum[1][h1-2]-sum[1][h2]+sum[0][b1-2]-sum[0][b2];
		cout<<h1<<" "<<h2<<"\n";
		cout<<sum[1][h1-2]<<"\n";
		cout<<"rfa: "<<r<<"\n";
		cout<<st_query(1,h2,h1)<<"\n";
		cout<<st_query(0,b2,b1)<<"\n";
		ll j=lower_bound(ALL(aa),b2+1)-aa.begin();
		ll j2=lower_bound(ALL(bb),h2+1)-bb.begin();
		if(h1-h2>b1-b2) {
			r+=st_query(1,h2,h1)*(h1-b1-h2+b2-((h1-b1-h2+b2)&1));
			if(aa[j]<=)
		}
		if(b1-b2>h1-h2){r+=st_query(0,b2,b1)*(b1-h1+h2-b2-((h1-b1-h2+b2)&1));}
		cout<<r<<"\n";
		cout<<"------\n";
	}
	
	return 0;
}
/*
if(h1-h2>b1-b2) r+=st_query(1,h2,h1)*(h1-b1-h2+b2-((h1-b1-h2+b2)&1));
		if(b1-b2>h1-h2){r+=st_query(0,b2,b1)*(b1-h1+h2-b2-((h1-b1-h2+b2)&1));}
10
5 1 5 5 5 1 1 5 5
1 5 5 5 1 5 5 1 5
3
4 3 9 10
9 2 2 9
5 1 5 1
11 25
rfa: 21
0
1
21
10 133
rfa: 60
1
1
60
2 01
rfa: 6
1
5
6

*/