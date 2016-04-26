#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>


using namespace std;


bool solve(char* a){
	int flips = 0;
	for (int i = 1; a[i] != '\0' ; i += 1){
		if (a[i] != a[i-1]){
			flips += 1;
			if (flips >= 2) return true;
		}else{
			flips = 0;
		}
	}
	return false;
}

int main(void){
	int t;
	scanf("%d",&t);
	char* a = new char[100001];
	while (t--){
		scanf("%s",a);
		if (solve(a)){
			printf("Good\n");
		}else{
			printf("Bad\n");
		}
	}
}