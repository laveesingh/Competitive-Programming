#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	int a[] = {2 , 3 , 5 , 7 , 11, 4, 9, 25, 49 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47};
	char temp[4];
	string flag = "";
	int count = 0;
	for (int i = 0; i < 19; i += 1){
		printf("%d\n", a[i]);
		fflush(stdout);
		scanf("%s", temp);
		flag = temp;
		if (flag == "yes"){
			count += 1;
		}
	}
	if (count >= 2){
		printf("composite\n");
		fflush(stdout);
	}else{
		printf("prime\n");
		fflush(stdout);
	}

}