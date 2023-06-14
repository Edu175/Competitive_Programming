#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
ll inv=0;

queue<ll> merge(queue<ll>l, queue<ll>r){
	queue<ll>q;
	/*cout<<"merge "<<l<<","<<r<<" "<<s<<","<<e<<"\n";
	fore(i,l,r)cout<<a[i]<<" ";
	cout<<"| ";
	fore(i,s,e)cout<<a[i]<<" ";
	cout<<"\n";*/
	while(SZ(l)||SZ(r)){
		if(!SZ(r)||(SZ(l)&&l.front()<r.front()))q.push(l.front()),l.pop();
		else q.push(r.front()),r.pop(),inv+=SZ(l);
	}
	return q;
}
queue<ll> msort(queue<ll>&q){
	if(SZ(q)==1)return q;
	ll m=(SZ(q))/2;
	queue<ll>l,r;
	fore(i,0,m)l.push(q.front()),q.pop();
	while(SZ(q))r.push(q.front()),q.pop();
	//cout<<"msort "<<l<<","<<r<<"\n";
	return merge(msort(l),msort(r));
	/*fore(i,l,r)cout<<a[i]<<" ";
	cout<<"\n";*/
}

int main(){FIN;
	ll n; cin>>n; n/=2;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<ll>es(n);
	fore(i,0,n){
		ll x; cin>>x; x--;
		es[x]=i,x=i;
	}
	fore(i,0,n)a[i]=es[a[i]];
	/*fore(i,0,n)cout<<a[i]<<" ";
	cout<<"\n";*/
	es.clear();
	queue<ll>q;
	fore(i,0,n)q.push(a[i]);
	a.clear();
	msort(q);
	
	// iterativo con optimizacion de memoria?
	
	/*fore(i,0,n)cout<<a[i]<<" ";
	cout<<"\n";*/
	cout<<inv<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
