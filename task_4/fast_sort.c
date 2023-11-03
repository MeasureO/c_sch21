#include <stdio.h>
#define NMAX 10

void swap(int *a, int *b);
void heapify(int *a, int n, int i);
void heap_sort(int *a, int n);
int partition(int *a, int low, int high);
void quick_sort(int *a, int low, int high);
void print(int *a, int size);
int input(int *a, int *l);

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quick_sort(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

void print(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        if (i != size - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

int input(int *a, int *l) {
    int flag = 1;
    double tmp = 0.0;
    *l = 0;
    char c = '$';
    for (int i = 0; i < NMAX; i++) {
        int input_code = scanf("%lf", &tmp);
        if (input_code != 1 || !(tmp - (int)tmp < 1e-12)) {
            flag = 0;
            break;
        }
        a[i] = (int)tmp;
        *l += 1;
        if (*l == NMAX) {
            flag = 0;
            break;
        }
        c = getchar();
        if (c == 0x0a) break;
    }
    return flag;
}

void copy(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

int main() {
    int data1[NMAX];
    int data2[NMAX];
    int n;
    if (input(data1, &n)) {
        copy(data1, data2, n);
        quick_sort(data1, 0, n - 1);
        print(data1, n);
        printf("\n");
        heap_sort(data2, n);
        print(data2, n);
    } else
        printf("n/a");
}
