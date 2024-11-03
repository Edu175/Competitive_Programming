#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

bool func(ii a, ii b){
	ld auxa=(ld)a.fst/(ld)a.snd;
	ld auxb = (ld)b.fst/(ld)b.snd;
	return auxa<auxb;
}

int main(){
	JET
	ll n,q;
	cin>>n>>q;
	ll best[3*n+1];
	ll a[n+1];
	ii tg[n+1];
	fore(i,1,n+1) cin>>a[i];
	tg[0]={0,0};
	best[0]=0;
	fore(i,1,3*n+1){
		best[i]=1e16;
		if(i<=n) best[i]=a[i];
		fore(j,1,i){
			best[i]=min(best[i],best[j]+best[i-j]);
		}
		// cout<<i<<" "<<best[i]<<"\n";
		if(i<n+1)tg[i]={i,best[i]};
	}
	// for(auto x: a) cout<<x<<" ";
	// cout<<"\n";
	sort(tg+1,tg+n+1,func);
	int mej=tg[n].fst;
	ll pete[250];
	fore(i,0,250) pete[i]=1e16;
	fore(i,1,n+1){
		fore(j,1,n+1){
			pete[i+j]=min(pete[i+j],a[i]+a[j]);
		}
	}
	cout<<"\n";
	fore(i,0,q){
		ll k;
		cin>>k;
		ll rta=1e16;
		if(k<=n) cout<<a[k]<<"\n";
		else{
			fore(j,n+1,2*n+1){
				ll aux=0;
				if(j>k) continue;
				aux=pete[j];
				ll val=k;
				val-=j;
				aux+=query(val);
				// if(val>mej) aux+=(best[mej]*(val-mej/mej));
				// if(val>mej) val=val%mej+mej;
				// aux+=best[val];
				// rta=min(rta,aux);
			}	
			cout<<rta<<"\n";
		}
		
		
	}
	
}





/*
edu@edu-IdeaPad-3-14ITL6:~/Documents/NWERC_2020$ cat in
5 5
9 4 1 3 6 
13
12
5
12
2
edu@edu-IdeaPad-3-14ITL6:~/Documents/NWERC_2020$ ./a <in
11
9
6
9
4
edu@edu-IdeaPad-3-14ITL6:~/Documents/NWERC_2020$ ./b <in
6
4
6
4
4


*/