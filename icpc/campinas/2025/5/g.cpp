#include <bits/stdc++.h>
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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool f=false;
void flip(string &s){
	f=true;
	fore(i,0,SZ(s)){
		(s[i]=='a') ? s[i]='b':s[i]='a';
	}
}

int main(){
	JET
	string original; cin>>original; ll n=SZ(original);
	int atot=0,btot=0,am1=0,bm1=0,am2=0,bm2=0,m=0;
	string s,s1;
	fore(i,0,n){
		if(i<n/2){
			s.pb(original[i]);
			(original[i]=='a')? am1++:bm1++;
		}
		if(i>(n-1)/2){
			s1.pb(original[i]);	
			(original[i]=='a')? am2++:bm2++;
		}
		if(i==n/2){
			(original[i]=='a')? m=1:m=0;
		} 
		(original[i]=='a')?atot++:btot++;
	}
	if(atot%2==1 && btot%2==1){
		cout<<-1;
		return 0;
	}
	if(am1>(atot)/2){
		flip(original); 
		swap(am1,bm1);
		swap(am2,bm2);
		swap(atot,btot);
		flip(s);
		flip(s1);
		m^=1;
	}
	// cout<<"atot: "<<atot<<" btot "<<btot<<" am1 "<<am1<<" bm1 "<<bm1<<" am2 "<<am2<<" bm2 "<<bm2<<" m "<<m<<" s "<<s<<" s1 "<<s1<<"\n";
	
	
	ll rta=0;
	ll ya=0;
	reverse(ALL(s));
	string news,news1;
	
	//aca vamos a amontonar al final de la primer mitad y al principio de la primer mitad, no estoy guardando amontones
	ll as=0,bs=0;
	if(n%2==1) (m==1)? as++:bs++;
	fore(i,0,SZ(s)){
		if(s[i]=='b' && ya<bm1-btot/2){
			rta+=(i-ya);
			ya++;
			bs++;
		}
		else news.pb(s[i]);
	}
	ya=0;
	fore(i,0,SZ(s1)){
		if(s1[i]=='a' && ya<am2-atot/2){
			rta+=(i-ya);
			ya++;
			as++;
		}
		else news1.pb(s1[i]);
	}
	reverse(ALL(news));
	reverse(ALL(news1));
	while(SZ(news)<n/2) news.pb('a');
	while(SZ(news1)<n/2) news1.pb('b');
	rta+=as*bs;
	
	// cout<<"rta "<<rta<<" as "<<as<<" bs "<<bs<<" news "<<news<<" news1 "<<news1<<" s "<<s<<" s1 "<<s1<<endl;
	
	// ya deberia tener todo pagado vamos a terminar de hacer los swaps
	queue<int> qa,qb;
	// cout<<news<<" "<<news1<<endl;
	fore(i,0,SZ(news1)){
		(news1[i]=='a') ? qa.push(i):qb.push(i);
	}
	
	fore(i,0,SZ(news)){
		if(news[i]=='a'){
			ll x = qa.front();
			qa.pop();
			rta+=max(0ll,x-i);
			// cout<<"iteracion "<<i<<" rta "<<rta<<endl;
		}
		if(news[i]=='b'){
			ll x = qb.front();
			qb.pop();
			rta+=max(0ll,x-i);
			// cout<<"iteracion "<<i<<" rta "<<rta<<endl;
			
		}
	}
	cout<<rta<<"\n";
	
	
	return 0;
}


// atot: 4 btot 3 am1 1 bm1 2 am2 2 bm2 1 m 0 s abb s1 aab
// rta 0 as 0 bs 2 news aba news1 baa s bba s1 aab
// iteracion 0 rta 1
// iteracion 1 rta 1
// iteracion 2 rta 1
// 1
