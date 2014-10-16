import java.util.*;

public class SpeedRadar {
	public double averageSpeed(int minLimit, int maxLimit, int[] readings) {
		double res = 0.0;
		int sum = 0;
		int fail = 0;
		int cnt = 0;
		for (int i = 0; i < readings.length; i++) {
			if (readings[i] < minLimit || readings[i] > maxLimit) {
				fail++;
			} else {
				cnt++;
				sum += readings[i];
			}
		}
		int n = readings.length;
		double p = (fail * 1.0 / n) * 100.0;
		if (p > 10.0)
			return 0.0;
		res = 1.0 * sum / cnt;
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
