#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll maxn=6e3+5;
ll x[maxn],y[maxn],sz[maxn],x2[maxn],y2[maxn];
ll op(ll a, ll b, ll c, ll d){
	return a*c+b*d;
}
struct pts{
	ll i, j;	
	ll val()const{
		return op(x2[i],y2[i],sz[j],sz[j])+op(x2[j],y2[j],sz[i],sz[i])-2*op(x[i],y[i],x[j],y[j]);
	}
	ll nm()const{return sz[i]*sz[j];}
	ll old()const{assert(i<j); return i;}
	ll niu()const{return j;}
};

bool operator<(const pts &A, const pts &B){
	ll v1=A.val(),v2=B.val(),n1=A.nm(),n2=B.nm();
	if(v1*n2!=v2*n1) return v1*n2>v2*n1;
	if(A.old()!=B.old()) return A.old()>B.old();
	return A.niu()>B.niu();
}
priority_queue<pts> pq;
set<ll> v;
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n) cin>>x[i]>>y[i],x2[i]=x[i]*x[i],y2[i]=y[i]*y[i],sz[i]=1,v.insert(i);
	fore(i,0,n)fore(j,0,i) pq.push((pts){j,i});
	ll u=n;
	while(SZ(pq)){
		auto[i,j]=pq.top(); pq.pop();
		if(!v.count(i)||!v.count(j)) continue;
		v.erase(i); v.erase(j);
		x[u]=x[i]+x[j];
		x2[u]=x2[i]+x2[j];
		y[u]=y[i]+y[j];
		y2[u]=y2[i]+y2[j];
		sz[u]=sz[i]+sz[j];
		cout<<sz[u]<<"\n";
		for(auto t: v) pq.push((pts){t,u});
		v.insert(u++);
	}
	return 0;
}