#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef ll node;
#define oper add
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	ll n,h; cin>>n>>h;
	vector<ii>a(n);
	vector<ll>p(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(ALL(a));
	fore(i,0,n)p[a[i].snd]=i;
	vector<ll>pr,id(n),ls={0},rs;
	fore(i,0,n){
		if(!i||a[i-1].fst<a[i].fst-h){
			rs.pb(i),ls.pb(i),pr.pb(0);
			//,cout<<"    ";
		}
		id[i]=SZ(pr)-1;
		cout<<a[i].fst<<","<<a[i].snd<<" ";
	}
	cout<<"\n";
	rs.pb(n);
	vector<vector<ll>>fu(n,vector<ll>(3,0));
	ll res=1,q=SZ(pr);
	ll last=0;
	/*auto calc=[&](ll k){ //debugging
		vector<ll>v;
		fore(x,0,n)if(id[x]==k){
			v.pb(x);
		}
		ll res=add(fu[v[0]][2],fu[v.back()][1]);
		fore(i,0,SZ(v)-1)res=add(res,mul(fu[v[i]][1],fu[v[i+1]][2]));
		return res;
	};*/
	STree stl(n),str(n);
	fore(i,0,n){
		ll x=p[i],k=id[x];
		ll ul=pr[k];
		fu[x][1]=mul(fpow(2,MOD-2),sub(1,str.query(ls[k],x)));
		fu[x][2]=mul(fpow(2,MOD-2),sub(1,stl.query(x,rs[k])));
		stl.upd(x,fu[x][1]);
		str.upd(x,fu[x][2]);
		ll hayl=x&&a[x-1].fst>=a[x].fst-h;
		ll hayr=x<n-1&&a[x].fst+h>=a[x+1].fst;
		pr[k]=add(pr[k],add(mul(fu[x][1],hayr?fu[x+1][2]:1),
		                    mul(fu[x][2],hayl?fu[x-1][1]:1)));
		cout<<i<<":\n";
		for(auto i:pr)cout<<i<<" ";;cout<<"\n";
		//fore(i,0,SZ(pr))cout<<calc(i)<<" ";;cout<<"\n";
		if(ul!=pr[k]){
			if(ul)res=mul(res,fpow(ul,MOD-2));//,cout<<"divided\n";
			else q--;
			res=mul(res,pr[k]);
//			cout<<"changed\n";
		}
//		cout<<ul<<" --> "<<pr[k]<<"\n";
//		cout<<last<<" -> "<<res<<"\n";
		ll resi=sub(res,last);
		if(q)cout<<"0 ",last=0;
		else cout<<mul(resi,fpow(2,n))<<" ",last=res;
//		cout<<"\n\n";
	}
	cout<<"\n";
	return 0;
}
