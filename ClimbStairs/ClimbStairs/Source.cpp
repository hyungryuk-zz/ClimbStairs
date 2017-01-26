#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	int numOfStairs;
	scanf("%d", &numOfStairs);
	int *dp = (int*)malloc(sizeof(int)*numOfStairs);
	int *arr = (int*)malloc(sizeof(int)*numOfStairs);
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	scanf("%d", &arr[2]);
	dp[0] = arr[0];
	for (int i = 1; i<3; i++) {
		if (i == 1) {
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		}
		else {
			dp[i] = max(dp[i - 2] + arr[i], arr[i - 1] + arr[i]);
		}
	}
	for (int i = 3; i < numOfStairs; i++) {
		scanf("%d", &arr[i]);
		dp[i] = max(dp[i - 2] + arr[i],dp[i-3]+arr[i-1]+arr[i]);
	}
	printf("%d", dp[numOfStairs - 1]);
}