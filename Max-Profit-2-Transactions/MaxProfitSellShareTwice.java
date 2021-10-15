class MaxProfitSellShareTwice {
	static void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static int findMaxProfit(int[] arr) {
		int n = arr.length;
		int[] maxProfitIfSoldByNow = new int[n];
		int[] maxProfitIfBoughtInFuture = new int[n];
		int min = Integer.MAX_VALUE;
		int maxProfit = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++) {
			min = Math.min(min, arr[i]);
			maxProfit = Math.max(maxProfit, arr[i] - min);
			maxProfitIfSoldByNow[i] = maxProfit;
		}
		int max = Integer.MIN_VALUE;
		maxProfit = Integer.MIN_VALUE;
		for(int i = n - 1; i >= 0; i--) {
			max = Math.max(max, arr[i]);
			maxProfit = Math.max(maxProfit, max - arr[i]);
			maxProfitIfBoughtInFuture[i] = maxProfit;
		}

		printArray(maxProfitIfSoldByNow, n);
		printArray(maxProfitIfBoughtInFuture, n);
		maxProfit = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++) {
			maxProfit = Math.max( maxProfit, maxProfitIfSoldByNow[i] + maxProfitIfBoughtInFuture[i]);
			
		}
		return maxProfit;
	}
}
