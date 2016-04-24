#include <stdio.h>
#include <time.h>

/*Our binary search makes two tests inside the loop, when one would suffice 
 * (at the price of more tests outside.) 
 * Write a version with only one test inside the loop
 * and measure the difference in run-time.*/

int binsearch(int x, int v[], int n);
int bin_search(int x, int v[], int n);

int main() {
    clock_t time;
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    time = clock();
    printf("%d\n", binsearch(7, v, 10));
    printf("%lu clocks\n", clock() - time);

    time = clock();
    printf("%d\n", bin_search(7, v, 10));
    printf("%lu clocks\n", clock() - time);
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int bin_search(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  mid = (low+high)/2;

  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid +1;
    else
      low = mid +1;
    mid = (low+high)/2;
  }

  return (x == v[mid]) ? mid : -1;
}
