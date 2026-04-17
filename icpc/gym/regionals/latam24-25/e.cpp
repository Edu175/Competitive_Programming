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
	int j=a[x];
	int x2=x,y2=y;
	if(x>y) x2=-x,y2=-y;
	if(m<0 && y2<=0) y2--;
	else if(m<0) y2++; 
	fore(i2,x2,y2){
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
			if(j<=0 || j>=n) yata=0;
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
		ultimo=i;
		if(flag && x>ant){
			cout<<"*\n";
			return 0;
		}
		if(x<ant && !flag) flag=1,med=i;
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
			int j=1;
			while(vis[j])j++;
			if(primero!=n-1)a[n-1]=j,vis[j]++;
			if(primero!=n-1)ir(n-1,primero+1,1);
			arr();
		}
		else if(n-primero<=a[primero]){
			ir(primero,n,-1);
			int j=1;
			while(vis[j])j++;
			if(primero!=0)a[0]=j,vis[j]++;
			if(primero!=0)ir(0,primero-1,1);
		}
		else{
			invalido();
			return 0;
		}
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
		int penul=ultimo-1;
		while(a[penul]==0) penul--;
		if(a[0]==0){
			if(vis[1]!=0){
				invalido();
				return 0;
			}
			a[0]=1;
		} 
		ir(0,ultimo,1);
		if(vis[n]==0 && ultimo+1<n) a[ultimo+1]=n,vis[n]=1;
		else if(ultimo+1<n) yata=0;
		else if(a[ultimo]!=n) yata=0;
		ir(ultimo+1,n,-1);
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1; reset();
		ir(ultimo,n,-1);
	
		ir(ultimo-1,0,-1);
		yata=yata&&valido();
		if(yata)arr();
		else invalido();
		return 0;
	}
	if(solob){
		int seg=primero+1;
		if(a[0]==0){
			if(vis[n]!=0){
				invalido();
				return 0;
			}
			a[0]=n;
		} 
		while(a[seg]!=0) seg++;
		ir(primero,n,-1);
		if(vis[n]==0 && primero-1>=0) a[primero+1]=n,vis[n]=1;
		else if(primero-1<n) yata=0;
		else if(a[primero]!=n) yata=0;
		if(primero-1>=0)ir(primero-1,0,-1);
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1; reset();
		ir(primero,0,-1);
		ir(primero+1,n,-1);
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
		fore(i,0,primero){
			if(j==a[primero]){
				invalido();
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
		for(ll i=n-1;i>=ultimo;i--){
			while(vis[j])j++;
			if(j>=a[ultimo]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
	}
	else{
		for(ll i=n-1;i>=ultimo;i--){
			if(j>=a[ultimo]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
		fore(i,0,primero){
			while(vis[j])j++;
			if(j>=a[primero]){
				invalido();
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
	}
	vis[0]=1;
	j=0;
	while(primero<x && ultimo>y){
		if(a[primero]!=0){
			if(a[primero]<j){
				invalido();
				return 0;
			}
			primero++;continue;
		}
		else if(a[ultimo]!=0){
			if(a[primero]<j){
				invalido();
				return 0;
			}
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
	else{
		for(ll i=ultimo;i>=y;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
	}
	fore(i,1,x){
		if(a[i]<a[i+1]){
			cout<<"*\n";
			return 0;
		}
	}
	fore(i,y+1,n){
		if(a[i]>a[i+1]){
			cout<<"*\n";
			return 0;
		}
	}
	if(a[med]==n){
		ir(med,x,-1);
		ir(med,y,-1);
		yata=yata&&valido();
		if(yata) arr();
		if(!yata) invalido();
		return 0;
	}
	else{
		fore(i,0,MAXN) vis2[i]=vis[i],a2[i]=a[i];
		ir(x,med,1);
		ir(med+1,y,-1);
		yata=yata&&valido();
		if(yata){arr();return 0;}
		yata=1;
		reset();
		ir(y,med,1);
		ir(med-1,x,-1);
		yata=yata&&valido();
		if(yata)arr();
		else invalido();
		return 0;
	}
}