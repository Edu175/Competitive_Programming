#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1010;
ll c = 1;
ll col[maxn][maxn];
ll n;

bool check(int x, int y){
	set<ll> us;
	fore(i,0,n){
		fore(j,0,n){
			ll dist = (x-i)*(x-i) + (y-j)*(y-j);
			if(dist<=100 && x == 22 && y == 19 && col[i][j]==6){
				cout<<"distancia a 6 "<<dist<<" 6 de la pos "<<i<<" "<<j <<"\n"; 
			}
			if(dist<=100){
				us.insert(col[i][j]);
			}
		}
	}
	if(SZ(us) > 8){
		cout<<"FAILED AT "<<x<<" "<<y<<" !!!!\n";
		for(auto a:us) cout<<a<<" ";
		cout<<"\n";	
	}
	return SZ(us)<=8;
}

int main(){
	JET
	mset(col,-1);
	cin>>n;
	ll m=(n+4)/5;
	
	for(ll i=0;i<m;i+=3)for(ll j=0;j<n;j+=6){
		
	}
	
	fore(i,0,n){
		fore(j,0,n) cout<<col[i][j]<<" ";
		cout<<"\n";
	}
	fore(i,0,n){
		fore(j,0,n){
			if(!check(i,j)) cout<<"FAILED AT "<<i<<" "<<j<<" with col "<<col[i][j]<<"\n";
		}
	}
	// assert(c<=10+n*n/100);
	return 0;
}