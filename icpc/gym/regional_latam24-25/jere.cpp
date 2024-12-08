#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
	
const int MAXN=2e5+9;
ll a[MAXN],vis[MAXN],a2[MAXN],vis2[MAXN];
ll n;
bool yata=1;

void reset(){
	fore(i,0,MAXN) a[i]=a2[i],vis[i]=vis2[i];
}
void ir (int x, int y, int m){
	int j;
	(m<0)? j=n:j=1;
	int x2=x,y2=y;
	if(x>y) x2=-x,y2=-y;
	fore(i2,x2,y2+1){
		//cout<<i2<<"\n";
		int i=i2;
		if(x>y) i=-i2;
		if(a[i]!=0){
			if(m>0 && j>a[i]) yata=0;
			if(m<0 && j<a[i]) yata=0;
			j=a[i];
			continue;
		}
		while(vis[j]){
			j+=m;
			if(j<=0 || j>n) yata=0;
			if(!yata) break;
		}
		if(!yata) break;
		a[i]=j;
		vis[j]++;
	}
}

void invalido(){
	cout<<"*\n";
}

void arr(){
	fore(i,0,n) cout<<a[i]<<" ";
	cout<<"\n";
}

bool valido(){
	if(a[0]>n || a[0]<=0) return false;
	bool flag=0;
	fore(i,1,n){
		if(a[i]>n || a[i]<=0) return false;
		if(a[i]<a[i-1]) flag=1;
		if(a[i]>a[i-1] && flag) return false;
	}
	return true;
}

int main(){
	JET
	vis[0]=1;
	cin>>n;
	bool flag=0;
	ll ant=-1;
	ll primero=-1;
	ll ultimo=-1;
	ll med=-1;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=x;
		if(x==0) continue;
		if(primero==-1) primero=i;
		if(x<ant && !flag) flag=1,med=ultimo;
		ultimo=i;
		if(flag && x>ant){
			cout<<"*\n";
			return 0;
		}
		ant=x;
		vis[x]=1;
	}
	fore(i,0,MAXN)vis2[i]=vis[i],a2[i]=a[i];
	if(ultimo==-1){
		fore(i,1,n+1) cout<<i<<" ";
		cout<<"\n";
		return 0;
	}
	if(ultimo==primero){
		if(a[primero]>primero){
			ir(primero,0,-1);
			ir(n-1,primero+1,1);
		}
		else if(n-primero<=a[primero]){
			ir(primero,n-1,-1);
			ir(0,primero-1,1);
		}
		else{
			invalido();
			return 0;
		}
		//arr();
		if(valido()) arr();
		else invalido();
		return 0;
	}
	bool solob = true;
	bool solos = true;
	ant=-1;
	fore(i,0,n) if(a[i]!=0) {if(a[i]<ant) solos=false;ant=a[i];}
	ant=n+5;
	fore(i,0,n) if(a[i]!=0) {if(a[i]>ant) solob=false;ant=a[i];}
	if(solos){
		ir(0,ultimo,1);
		ir(ultimo+1,n-1,-1);
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1; reset();
		ir(ultimo,n-1,-1);
		ir(ultimo-1,0,-1);
		yata=yata&&valido();
		if(yata)arr();
		else invalido();
		return 0;
	}
	if(solob){
		ir(primero,n-1,-1);
		ir(primero-1,0,-1);
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1; reset();
		ir(primero,0,-1);
		ir(primero+1,n-1,-1);
		yata=yata&&valido();
		if(yata)arr();
		if(!yata) invalido();
		return 0;
	}
	
	
	int x=med-1,y=med+1;
	while(a[x]==0) x--;
	while(a[y]==0) y++;
	int j=1;
	if(a[primero]<a[ultimo]){
		ir(0,primero,1);
		ir(n-1,ultimo,1);
	}
	else{
		ir(n-1,ultimo,1);
		ir(0,primero,1);
	}
	j=0;
	while(primero<x && ultimo>y){
		if(a[primero]!=0){
			primero++;continue;
		}
		else if(a[ultimo]!=0){
			ultimo--;continue;
		}
		
		while(vis[j])j++;
		if(a[primero-1]<a[ultimo+1]){
			a[primero]=j;
			vis[j]=1;
			primero++;
		}
		else{
			a[ultimo]=j;
			vis[j]=1;
			ultimo--;
		}
	}
	if(primero<x){
		fore(i,primero,x){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
	}
	else if(ultimo>y){
		for(ll i=ultimo;i>=y;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
	}
	fore(i,1,x){
		if(a[i]<a[i-1]){
			cout<<"*\n";
			return 0;
		}
	}
	fore(i,y+1,n){
		if(a[i]>a[i-1]){
			cout<<"*\n";
			return 0;
		}
	}
	if(a[med]==n){
		if(a[x]<a[y]){
			ir(x,med,1);
			ir(y,med,1);
		}
		else{
			ir(y,med,1);
			ir(x,med,1);
		}
		yata=yata&&valido();
		if(yata) arr();
		if(!yata) invalido();
		return 0;
	}
	else{
		fore(i,0,MAXN) vis2[i]=vis[i],a2[i]=a[i];
		if(a[x]<a[y]){
			ir(x,med,1);
			ir(y,med+1,1);
		}
		else{
			ir(y,med+1,1);
			ir(x,med,1);
		}
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1;
		reset();
		if(a[x]<a[y]){
			ir(x,med-1,1);
			ir(y,med,1);
		}
		else{
			ir(y,med,1);
			ir(x,med-1,1);
		}
		yata=yata&&valido();
		if(yata)arr();
		else invalido();
		return 0;
	}
}