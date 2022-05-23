import java.util.*;
import static java.lang.System.out;

class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		while (scn.hasNext()) {

			int n = scn.nextInt();
			boolean p = isPrime(n);
			boolean e = isEmirp(n);
			// out.println(p + "," + e);

			if (p && e)
				out.format("%d is emirp.\n", n);
			else if (p && !e)
				out.format("%d is prime.\n", n);
			else
				out.format("%d is not prime.\n", n);

		}
		scn.close();
	}

	static boolean isPrime(int n) {

		if (n < 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static boolean isEmirp(int n) {
		int original = n;
		n = Integer.parseInt(new StringBuilder(String.valueOf(n)).reverse().toString());

		return isPrime(n) && original != n;
	}
}
