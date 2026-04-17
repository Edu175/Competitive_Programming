#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=2e9;
struct lt{
	ll x; bool inf;
	lt(ll x): x(x), inf(x>=INF) {}
	lt() {}
};
const lt TINF=lt(INF);
lt operator+(const lt &x, const lt &y){
	if(x.inf||y.inf) return TINF;
	return lt(x.x+y.x);
}
lt operator*(const lt &x, const lt &y){
	if((x.inf&&y.x)||(y.inf&&x.x)) return TINF;
	return lt(x.x*y.x);
}
bool operator<(const lt &x, const lt &y){
	return x.x<y.x;
}
bool operator<=(const lt &x, const lt &y){
	return x.x<y.x||x.x==y.x||(x.inf&&y.inf);
}
struct mx{
	lt a[3][3];
};
mx operator*(const mx &A, const mx &B){
	mx r;
	fore(i,0,3)fore(j,0,3){
		r.a[i][j]=lt(0);
		fore(k,0,3){
			r.a[i][j]=r.a[i][j]+(A.a[i][k]*B.a[k][j]);
		}
	}
	return r;
}
mx be(mx A, ll b){
	mx r;
	fore(i,0,3)fore(j,0,3) r.a[i][j]=lt(i==j);
	while(b){
		if(b&1) r=r*A;
		A=A*A;
		b>>=1;
	}
	return r;
}
int main(){
	JET
	ll n,h,p;
	cin>>n>>p>>h;
	vector<lt> pl,t;
	ll a=0;
	fore(i,0,n){
		char x; cin>>x;
		if(x=='!'){
			a++; continue;
		}
		ll y; cin>>y;
		auto &r=(x=='*'?t:pl);
		r.pb(lt(y));
	}
	if((!a)||((!p)&&(!(SZ(pl))))){
		cout<<"*\n";
		return 0;
	}
	//cuenta de la matriz O(N)
	lt s1=lt(0),p1=lt(1);
	fore(i,0,SZ(pl)) s1=s1+pl[i];
	fore(i,0,SZ(t)) p1=p1*t[i];
//	cout<<p1.x<<" "<<a<<" "<<s1.x<<"\n";
	mx PINGO,PINGAZO;
	fore(i,0,3)fore(j,0,3){PINGAZO.a[i][j]=lt(0); PINGO.a[i][j]=lt(0);} PINGO.a[0][0]=lt(1); PINGO.a[0][1]=s1; PINGO.a[1][1]=lt(1); PINGO.a[2][2]=lt(1);
	PINGAZO.a[0][0]=p1; PINGAZO.a[1][1]=lt(1); PINGAZO.a[2][0]=p1*lt(a); PINGAZO.a[2][2]=lt(1);
	mx A=PINGAZO*PINGO;
	
	//BusBin O(log(H)*8)
	ll l=0, r=ll(1e17);
//	cout<<A.a.x<<" "<<A.b.x<<"\n";
	lt H=lt(h);
	while(l<=r){
		ll m=(l+r)/2;
		mx B=be(A,m);
		//if(m<5)cout<<m<<"m "<<l<<"l "<<r<<"r "<<(B.a[2][0]*lt(p)+B.a[2][1]).x<<"\n";
		if(((B.a[2][0]*lt(p))+B.a[2][1])<H) l=m+1;
		else r=m-1;
	}
	//cout<<r<<"\n";
	mx B=be(A,r);
	lt P=(B.a[2][0]*lt(p))+B.a[2][1];
	H.x-=P.x;
	r*=n;
	
	//Lo que sobra O(N^4)
//	cout<<r<<"\n";
	
	//cout<<P.x<<"\n";
	//cout<<H.x<<"\n";
	sort(ALL(pl)); sort(ALL(t)); reverse(ALL(pl)); reverse(ALL(t));
	lt ap[n+1];
	fore(i,0,n+1) ap[i]=lt(0);
	fore(i,0,SZ(pl)+1)fore(j,0,SZ(t)+1)fore(k,0,a+1){
		lt s=P; fore(i0,0,i) s=s+pl[i0];
		fore(j0,0,j) s=s*t[j0];
		s=s*lt(k);
		if(ap[i+j+k]<s) ap[i+j+k]=s;
	}
	fore(i,0,n+1) if(H<=ap[i]) {r+=i; break;}
	//if(r<INF*n)
	cout<<r<<"\n";
//	else cout<<"*\n";
	return 0;
}