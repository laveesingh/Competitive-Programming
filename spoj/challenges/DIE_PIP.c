a[3][3];
int main(i,j,n){
	while(scanf("%d",&n)==1){
		memset(a,0,sizeof(a)); 
		if(n%2)a[1][1]=1,n--; 
		if(n)a[0][0]=a[2][2]=1,n-=2;
		if(n)a[0][2]=a[2][0]=1,n-=2; 
		if(n)a[1][0]=a[1][2]=1;i=9;
		while(i--)printf("%d%s",a[i/3][i%3],i%3==0?"\n":" "); 
	} 
}	
