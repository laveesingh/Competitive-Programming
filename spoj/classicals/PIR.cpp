#include <iostream>
#include <cmath>

using namespace std;


int main(void){
	int t;
	cin >> t;
	while(t--){
		double u, v, w, U, V, W, a, vol, d=12;
		cin>>u>>v>>w>>W>>V>>U;
        a=4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));
        vol = sqrt(a);
        vol /= d;
        printf("%.4lf\n", vol);
	}
}