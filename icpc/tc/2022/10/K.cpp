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

vector<pair<ll,ll>>v;

int main(){FIN;
	ll n,k; cin>>n>>k;
	map<ll,ll>oc;
	fore(i,0,n){
		ll a; cin>>a;
		oc[a]++;
	}
	for(auto i:oc){
		v.pb({i.fst,i.snd});
	}
	ll l=0;
	ll ki=k;
	ll num=v[0].fst;
	ll resi=v[0].snd,res=resi;
	//cout<<v[0].fst<<": "<<resi<<" "<<ki<<"\n";
	fore(i,1,SZ(v)){
		//cout<<v[i].fst<<" ";
		ll salto=((v[i].fst-v[i-1].fst)*resi);
		if(ki-salto<0){
			if(resi>res)res=resi,num=v[i-1].fst;
			else if(resi==res){
				if(v[i-1].fst<num)res=resi,num=v[i-1].fst;
			}
			//cout<<"? "<<resi<<" "<<v[i-1].fst<<"\n";
			while(l<n&&ki-salto<0){
				ki+=(v[i].fst-v[l].fst)*v[l].snd;
				resi-=v[l].snd;
				l++;
			}
		}
		if(l>=n)break;
		ki-=salto,resi+=v[i].snd;
		//cout<<v[i].fst<<": "<<l<<" "<<resi<<" "<<ki<<"\n";
	}
	cout<<res<<" "<<num<<"\n";
	return 0;
}
///"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
