#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

using namespace std;

const int m_size = 32768;

void segmented_sieve(int limit, int segment_size=m_size){
    int sqroot = (int) sqrt((double) limit);
    int count = (limit < 2 ) ? 0 : 1;
    int s = 2;
    int n = 3;

    vector<int> sieve(segment_size);
    vector<int> is_prime(sqroot+1, 1);
    is_prime[0] = 0;
    is_prime[1];
    for (int i = 4; i <= sqroot; i += 2){
        is_prime[i]  = 0;
    }
    for (int i = 3; i*i <= sqroot; i += 2){
        if (is_prime[i]){
            for (int j = i*i; j <= sqroot; j +=2*i){
                is_prime[j] = 0;
            }
        }
    }
    vector<int> primes;
    vector<int> next;

    for (int low=0; low <= limit; low += segment_size){
        fill(sieve.begin(), sieve.end(), 1);


    }

}
int main(void){
    segmented_sieve(100000);
}
