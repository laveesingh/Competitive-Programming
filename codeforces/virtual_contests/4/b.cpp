#include <iostream>

using namespace std;

int main(void){
	int d, sumTime, minTime, maxTime;
	cin >> d >> sumTime;
	int max_limit[d], min_limit[d], final_limit[d];
	int totalTime = 0;
	for (int i = 0; i < d; i += 1){
		cin >> min_limit[i] >> max_limit[i];
		totalTime += min_limit[i];
		final_limit[i] = min_limit[i];
	}
	// cout << "Total time at the beginning is : " << totalTime << endl;
	if(totalTime > sumTime){
		cout << "NO" << endl;
	}else{
		bool done = false;
		while (!done && totalTime < sumTime){
			done = true;
			for (int i = 0; i < d; i += 1){
				// cout << "Final limit for " << i+1 << " is " << final_limit[i] << " and maxlimit is " << max_limit[i] << endl;
				if (final_limit[i] < max_limit[i]){
					final_limit[i] += 1;
					totalTime += 1;
					if(final_limit[i] < max_limit[i]) done = false;
				}
				if(sumTime == totalTime){
					done = true;
					break;
				}
			}
		}
		// cout << "Total time at the end is : " << totalTime << endl;
		if (sumTime == totalTime){
			cout << "YES" << endl;
			cout << final_limit[0];
			for (int i = 1; i < d; i += 1){
				cout << " " << final_limit[i];
			}
			cout << endl;
		}else{
			cout << "NO" << endl;
		}
	}

}