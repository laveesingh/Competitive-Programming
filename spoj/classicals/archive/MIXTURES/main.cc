#include <iostream>
using namespace std;

const int N = 101;
int arr[N],
    color[N][N],
    smoke[N][N];


int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while(cin >> n){
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        smoke[i][j] = 1e9;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int len = 0; len < n; len++){
      for(int i = 0; i < n; i++){
        int j = i + len;
        if(i == j){
          smoke[i][j] = 0, color[i][j] = arr[i];
        }else{
          for(int k = i; k < j; k++){
            if(smoke[i][k]+smoke[k+1][j]+color[i][k]*color[k+1][j] < smoke[i][j]){
              smoke[i][j] = smoke[i][k] + smoke[k+1][j] + color[i][k]*color[k+1][j];  
              color[i][j] = (color[i][k] + color[k+1][j]) % 100;
            }
          }
        }
      }
    }
    cout << smoke[0][n-1] << endl;
  }
}
