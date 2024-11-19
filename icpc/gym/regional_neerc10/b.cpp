#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
void pinchilon(){
	#ifdef ONLINE_JUDGE
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	#endif
}

const ll K=61,D=10,B=19;

ll op[D][D],pot[B];
struct fun{
	ll n=D; ll F[K][D];
	fun(){}
	fun(vv f){
		fore(x,0,n)F[0][x]=f[x];
		fore(k,1,K)fore(x,0,n)F[k][x]=F[k-1][F[k-1][x]];
	}
	ll go(ll x, ll v){
		for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
			v-=1ll<<k;
			x=F[k][x];
		}
		return x;
	}
};
ll fd(ll l, ll r){
	ll cnt=0,res=-1;
	while(l||r){
		if(l%10!=r%10)res=cnt;
		cnt++; l/=10,r/=10;
	}
	return res;
}
int main(){pinchilon();
	JET
	fore(i,0,10)fore(j,0,10)cin>>op[i][j];
	vector<fun> only(D);
	fore(d,0,D){
		vv f(D);
		fore(x,0,D)f[x]=op[x][d];
		only[d]=fun(f);
	}
	pot[0]=1;
	fore(i,1,B)pot[i]=pot[i-1]*10;
	vector<fun> cyc(B);
	fore(j,0,B){
		vv f(D);
		fore(_x,0,D){
			auto x=_x;
			fore(d,0,D)x=only[d].go(x,pot[j]);
			f[_x]=x;
		}
		cyc[j]=fun(f);
	}
	ll L,R; cin>>L>>R;
	vv ans;
	fore(j,0,B){
		ll l=L,r=R,p=pot[j];
		// cout<<j<<" j: ";
		if(fd(l,r)<j){
			ll d=l/p%10;
			ll res=only[d].go(d,r-l);
			ans.pb(res);
			// cout<<"pingo\n";
			continue;
		}
		r++;
		ll x=l/p%10; l++;
		// cout<<l<<": "<<x<<" start\n";
		do{
			ll e=min(r,l/p*p+p);
			x=only[l/p%10].go(x,e-l);
			l=e;
		}
		while(l<r&&l/p%10);
		// cout<<l<<": "<<x<<" antes cyc\n";
		
		if(l==r){
			ans.pb(x);
			continue;
		}
		ll e=r/p/10*10*p;
		x=cyc[j].go(x,(e-l)/(10*p));
		// cout<<l<<": "<<x<<" despues cyc\n";
		
		l=e;
		while(l<r){
			ll e=min(r,l/p*p+p);
			x=only[l/p%10].go(x,e-l);
			l=e;
		}
		// cout<<l<<": "<<x<<" final\n";
		ans.pb(x);
	}
	while(SZ(ans)>1&&ans.back()==0)ans.pop_back();
	reverse(ALL(ans));
	for(auto i:ans)cout<<i;
	cout<<"\n";
	return 0;
}