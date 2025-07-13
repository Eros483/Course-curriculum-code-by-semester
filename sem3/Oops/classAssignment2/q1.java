import java.util.Scanner;

public class q1 {

    public static boolean evenChecker(int x) {
        return x % 2 == 0;
    }

    public static boolean primeChecker(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static int evenInitial(int evenMin, int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (evenChecker(arr[i])) {
                evenMin = arr[i];
                break;
            }
        }
        return evenMin;
    }

    public static int evenMin(int evenMin, int[] arr, int i) {
        if (i >= arr.length) {
            return evenMin;
        }
        if (evenChecker(arr[i])) {
            if (arr[i] < evenMin || evenMin == -1) {
                evenMin = arr[i];
            }
        }
        return evenMin(evenMin, arr, ++i);
    }

    public static int oddInitial(int maxOdd, int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (!evenChecker(arr[i])) {
                maxOdd = arr[i];
                break;
            }
        }
        return maxOdd;
    }

    public static int oddMax(int maxOdd, int[] arr, int i) {
        if (i >= arr.length) {
            return maxOdd;
        }
        if (!evenChecker(arr[i])) {
            if (arr[i] > maxOdd || maxOdd == -1) {
                maxOdd = arr[i];
            }
        }
        return oddMax(maxOdd, arr, ++i);
    }

    public static void factorStoring(int[] arr, int[] factors) {
        int k = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 1; j <= arr[i]; j++) {
                if (arr[i] % j == 0) {
                    factors[k] = j;
                    k++;
                }
            }
        }
    }

    public static void primeFactors(int[] factors, int[] primeFactors) {
        int k = 0;
        for (int i = 0; i < factors.length; i++) {
            if (factors[i] > 0 && primeChecker(factors[i])) {
                primeFactors[k] = factors[i];
                k++;
            }
        }
    }

    public static int largestPrimeFactor(int[] primeFactors, int maxPrime, int i) {
        if (i >= primeFactors.length || primeFactors[i] == 0) {
            return maxPrime;
        }
        if (primeFactors[i] > maxPrime) {
            maxPrime = primeFactors[i];
        }
        return largestPrimeFactor(primeFactors, maxPrime, ++i);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter length of array wanted: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Please enter array element: ");
            arr[i] = sc.nextInt();
        }

        System.out.println("The smallest even number in the array is: " + evenMin(-1, arr, 0));

        System.out.println("The largest odd number in the array is: " + oddMax(-1, arr, 0));

        int[] factors = new int[100 * n];
        factorStoring(arr, factors);

        int[] primeFactors = new int[100 * n];
        primeFactors(factors, primeFactors);

        System.out.println("The largest prime factor among the factors of all elements in the array is: " +
                largestPrimeFactor(primeFactors, -1, 0));
    }
}
