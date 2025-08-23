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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXL=1e6+5,MAXN=1e5+5;
int uf[MAXN];
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

ll ans[MAXN];
ll lam[MAXN];
// ed = {w,is,x,y}

void actu(ll lm, ll sum, ll cnt){
	// cerr<<"actu "<<cnt<<" "<<sum<<" "<<lm<<" cnt sum lm"<<endl;
	if(ans[cnt]==-1)ans[cnt]=sum,lam[cnt]=lm;
	else {
		assert(ans[cnt]==sum);
		lam[cnt]=max(lam[cnt],lm);
	}

}

ll piso2(ll x){
	if(x<0)return -((abs(x)+1)/2);
	return x/2;
}

void dnc(vector<array<ll,4>> &ed, ll s, ll e, ll sum, ll cnt){
	// sort(ALL(ed)); // dbg
	// cout<<"\n\ndnc "<<s<<","<<e<<": "<<sum<<" "<<cnt<<": ";
	// for(auto &[w,is,x,y]:ed)cout<<"["<<w<<","<<is<<","<<x<<","<<y<<"] ";;cout<<"\n";
	if(!SZ(ed)){
		actu(e-1,sum,cnt);
		return;
	}

	ll m=piso2(s+e);
	for(auto &[w,is,x,y]:ed)if(is)w-=m;
	sort(ALL(ed));
	// for(auto &[w,is,x,y]:ed)cout<<"["<<w<<","<<is<<","<<x<<","<<y<<"] ";;cout<<"\n";
	
	vv nod;
	vector<array<ll,4>> H[2], app[2];
	
	for(auto &e:ed){
		auto &[w,is,x,y]=e;
		if(is)w+=m;
		nod.pb(x); nod.pb(y);
		// cout<<x<<","<<y<<": ";
		if(uf_join(x,y)){
			// cout<<"uso\n";
			ll wh=!is;
			app[!wh].pb(e);
			H[wh].pb(e);
		}
		else {
			// cout<<"no uso\n";
			ll wh=is;
			H[wh].pb(e);
		}
	}
	for(auto i:nod)uf[i]=-1;
	if(e-s==1){
		// cout<<"base\n";
		ll sump=sum,cntp=cnt;
		fore(w,0,2)for(auto &[w,is,x,y]:app[w]){
			sump+=w;
			cntp+=is;
		}
		actu(s,sump,cntp);
		return;
	}
	fore(w,0,2){
		ll sump=sum,cntp=cnt;
		for(auto &[w,is,x,y]:app[w]){
			sump+=w;
			cntp+=is;
			uf_join(x,y);
		}
		auto &ed=H[w];
		for(auto &[w,is,x,y]:ed)x=uf_find(x),y=uf_find(y);
		for(auto i:nod)uf[i]=-1;
		if(e-s==1){
		}
		else dnc(ed,(!w?s:m),(!w?m:e),sump,cntp);
	}
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n+3){
			uf[i]=-1;
			ans[i]=-1;
		}
		vector<array<ll,4>> ed;
		fore(i,0,m){
			ll u,v,w; char c; cin>>u>>v>>w>>c; u--,v--;
			ed.pb({w,c=='R',u,v});
		}
		dnc(ed,-MAXL,MAXL,0,0);
		ll l=0,r=n+1; // r=n-1
		while(ans[l]==-1)l++;
		while(ans[r]==-1)r--;; r++;
		ll lm=0,ns=0,d=0;
		fore(i,l,r){
			if(ans[i]!=-1)lm=lam[i],ns=ans[i],d=0;
			else {
				ans[i]=ns+d*lm;
			}
			d++;
		}
		fore(i,0,n)cout<<ans[i]<<" ";;cout<<"\n";
	}
	// cerr<<piso2(-1)<<"\n";
	return 0;
}