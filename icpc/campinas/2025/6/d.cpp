#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll dp[65][65][205];
ll q,n;
ii a[206];
const ll INF =1e16;

bool c (ll p, ll x){
	return (p-x)<n && p-x>=0;
}

ll f(int p1, int p2, int p3, int i){
	ll &rta=dp[p1][p2][i];
	if(i==q) return 0;
	if(rta!=-1) return rta;
	rta=INF;
	ll j = a[i].snd;
	ll prev = a[i].fst;
	
	//asumo que elijo el 1:
	ll tot = j-p1;
	ll paso1 = j-prev;
	ll paso2 = prev - p1;
	ll obli = abs(paso1) + abs(paso2); //esto es lo que sumo si o si
	if(c(p2,tot)&&c(p2,paso2)) rta = min(rta,f(j,p2-tot,p3,i+1)+obli);
	if(c(p2,paso1) && c(p3,paso2)) rta = min(rta,f(j,p2-paso1,p3-paso2,i+1)+obli);
	if(c(p2,paso2) && c(p3,paso1)) rta = min(rta,f(j,p2-paso2,p3-paso1,i+1)+obli);
	if(c(p3,tot)&&c(p3,paso2)) rta = min(rta,f(j,p2,p3-tot,i+1)+obli);
	
	//asumo que elijo el 2
	 tot = j-p2;
	 paso1 = j-prev;
	 paso2 = prev - p2;
	 obli = abs(paso1) + abs(paso2); //esto es lo que sumo si o si
	if(c(p1,tot)&&c(p1,paso2)) rta = min(rta,f(p1-tot,j,p3,i+1)+obli);
	if(c(p1,paso1) && c(p3,paso2)) rta = min(rta,f(p1-paso1,j,p3-paso2,i+1)+obli);
	if(c(p1,paso2) && c(p3,paso1)) rta = min(rta,f(p1-paso2,j,p3-paso1,i+1)+obli);
	if(c(p3,tot)&&c(p3,paso2)) rta = min(rta,f(p1,j,p3-tot,i+1)+obli);
	
	//asumo que elijo el 3
	 tot = j-p3;
	 paso1 = j-prev;
	 paso2 = prev - p3;
	 obli = abs(paso1) + abs(paso2); //esto es lo que sumo si o si
	if(c(p2,tot)&&c(p2,paso2)) rta = min(rta,f(p1,p2-tot,j,i+1)+obli);
	if(c(p2,paso1) && c(p1,paso2)) rta = min(rta,f(p1-paso2,p2-paso1,j,i+1)+obli);
	if(c(p2,paso2) && c(p1,paso1)) rta = min(rta,f(p1-paso1,p2-paso2,j,i+1)+obli);
	if(c(p1,tot) && c(p1,paso2)) rta = min(rta,f(p1-tot,p2,j,i+1)+obli);
	
	return rta;
}

int main(){
	JET
	cin>>n>>q;
	fore(i,0,q) cin>>a[i].fst>>a[i].snd;
	mset(dp,-1);
	cout<<f((n-1)/2,(n-1)/2,(n-1)/2,0)<<"\n";
	// cout<<f(1,3,(n-1)/2,1)<<"\n";
	return 0;
}

// ascensores estan p1: 2 p2: 2 p3: 2 i: 1 rta : 2
// ascensores estan p1: 2 p2: 2 p3: 2 i: 0 rta : 4
