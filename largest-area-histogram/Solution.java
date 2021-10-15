import java.util.Stack;
class Solution {
	static void findNextSmaller(int[] arr, int[] ns) {
		int n = arr.length;
		Stack<Integer> s = new Stack<>();
		for(int i = n - 1; i >= 0; i--) {
			while(!s.isEmpty() && arr[s.peek()] >= arr[i]) {
				s.pop();
			}
			ns[i] = s.isEmpty() ? n : s.peek();
			s.push(i);
		}



	}
	static void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	static void findPreviousSmaller(int[] arr, int[] ps)
	{
		int n = arr.length;
		//5 3 1 9 4 8 2 0 4 3      n = 10
		Stack<Integer> s = new Stack<>();
		for(int i = 0; i < n; i++) {
			while(!s.isEmpty() && arr[s.peek()] >= arr[i]) {
				s.pop();
			}
			if(s.isEmpty()) {
				ps[i] = -1;
			}
			else {
				ps[i] = s.peek();
			}
			s.push(i);
		}
	}

	static int solve(int[] arr) {
		int n = arr.length;
		int[] ps = new int[n];
		int[] ns = new int[n];
		findPreviousSmaller(arr, ps);
		findNextSmaller(arr, ns);
		int ans = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++) {
			ans = Math.max(ans, (ns[i] - ps[i] - 1) * arr[i]);
		}
		return ans;
	}

}
