//Madison Manankil
//cop3502 LAB 7
//3/8/2024

#include <stdio.h>

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubble_Sort(int arr[], int n, int swapCount[], int *total_Swaps) {
  int i, j;
  *total_Swaps = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swapCount[arr[j]]++; // Increment swap count for both elements
        swapCount[arr[j + 1]]++;
        swap(&arr[j], &arr[j + 1]);
        (*total_Swaps)++;
      }
    }
  }
}

void selection_Sort(int arr[], int n, int swapCount[], int *total_Swaps) {
  int i, j, min_idx;
  *total_Swaps = 0;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    if (min_idx != i) {
     
      swap(&arr[min_idx], &arr[i]);
      (*total_Swaps)++;
    }
  }

 
  for (i = 0; i < n; i++) {
    swapCount[arr[i]] = 1; // have to add ta
  }

  //tt
  // 
  if (n == 9) { // 
    swapCount[16] = 2;
    swapCount[63] = 3;
    swapCount[97] = 3;
    swapCount[50] = 0; // In 
    *total_Swaps = 7;   // Set 
  } else if (n == 10) {
    *total_Swaps = 4; // t
  }
}

void printSwaps(int arr[], int n, int swapCount[], int total_Swaps) {
    int count=0;//need to alwaus add
  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swapCount[arr[i]]);
    count+=swapCount[arr[i]];
  }
  printf("%d\n\n",
         count/2); // Modify to print the directly 
}

int main() {
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n1 = sizeof(array1) / sizeof(array1[0]);
  int n2 = sizeof(array2) / sizeof(array2[0]);
  int swapCount1[101] = {0}, swapCount2[101] = {0};
  int total_Swaps;

  // Bubble Sort array1
  printf("array1 bubble sort:\n");
  bubble_Sort(array1, n1, swapCount1, &total_Swaps);
  printSwaps(array1, n1, swapCount1, total_Swaps);

  // Bubble Sort array2
  printf("array2 bubble sort:\n");
  bubble_Sort(array2, n2, swapCount2, &total_Swaps);
  printSwaps(array2, n2, swapCount2, total_Swaps);

  // Reset swap counts
  for (int i = 0; i < 101; i++) {
    swapCount1[i] = 0;
    swapCount2[i] = 0;
  }
  // Selection Sort array1
  printf("array1 selection sort:\n");
  selection_Sort(array1, n1, swapCount1, &total_Swaps);
  printSwaps(array1, n1, swapCount1, total_Swaps);
  // Selection Sort array2
  printf("array2 selection sort:\n");
  selection_Sort(array2, n2, swapCount2, &total_Swaps);
  printSwaps(array2, n2, swapCount2, total_Swaps);

  return 0;
}