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

bool check(int x, int y,vector<vv> &a){
	set<ll> us;
	fore(i,max(0,x-10),min(n,x+11ll)){
		fore(j,max(0,y-10),min(n,y+11ll)){
			if((x-i)*(x-i)+(y-j)*(y-j)<=100){
				us.insert(a[i][j]);
			}
		}
	}
	if(SZ(us) > 8){
		cout<<"FAILED AT "<<x<<" "<<y<<" !!!!\n";
		for(auto a:us) cout<<a<<" ";
		cout<<endl;
		assert(0);	
	}
	return SZ(us)<=8;
}

int main(){
	JET
	{
	//n=_;
		mset(col,-1);
	cin>>n;
	vector<vv> a(n,vv(n));
	ll cnt=1;
	for(ll i=0;i<n;i+=17)for(ll j=0;j<n;j+=17){
		fore(k,0,17)fore(l,0,16)if(i+k<n&&j+l<n)a[i+k][j+l]=cnt;
		cnt++;
	}
	
	for(ll i=2;i<n;i+=17)for(ll j=2;j<n;j+=17){
		fore(k,0,12)fore(l,0,12)if(i+k<n&&j+l<n)a[i+k][j+l]=cnt;
		cnt++;
	}
	
	fore(i,0,n){
		fore(j,0,n) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	fore(i,0,n)fore(j,0,n){
		check(i,j,a);
	}
	// fore(i,0,n){
	// 	fore(j,0,n){
	// 		if(!check(i,j)) cout<<"FAILED AT "<<i<<" "<<j<<" with col "<<col[i][j]<<"\n";
	// 	}
	// }
	assert(cnt<=10+n*n/100);}
	return 0;
}