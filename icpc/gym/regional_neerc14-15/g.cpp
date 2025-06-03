#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
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

void c(ii a){
	cout<<a.fst<<" "<<a.snd<<endl;
}

ii tapa,limite,p;
set<ii> sus;

ii calculate(ii a){
	a.fst-=10;
	a.snd-=10;
	if(a.fst>0) a.fst=1;
	if(a.fst<0) a.fst=-1;
	
	if(a.snd>0) a.snd=1;
	if(a.snd<0) a.snd=-1;
	return a;
}

void f(ii dir){
	ii ini = {10,10};
	tapa = {ini.fst - dir.fst,ini.snd-dir.snd};
	fore(i,0,5){
		sus.insert(ini);
		ini.fst+=dir.fst;
		ini.snd+=dir.snd;
	}
	sus.erase({10,10});
}

ii dir_win(ii a){
	if(a==(ii){-1,0}) return {1,0};
	if(a==(ii){0,1}) return {-1,-1};
	if(a==(ii){-1,1}) return {0,-1};
	if(a==(ii){-1,-1}) return {1,0};
	if(a==(ii){0,-1}) return {-1,1};
	return {0,0};
}

ll x,y;
int main(){
	JET
	cin>>x>>y;
	cout<<11<<" "<<10<<endl;
	cin>>p.fst>>p.snd;
	ii dir = calculate(p);
	if(dir.fst==1){
		ii yo = {11,10};
		fore(i,0,4){
			yo.fst-=dir.snd;
			c(yo);
			cin>>x>>y;
		}
		return 0;
	}
	f(dir);
	sus.erase(p);
	if(tapa==(ii){11,10}) tapa = {11,11};
	ii win=dir_win(dir);
	c(tapa);
	cin>>p.fst>>p.snd;
	sus.erase(p);
	c(limite);
	cin>>p.fst>>p.snd;
	sus.erase(p);
	c(*sus.begin());
	cin>>x>>y;
	ii yo ={11,10};
	yo.fst+=win.fst;
	yo.snd+=win.snd;
	yo.fst+=win.fst;
	yo.snd+=win.snd;
	fore(i,0,3){
		c(yo);
		yo.fst+=win.fst;
		yo.snd+=win.snd;
	}
	
	return 0;
	
}