public class MostProfitable {
	public String bestItem(int[] costs, int[] prices, int[] sales,
			String[] items) {
		String res = "";
		int n = items.length;
		int best = Integer.MIN_VALUE;
		for (int i = 0; i < n; ++i) {
			int x = prices[i]*sales[i]-costs[i]*sales[i]; 
			if ( x > 0 && x > best ) {
				res = items[i];
				best = x;
			}
		}
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
