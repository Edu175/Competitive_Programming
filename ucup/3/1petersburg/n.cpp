#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vv> mat;

ll lgt(ll n){
	ll cnt=0;
	while(n>1){
		cnt++;
		n=(n+1)/2;
	}
	return cnt;
}

mat encode(mat a, ll m){
	ll n=SZ(a);
	assert(n<m);
	mat b(m,vv(m));
	fore(i,0,n)fore(j,0,n)b[i][j]=a[i][j];
	auto add_edge=[&](ll u, ll v){b[u][v]=b[v][u]=1;};
	ll k=lgt(n);
	fore(i,0,k){
		ll p=n+i;
		if(i)add_edge(p,p-1);
		fore(j,0,n){
			ll bo=j>>i&1;
			if(bo)add_edge(p,j);
		}
	}
	ll tod=m-1,chad=tod-1,npc=chad-1;
	add_edge(npc,n);
	fore(i,0,chad)add_edge(i,tod);
	fore(i,n,n+k)add_edge(i,chad);
	return b;
}
mat decode(mat b, ll n){
	ll m=SZ(b);
	auto deg=[&](ll u){return count(ALL(b[u]),1);};
	assert(n<m);
	ll mx=0;
	fore(i,0,m)if(deg(i)>deg(mx))mx=i;
	
	ll chad=-1;
	fore(i,0,m)if(i!=mx&&!b[mx][i])chad=i;
	
	// cerr<<mx<<" "<<chad<<" mx chad\n";
	
	vv good(m);
	fore(i,0,m)good[i]=b[chad][i];
	
	auto deg_good=[&](ll u){
		ll cnt=0;
		fore(i,0,m)cnt+=(b[u][i]&&good[i]);
		return cnt;
	};
	
	vv mns;
	fore(i,0,m)if(good[i]){
		if(!SZ(mns)||deg_good(i)<deg_good(mns[0]))mns={i};
		else if(deg_good(i)==deg_good(mns[0]))mns.pb(i);
	}
	ll mn=mns[0];
	if(deg(mn)<deg(mns[1]))mn=mns[1];
	// cerr<<"mns: "; imp(mns)
	// cerr<<"mn: "<<mn<<"\n";
	
	vv tag(m),vis(m);
	ll x=mn,idx=0;
	while(1){
		// cerr<<idx<<": "<<x<<" x\n";
		vis[x]=1;
		fore(j,0,m)if(b[x][j]){
			tag[j]|=1ll<<idx;
		}
		ll prox=-1;
		fore(y,0,m)if(b[x][y]&&!vis[y]&&good[y])prox=y;
		idx++;
		if(prox==-1)break;
		x=prox;
	}
	vv in(m);
	fore(i,0,m)in[i]=!good[i];
	in[mx]=in[chad]=0;
	
	ll sac=0; // saco al npc
	fore(i,0,m)if(!sac&&in[i]&&tag[i]==1&&deg(i)==2)sac=1,in[i]=0;
	
	mat a(n,vv(n));
	fore(i,0,m)if(in[i])fore(j,0,m)if(in[j]){
		a[tag[i]][tag[j]]=b[i][j];
	}
	return a;
	
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	mat a(n,vv(n)),b;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		a[i][j]=c=='1';
	}
	if(n<m)b=encode(a,m);
	else b=decode(a,m);
	fore(i,0,m){
		fore(j,0,m)cout<<b[i][j];
		cout<<"\n";
	}
	return 0;
}
