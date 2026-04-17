#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
typedef pair<ll,ll> ii;
const ll n=4;
ll a[n][n];

bool hay(ll i, ll j, ll v){
	a[i][j]=v;
	ll res=0;
	fore(i,0,n){
		ll s=0,flag=1;
		fore(j,0,n)s+=a[i][j],flag&=a[i][j]>0;
		if(flag&&s==10)res=1;
	}
	fore(j,0,n){
		ll s=0,flag=1;
		fore(i,0,n)s+=a[i][j],flag&=a[i][j]>0;
		if(flag&&s==10)res=1;
	}
	a[i][j]=0;
	return res;
}
bool nocago(ll i, ll j, ll v){
	a[i][j]=v;
	ll res=1;
	fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(k,1,5){
		if(hay(i,j,k))res=0;
	}
	a[i][j]=0;
	return res;
}
void go(ll i, ll j, ll k){
	a[i][j]=k;
	cout<<i+1<<" "<<j+1<<" "<<k<<endl;
}
random_device rd;
mt19937 rng(rd());
int main(){
	vv magic(4);
	iota(ALL(magic),0);
	JET
	while(1){
		ll r,c,k; cin>>r>>c>>k; r--,c--;
		a[r][c]=k;
		fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(k,1,5){
			if(hay(i,j,k)){
				cout<<i+1<<" "<<j+1<<" "<<k<<" WIN"<<endl;
				return 0;
			}
		}
		k=5-k;
		shuffle(ALL(magic),rng);
		ll did=0;
		for(auto i:magic)if(!a[i][c]&&nocago(i,c,k)){
			go(i,c,k);
			did=1;
			break;
		}
		if(!did){
			auto magic2=magic;
			shuffle(ALL(magic),rng);
			vv vals(4); iota(ALL(vals),1);
			shuffle(ALL(vals),rng);
			for(auto i:magic)for(auto j:magic2)if(!a[i][j])for(auto v:vals){
				if(nocago(i,j,v)){
					go(i,j,v);
					goto arafue;
				}
			}
			assert(0);
		}
		assert(did);
		arafue:
		ll pingo;
	}
	return 0;
}
