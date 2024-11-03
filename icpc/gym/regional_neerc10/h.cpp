#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto pinchilon=[](){
	#ifdef ONLINE_JUDGE
	freopen("hands.in","r",stdin);
	freopen("hands.out","w",stdout);
	#endif
};
const ll MAXN=7462;

vector<pair<vv,ll>> a; //hands
/*
cartaAlta par doblePar pierna escalera color full poker escaleraOp
    0      1     2        3       4      5     6    7        8
*/
ll val(pair<vv,ll>_a){
	auto a=_a.fst;
	ll n=SZ(a);
	ll dif=0;
	bool esc=1,col=_a.snd;
	fore(i,0,n-1){
		dif+=(a[i]!=a[i+1]);
		if(i==n-2&&a[n-1]==14&&a[i]==5)ll pingo;
		else esc&=a[i+1]==a[i]+1;
	}
	ll mx=0,q=0;
	fore(i,0,n){
		q++;
		if(i==n-1||a[i]!=a[i+1])mx=max(mx,q),q=0;
	}
	if(esc&&col)return 8;
	if(mx==4)return 7;
	if(dif==1)return 6;
	if(col)return 5;
	if(esc)return 4;
	if(mx==3)return 3;
	if(dif==2)return 2;
	if(mx==2)return 1;
	return 0;
}

vector<ii> get(vv a){
	vector<ii>res;
	ll q=0;
	fore(i,0,SZ(a)){
		q++;
		if(i==SZ(a)-1||a[i]!=a[i+1])res.pb({q,a[i]}),q=0;
	}
	sort(ALL(res)); reverse(ALL(res));
	return res;
}

bool cmp(pair<vv,ll> a, pair<vv,ll> b){
	ll ta=val(a), tb=val(b);
	if(ta!=tb)return ta<tb;
	if(ta==5){
		reverse(ALL(a.fst)); reverse(ALL(b.fst));
		return a.fst<b.fst;
	}
	if(ta==4||ta==8){
		ll na=a.fst[4],nb=b.fst[4];
		if(na==14&&a.fst[0]==2)na=5;
		if(nb==14&&b.fst[0]==2)nb=5;
		return na<nb;
	}
	return get(a.fst)<get(b.fst);
;}
ll C=15;
int main(){pinchilon();
	JET
	fore(i,2,C)fore(j,i,C)fore(k,j,C)fore(l,k,C)fore(m,l,C)fore(col,0,2){
		set<ll>st={i,j,k,l,m};
		if(col&&SZ(st)<5)continue;
		if(SZ(st)>1)a.pb({{i,j,k,l,m},col});
	}
	// cout<<SZ(a)<<"\n";
	sort(ALL(a),cmp);
	vv idx(SZ(a));
	fore(i,1,SZ(a))
		idx[i]=idx[i-1]+(cmp(a[i],a[i-1])!=cmp(a[i-1],a[i]));
	// fore(i,0,SZ(a)){
	// 	cout<<"[";
	// 	fore(j,0,SZ(a[i].fst)){
	// 		if(j)cout<<",";
	// 		cout<<a[i].fst[j];
	// 	}
	// 	if(a[i].snd)cout<<"col";
	// 	cout<<"|"<<idx[i]<<"] ";
	// }
	// cout<<"\n";
	ll col=1;
	vector<string>b(5);
	fore(i,0,5)cin>>b[i];
	vv v(5);
	fore(i,0,5){
		char c=b[i][0];
		if(c<='9')v[i]=c-'0';
		if(c=='T')v[i]=10;
		if(c=='J')v[i]=11;
		if(c=='Q')v[i]=12;
		if(c=='K')v[i]=13;
		if(c=='A')v[i]=14;
	}
	fore(i,0,4)col&=b[i][1]==b[i+1][1];
	sort(ALL(v));
	pair<vv,ll>key={v,col};
	ll res=-1;
	fore(i,0,SZ(a)){
		if(a[i]==key)res=idx[i];
	}
	cout<<res+1<<"\n";
	return 0;
}