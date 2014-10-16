public class FixedPointTheorem {
	public double cycleRange(double R) {
		double res = 0.0;
		double x = 0.25;
		double min = Double.MAX_VALUE;
		double max = -1.0;
		for (int i = 0; i < 200000; ++i) {
			double t = R*x*(1-x);
			x = t;
		}
		for (int i = 0; i < 1000; ++i) {
			double t = R*x*(1-x);
			max = Math.max(max, x);
			min = Math.min(min, x);
			x = t;
		}
		res = max-min;
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
