#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

bool cmpl(ll a[3], ll b[3]){
	return a[1]<b[1];
}
bool cmpr(ll a[3], ll b[3]){
	return a[2]<b[2];
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll m[n];
	string s[n];
	ll b[n][3];
	fore(i,0,n)cin>>m[i]>>s[i];
	pair<ll,ll> bl[n];
	pair<ll,ll> br[n];
	fore(i,0,n){
		ll tot=0;
		fore(j,0,m[i]){
			if(s[i][j]=='1')tot++;
			else tot--;
			if(!j)b[i][2]=tot;
			b[i][2]=max(b[i][2],tot);
			if(j==m[i]-1)b[i][0]=tot;
		}
		tot=0;
		for(ll j=m[i]-1; j>=0; j--){
			if(s[i][j]=='1')tot++;
			else tot--;
			if(j==m[i]-1)b[i][1]=tot;
			b[i][1]=max(b[i][1],tot);
		}
		bl[i].fst=b[i][1],bl[i].snd=i;
		br[i].fst=b[i][2],br[i].snd=i;
		//cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<"\n";
	}
	//sort(bl,bl+n,greater<pair<ll,ll>>());
	//sort(br,br+n,greater<pair<ll,ll>>());
	/*fore(i,0,n)cout<<bl[i].fst<<" "<<bl[i].snd<<"\n";
	cout<<"\n";
	fore(i,0,n)cout<<br[i].fst<<" "<<br[i].snd<<"\n";*/
	while(q--){
		ll l,r; cin>>l>>r;
		l--,r--;
		ll res=0;
		ll ni=r-l+1;
		ll bi[ni][3];
		fore(i,l,r+1){
			fore(j,0,3)bi[i-l][j]=b[i][j];//,cout<<bi[i-l][j]<<" ";
			//cout<<"\n";
		}
		vector<pair<ll,ll>>vl;
		vector<pair<ll,ll>>vr;
		fore(i,0,ni){
			if(bi[i][0]>0)res+=bi[i][0];
			if(bi[i][1]>bi[i][0]&&bi[i][1]>0)vl.pb({bi[i][1]-bi[i][0],i});
			if(bi[i][2]>bi[i][0]&&bi[i][2]>0)vr.pb({bi[i][2]-bi[i][0],i});
		}
		/*for(auto i:vl)cout<<"{"<<i.fst<<","<<i.snd<<"} ";
		cout<<"\n";
		for(auto i:vr)cout<<"{"<<i.fst<<","<<i.snd<<"} ";
		cout<<"\n";*/
		if(SZ(vl))sort(ALL(vl),greater<pair<ll,ll>>());
		if(SZ(vr))sort(ALL(vr),greater<pair<ll,ll>>());
		if(SZ(vl)&&SZ(vr)){
			if(vl[0].snd!=vr[0].snd)res+=vl[0].fst+vr[0].fst;
			else if(SZ(vr)<2||(SZ(vl)>1&&vl[1].fst>=vr[1].fst))res+=vl[1].fst+vr[0].fst;
			else if(SZ(vr)>1)res+=vl[0].fst+vr[1].fst;
			else res+=vl[0].fst;
		}
		else {
			if(SZ(vl))res+=vl[0].fst;
			else if(SZ(vr))res+=vr[0].fst;
		}
		/*for(auto i:vl)cout<<"{"<<i.fst<<","<<i.snd<<"} ";
		cout<<"\n";
		for(auto i:vr)cout<<"{"<<i.fst<<","<<i.snd<<"} ";
		cout<<"\n";*/
		pres;
	}
	return 0;
}
