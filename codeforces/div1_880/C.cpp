#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//v2
//const ll it=100;
ll rnd(){ // < 2³⁰
	return ((1ll*rand())<<15)+rand();
}
int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll k; cin>>k;
		ll n=(1ll<<(k+1));
		ll a[n],xp[n+1]; xp[0]=0;
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1]; // l-->l-1 , r-->r
		map<ll,ll>oc;
		vector<ll>res;
		fore(i,0,n+1){
			if(!oc.count(xp[i]))oc[xp[i]]=i;
			else if(oc[xp[i]]<i-1){
				res={oc[xp[i]],i-1,i-1,i};
			}
		}
		map<ll,ii>mp;
		set<ii>st;
		//imp(xp);
		while(!SZ(res)){
			ll l=rnd()%(n+1),r=rnd()%(n+1);
			if(l==r)continue;
			if(l>r)swap(l,r);
			if(st.count({l,r}))continue;
			st.insert({l,r});
			ll v=xp[l]^xp[r];
			/*cout<<l<<" "<<r<<" = "<<v<<"\n";
			cout<<"st:: ";
			for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";
			cout<<"\n";
			for(auto i:mp[v])cout<<i.fst<<","<<i.snd<<" ";
			cout<<"\n";*/
			if(mp.count(v)){
				vector<ll>resi={mp[v].fst,mp[v].snd,l,r};
				sort(ALL(resi));
				//cout<<i.fst<<","<<i.snd<<": "; imp(resi);
				if(resi[0]<resi[1]&&resi[2]<resi[3]){
					res=resi;
					break;
				}
			}
			mp[v]={l,r};
		}
		//imp(res);	
		if(!SZ(res))cout<<"-1\n";
		else {
			ll l0=res[0],r0=res[1],l1=res[2],r1=res[3]; // index 0, [l,r)
//================================CHECKER==================================
			assert(0<=l0&&r1<=n);
			ll x=0;
			fore(i,l0,r0)x^=a[i];
			fore(i,l1,r1)x^=a[i];
			assert(x==0);
//==================================END====================================
			cout<<l0+1<<" "<<r0<<" "<<l1+1<<" "<<r1<<"\n";
		}
	}
	return 0;
}