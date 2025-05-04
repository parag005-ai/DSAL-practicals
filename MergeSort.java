public class MergeSort {

    public static void divide(int arr[], int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        
        // Correct recursive calls for the left and right subarrays
        divide(arr, low, mid); // Left part
        divide(arr, mid + 1, high); // Right part
        
        // Correctly call conquer to merge the sorted subarrays
        conquer(arr, low, mid, high);
    }

    public static void conquer(int arr[], int low, int mid, int high) {
        int[] merged = new int[high - low + 1];
        int ind1 = low;
        int ind2 = mid + 1;
        int x = 0;

        // Merging the two halves
        while (ind1 <= mid && ind2 <= high) {
            if (arr[ind1] <= arr[ind2]) {
                merged[x++] = arr[ind1++];
            } else {
                merged[x++] = arr[ind2++];
            }
        }

        // If elements are left in the left half
        while (ind1 <= mid) {
            merged[x++] = arr[ind1++];
        }

        // If elements are left in the right half
        while (ind2 <= high) {
            merged[x++] = arr[ind2++];
        }

        // Copying merged array back to the original array
        for (int i = 0, j = low; i < merged.length; i++, j++) {
            arr[j] = merged[i];
        }
    }

    public static void main(String[] args) {
        int[] arr = {6, 3, 9, 5, 2, 7}; // Test array
        int n = arr.length;

        // Calling divide to sort the array
        divide(arr, 0, n - 1);

        // Display the sorted array
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
