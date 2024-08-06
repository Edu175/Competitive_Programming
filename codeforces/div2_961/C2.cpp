#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<__int128,ll> ii;

bool les(ii a, ii b){
	// cout<<"\n";
	cout<<(ll)a.fst<<","<<a.snd<<" "<<(ll)b.fst<<","<<b.snd<<"\n";
	ll mn=min(a.snd,b.snd);
	a.snd-=mn,b.snd-=mn;
	// cout<<(ll)a.fst<<","<<a.snd<<" "<<(ll)b.fst<<","<<b.snd<<"\n";
	fore(_,0,a.snd)a.fst*=a.fst;
	fore(_,0,b.snd)b.fst*=b.fst;
	return a.fst<b.fst;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ii>b(n);
		fore(i,0,n)b[i]={a[i],0};
		ll res=0;
		fore(i,1,n){
			if(b[i].fst<b[i-1].fst){
				res+=(b[i].snd=b[i-1].snd+1);
				if(b[i].fst==1){res=-1;break;}
			}
			while(les(b[i],b[i-1]))b[i].snd++,res++;
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
