#include <iostream>

using namespace std;

class Point{
public:
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}
};

void solve(){
	int n, x, y;
	cin >> n;
	Point a[n];
	for (int i = 0; i < n; i += 1){
		cin >> x >> y;
		a[i] = Point(x, y);
	}
	int minx=INF, miny=INF, maxx=-INF,maxy=-INF, minxi, minyi, maxyi;
	bool flag;
	for (int i = 0; i < n; i += 1){
		if (a[i].x < minx){
			minx = a[i].x;
			miny = a[i].y;
			maxy = a[i].y;
			minyi = i;
			maxyi = i;
		}else if(a[i].x == minx){
			if (a[i].y > maxy){
				maxy = a[i].y;
				maxyi = i;
			}
			if (a[i].y < miny){
				miny = a[i].y;
				minyi = i;
			}
		}
	}
	flag = false;
	for (int i = 0; i < n; i += 1){
		if (a[i].y > a[maxyi]){
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << maxyi+1 << " SE" << endl;
		return;
	}// we are done finding the answer
	flag = false;
	for (int i = 0; i < n; i += 1){
		if (a[i].y < a[minyi]){
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << minyi+1 << " NE" << endl;
		return;
	}// we are done finding the answer
	maxx = -INF;
	for (int i = 0; i < n; i += 1){
		if (a[i].x > maxx){
			maxx = a[i].x;
			miny = a[i].y;
			maxy = a[i].y;
			minyi = i;
			maxyi = i;
		}else if(a[i].x == maxx){
			if (a[i].y > maxy){
				maxy = a[i].y;
				maxyi = i;
			}
			if (a[i].y < miny){
				miny = a[i].y;
				minyi = i;
			}
		}
	}
	flag = false;
	for (int i = 0; i < n; i += 1){
		if (a[i].y > a[maxyi]){
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << maxyi+1 << " SW" << endl;
		return;
	}// we are done finding the answer

	flag = false;
	for (int i = 0; i < n; i += 1){
		if (a[i].y < a[minyi]){
			flag = true;
			break;
		}
	}
	if (flag == false) {
		cout << minyi+1 << " NW" << endl;
		return;
	}// we are done finding the answer

	miny = INF;
	maxy = -INF;
	for (int i = 0; i < n; i += 1){
		if (a[i].y < miny){
			miny = a[i].y;
			minx = a[i].x;
			minxi = i;
			maxx = a[i].x;
			maxxi = i;
		}else if(a[i].y == miny){
			if (a[i].x < minx){
				minx = a[i].x;
				
			}
		}
	}

}

int main(void){

}