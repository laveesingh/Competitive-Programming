#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define INF 1000000000

class shop{
public:
	int m, k, c;
	int x, y, z;
	shop(){}
	shop(int xi, int yi, int zi, int mouse, int keyboard, int cpu){
		x = xi;
		y = yi;
		z = zi;
		m = mouse;
		k = keyboard;
		c = cpu;
	}
	bool operator==(shop b){
		return (x == b.x && y == b.y && z == b.z);
	}
};

int n, ns;
shop *a;

int dist(shop a, shop b){
	int ans = 0;
	ans += (a.x-b.x)*(a.x-b.x);
	ans += (a.y-b.y)*(a.y-b.y);
	ans += (a.z-b.z)*(a.z-b.z);
	return ans;
}

int find(shop b){
	for (int i = 0; i < ns; i += 1){
		if (b == a[i]) return i;
	}
	return -1;
}

int solve(int m, int k, int c, int cost, shop cur, int visited[]){
	if (m >= n && k >= n && c >= n){
		return cost;
	}else{
		int min = INF, temp, j;
		for (int i = 0; i < ns; i += 1){
			if (visited[i]){
				j = find(cur);
				visited[j] = 1;
				/*
					Here is where we're getting the error: segmentation fault....
					Actually we are not reaching any basecase, as the m, k, c are being passed as were, need to eliminate this recursive call.
				*/
				temp = solve(m, k, c, cost+dist(cur,a[i]), a[i], visited);
			}else{
				visited[j] = 1;
				temp = solve(m+a[i].m, k+a[i].k, c+a[i].c, cost+dist(cur, a[i]), a[i], visited);
			}
			if (temp < min) min = temp;
		}
		visited[j] = 0;
		return min;
	}
}

void Print(vector<int> a){
	for (int x: a){
		cout << x  << " " ;
	}
	cout << endl;
}

int main(void){
	int  xi, yi, zi, m, mo, ke, cp;
	cin >> n;
	cin >> xi >> yi >> zi;
	shop init = shop(xi, yi, zi, 0, 0, 0);
	cout << "Initial shop created: " << endl;
	cin >> ns; // no. of shops
	a = new shop[ns];
	for (int i = 0 ; i < ns; i += 1){
		cin >> xi >> yi >> zi >> mo >> ke >> cp;
		a[i] = shop(xi, yi, zi, mo, ke, cp);
	}
	int visited[ns] = {0};
	int ans = solve(0, 0, 0, 0, init, visited);
	cout << ans << endl;

}

/*
Solution to the visited problem:
1. create a vector of the visited array
2. check everytime if the shop is visited,
make sure not to include the items from that shop
*/