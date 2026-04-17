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
// vv get(){
// 	ll r=-1,c=-1,k=-1;
// 	fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(v,1,5){
// 		a[i][j]=v;
// 		if(hay())r=i,c=j,k=v;
// 		a[i][j]=0;	
// 	}
// 	if(r!=-1)return {r,c,k};
// 	return {};
// }
bool nocago(ll i, ll j, ll v){
	a[i][j]=v;
	ll res=1;
	fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(k,1,5){
		if(hay(i,j,k))res=0;
	}
	a[i][j]=0;
	return res;
}
// vv proba(ll v){
// 	fore(i,0,n)fore(j,0,n)if(!a[i][j]){
// 		a[i][j]=v;
// 		auto vec=get();
// 		if(!SZ(vec)){a[i][j]=0;return {i,j};}
// 		a[i][j]=0;
// 	}
// 	return {};
// }
ll conta(ll i, ll j, ll v){
	a[i][j]=v;
	ll b[n][n]; mset(b,0);
	fore(i,0,n){
		ll s=0,c=0;
		fore(j,0,n)s+=a[i][j],c+=a[i][j]>0;
		if(s==5&&c==2){
			fore(j,0,n)if(!a[i][j])b[i][j]=1;
		}
	}
	fore(j,0,n){
		ll s=0,c=0;
		fore(i,0,n)s+=a[i][j],c+=a[i][j]>0;
		if(s==5&&c==2){
			fore(i,0,n)if(!a[i][j])b[i][j]=1;
		}
	}
	ll res=0;
	fore(i,0,n)fore(j,0,n)res+=b[i][j];
	a[i][j]=0;
	return res;
}
void go(ll i, ll j, ll k){
	a[i][j]=k;
	cout<<i+1<<" "<<j+1<<" "<<k<<endl;
}
int main(){
	JET
	ll primero=1;
	while(1){
		ll r,c,k; cin>>r>>c>>k; r--,c--;
		a[r][c]=k;
		if(primero){
			ll j=c-1;
			if(j==-1)j=c+1;
			go(r,j,5-k);
			primero=0;
			continue;
		}
		fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(k,1,5){
			if(hay(i,j,k)){
				cout<<i+1<<" "<<j+1<<" "<<k<<" WIN"<<endl;
				return 0;
			}
		}
		fore(i,0,n)fore(j,0,n)if(!a[i][j])fore(k,1,5){
			if(nocago(i,j,k)&&conta(i,j,k)%2==0){
				go(i,j,k);
				goto arafue;
			}
		}
		arafue:
		assert(1);
	}
	return 0;
}


/*

2 2 4
2 1 1
3 2 4
1 1 1
3 3 1
1 2 2


*/