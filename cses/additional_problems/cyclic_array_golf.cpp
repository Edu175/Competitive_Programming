#import <iostream>
#define f(b) for(i=0;i<b;++i)
int a['   '],F[25]['   '],p,n,h,i,x,k,v;
main(){
	std::cin>>n>>h;
	f(n)std::cin>>v,a[i]=a[i+n]=v;
	f('   '){
		for(;p<'   '&&k<=h;)k+=a[p++];
		F[0][i]=p-1;
		k-=a[i];
	}
	for(;++x<20;)f('   ')F[x][i]=F[x-1][F[x-1][i]];
	f(n){
		h=1,x=i;
		for(k=19;k--;)v=F[k][x],v<i+n?x=v,h+=1<<k:h;
		p=h<p?h:p;
	}
	std::cout<<p;
}
