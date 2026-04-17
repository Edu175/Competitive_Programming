#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<string> gravitas(vector<string> &a) {
   ll n=SZ(a),m=SZ(a[0]);
   vector<pair<ii,ll>>f;
   fore(i,0,n){
   	fore(j,0,m){
   		if(a[i][j]=='<')f.pb({{i,j},0});
   		if(a[i][j]=='A')f.pb({{i,j},1});
   	}
   }
   vector<ll> b(m,n);
   reverse(ALL(f));
  /* for(auto i:f){
   	cout<<"{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<" ";
   }
   cout<<"\n";*/
   char res[n][m];
   fore(i,0,n){
   	fore(j,0,m)res[i][j]='.';
   }
   for(auto i:f){
   	ll j=i.fst.snd;
   	//cout<<i.fst.fst<<","<<j<<" "<<i.snd<<": ";
   	if(i.snd){
   		ii d={b[j]-1,j};
   		b[j]=d.fst-1;
   		res[d.fst][d.snd]='V';
   		res[d.fst-1][d.snd]='A';
   		//cout<<d.fst<<","<<d.snd<<" "<<d.fst-1<<","<<d.snd<<"\n";
   	}
   	else{
   		ii d={min(b[j],b[j+1])-1,j};
   		b[j]=d.fst,b[j+1]=d.fst;
   		res[d.fst][d.snd]='<';
   		res[d.fst][d.snd+1]='>';
   		//cout<<d.fst<<","<<d.snd<<" "<<d.fst<<","<<d.snd+1<<"\n";
   	}
   }
   vector<string> RES(n);
   fore(i,0,n){
   	fore(j,0,m)RES[i].pb(res[i][j]);
   }
   return RES;
}
