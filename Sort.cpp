#include "Sort.h"

//// Algorithm Selection Sort

//! Selection Sort (for time)
void SelectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}
//? Selection Sort( for comparision)
void SelectionSort_comp(int *a, int n, long long &comp)
{
    for (int i = 0; ++comp && i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (++comp && a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

//// Algorithm Insertion Sort

//! Insertion Sort(for time)
void InsertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
//? Insertion Sort(for comparision)
void InsertionSort_comp(int *a, int n, long long &comp)
{
    comp = 0;
    for (int i = 1; ++comp && i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while ((++comp && j >= 0) && (++comp && a[j] > v))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

//// Algorithm Bubble Sort

//! Bubble Sort(for time)
void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                check = false;
            }
        }
        if (check==true)
            return;
    }
}
//? Bubble Sort( for comparison)
void BubbleSort_comp(int *a, int n, long long &comp)
{
    for (int i = 0; ++comp&&i < n; i++)
    {
        bool check = true;
        for (int j = n - 1; ++comp && j >= i + 1; j--)
        {
            if (++comp && a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                check = false;
            }
        }
        if (++comp && check==true)
            return;
    }
}

//// Algorithm Shaker Sort

//! Shaker Sort(for time)
void ShakerSort(int *a, int n)
{
    int left = 1, right = n - 1, k = n;
    do
    {
        bool check = true;
        for (int i = right; i >= left; i--)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
                check = false;
            }
        }
        if (check==true)
            return;
        check = true;
        left = k + 1;
        for (int i = left; i <= right; i++)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
                check = false;
            }
        }
        if (check==true)
            return;
        right = k - 1;
    } while (left <= right);
}
//? Shaker Sort(for comparision)
void ShakerSort_comp(int *a, int n, long long &comp)
{
    int left = 1, right = n - 1, k = n;
    do
    {
        bool check = true;
        for (int i = right;++comp&& i >= left; i--)
        {
            if (++comp && a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
                check = false;
            }
        }
        if (++comp && check)
            return;
        check = true;
        left = k + 1;
        for (int i = left; ++comp && i <= right; i++)
        {
            if (++comp && a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
                check = false;
            }
        }
        if (++comp && check)
            return;
        right = k - 1;
    } while (++comp && left <= right);
}

//// Algorithm Shell Sort

//!  Shell Sort(for time)
void ShellSort(int *a, int n)
{
    int interval = n / 2;
    while (interval > 0)
    {
        for (int i = interval; i < n; i++)
        {
            int x = a[i];
            int j = i;
            while (j >= interval && a[j - interval] > x)
            {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = x;
        }
        interval = interval / 2;
    }
}

//?  Shell Sort(for comparision)
void ShellSort_comp(int *a, int n, long long &comp)
{
    int interval = n / 2;
    while (++comp && interval > 0)
    {
        for (int i = interval; ++comp && i < n; i++)
        {
            int x = a[i];
            int j = i;
            while ((++comp && j >= interval) && (++comp && a[j - interval] > x))
            {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = x;
        }
        interval = interval / 2;
    }
}

//// ALgorithm Heap Sort

//! Sift function(for time)
void Sift(int a[], int left, int right)
{
    int i = left - 1;
    int x = a[i];
    int j = 2 * i;
    while (j <= right - 1)
    {
        if (j < right)
        {
            if (a[j] < a[j + 1])
            {
                j++;
            }
        }
        if (x >= a[j])
        {
            break;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i;
    }
    a[i] = x;
}

//? Sift function(for comparision)
void Sift_comp(int a[], int left, int right, long long &comp)
{
    int i = left - 1;
    int x = a[i];
    int j = 2 * i;
    while (++comp && j <= right - 1)
    {
        if (++comp && j < right)
        {
            if (++comp && a[j] < a[j + 1])
            {
                j++;
            }
        }
        if (++comp && x >= a[j])
        {
            break;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i;
    }
    a[i] = x;
}
//! Heapify function(for time)
void Heapify(int a[], int n)
{
    int left = n / 2;
    while (left - 1 > 0)
    {
        Sift(a, left - 1, n);
        left--;
    }
}
//? Heapify function (for comparision)
void Heapify_comp(int a[], int n, long long &comp)
{
    int left = n / 2;
    while (left - 1 > 0)
    {
        Sift_comp(a, left - 1, n, comp);
        left--;
    }
}
//! Heapsort (for time)
void HeapSort(int *a, int n)
{
    Heapify(a, n);
    int right = n;
    while (right >= 1)
    {
        swap(a[0], a[right - 1]);
        right--;
        Sift(a, 1, right - 1);
    }
}
//? Heapsort (for comparision)
void HeapSort_comp(int *a, int n, long long &comp)
{
    Heapify_comp(a, n, comp);
    int right = n;
    while (right >= 1)
    {
        swap(a[0], a[right - 1]);
        right--;
        Sift_comp(a, 1, right - 1, comp);
    }
}

//// Algorithm Merge Sort

//! Merge function(for time)
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *a1 = new int[n1];
    int *a2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = a[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int n = left;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            a[n] = a1[i];
            i++;
        }
        else
        {
            a[n] = a2[j];
            j++;
        }
        n++;
    }
    while (i < n1)
    {
        a[n] = a1[i];
        i++;
        n++;
    }
    while (j < n2)
    {
        a[n] = a2[j];
        j++;
        n++;
    }
    delete[] a1;
    delete[] a2;
}

//? Merge function(for comparision)
void merge_comp(int a[], int left, int mid, int right, long long &comp)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *a1 = new int[n1];
    int *a2 = new int[n2];
    for (int i = 0; ++comp && i < n1; i++)
    {
        a1[i] = a[left + i];
    }
    for (int i = 0; ++comp && i < n2; i++)
    {
        a2[i] = a[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int n = left;
    while ((++comp && i < n1) && (++comp && j < n2))
    {
        if (++comp && a1[i] < a2[j])
        {
            a[n] = a1[i];
            i++;
        }
        else
        {
            a[n] = a2[j];
            j++;
        }
        n++;
    }
    while (++comp && i < n1)
    {
        a[n] = a1[i];
        i++;
        n++;
    }
    while (++comp && j < n2)
    {
        a[n] = a2[j];
        j++;
        n++;
    }
    delete[] a1;
    delete[] a2;
}
//! MergeSort(for time)
void MergeSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

//? MergeSort (for comparision)
void MergeSort_comp(int *a, int left, int right, long long &comp)
{
    if (++comp && left >= right)
        return;
    else
    {
        int mid = (left + right) / 2;
        MergeSort_comp(a, left, mid, comp);
        MergeSort_comp(a, mid + 1, right, comp);
        merge_comp(a, left, mid, right, comp);
    }
}

// Algorithm Quick Sort
//! Sort function(for time, using insertion sort algorithm)
void Sort(int *a, int left, int right)
{
    for (int i = left + 1; i < right; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= left && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
//? Sort function(for comparision, using insertion sort algorithm)
void Sort_comp(int *a, int left, int right, long long &comp)
{
    for (int i = left + 1; ++comp && i < right; i++)
    {
        int v = a[i];
        int j = i - 1;
        while ((++comp && j >= left) && (++comp && a[j] > v))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
////! Find median in a small array(for time)
//int findMedian(int *a, int left, int right)
//{
//    Sort(a, left, right);
//    return a[(left + right) / 2];
//}
////? Find median in a small array(for comparision)
//int findMedian_comp(int *a, int left, int right, long long &comp)
//{
//    Sort_comp(a, left, right, comp);
//    return a[(left + right) / 2];
//}
////! Find the kth smallest element in array(for time)
//int kthSmallest(int *a, int left, int right, int k)
//{
//    if (k > 0 && k <= right - left + 1)
//    {
//        int n = right - left + 1;
//        int i;
//        int *median = new int[(n + 4) / 5];
//        for (i = 0; i < n / 5; i++)
//        {
//            median[i] = findMedian(a, left + i * 5, left + i * 5 + 5);
//        }
//        if (i * 5 < n)
//        {
//            median[i] = findMedian(a, left + i * 5, left + i * 5 + n % 5);
//            i++;
//        }
//        int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);
//        int pos = Partition(a, left, right, medOfMed);
//        if (pos - left == k - 1)
//        {
//            return a[pos];
//        }
//        if (pos - left > k - 1)
//            return kthSmallest(a, left, pos - 1, k);
//        return kthSmallest(a, pos + 1, right, k - pos + left - 1);
//    }
//}
////? Find the kth smallest element in array(for comparision)
//int kthSmallest_comp(int *a, int left, int right, int k, long long &comp)
//{
//    if ((++comp && k > 0) && (++comp && k <= right - left + 1))
//    {
//        int n = right - left + 1;
//        int i;
//        int *median = new int[(n + 4) / 5];
//        for (i = 0; ++comp && i < n / 5; i++)
//        {
//            median[i] = findMedian_comp(a, left + i * 5, left + i * 5 + 5, comp);
//        }
//        if (++comp && i * 5 < n)
//        {
//            median[i] = findMedian_comp(a, left + i * 5, left + i * 5 + n % 5, comp);
//            i++;
//        }
//        int medOfMed = (++comp && i == 1) ? median[i - 1] : kthSmallest_comp(median, 0, i - 1, i / 2, comp);
//        int pos = Partition_comp(a, left, right, medOfMed, comp);
//        if (++comp && pos - left == k - 1)
//        {
//            return a[pos];
//        }
//        if (++comp && pos - left > k - 1)
//            return kthSmallest_comp(a, left, pos - 1, k, comp);
//        return kthSmallest_comp(a, pos + 1, right, k - pos + left - 1, comp);
//    }
//}

////! Partition (for time)
//int Partition(int a[], int left, int right, int x)
//{
//    int p = x;
//    int i = left;
//    int j = right;
//    int idx = 0;
//    for (int h = left; h < right; h++)
//    {
//        if (a[h] == p)
//        {
//            swap(a[h], a[left]);
//            break;
//        }
//    }
//    while (i < j)
//    {
//        do
//        {
//            i++;
//        } while (a[i] < p);
//        do
//            j--;
//        while (a[j] > p);
//        swap(a[i], a[j]);
//    }
//    swap(a[i], a[j]);
//    swap(a[left], a[j]);
//    return j;
//}
//? Partition (for comparision)
int Partition(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    if (a[mid] < a[left])
    {
        swap(a[left], a[mid]);
    }
    if (a[right] < a[left])
    {
        swap(a[left], a[right]);
    }
    if (a[mid] < a[right])
    {
        swap(a[mid], a[right]);
    }
    int p = a[right];
    int i = left-1;
    int j = right;
    do
    {
        do
            i++;
        while (a[i] < p);
        do
            j--;
        while (a[j] > p);
        swap(a[i], a[j]);
    } while (i < j);
    swap(a[i], a[j]);
    swap(a[right], a[i]);
    return i;
}
int Partition_comp(int a[], int left, int right, long long& comp)
{
    int mid = (left + right) / 2;
    if (++comp&&a[mid] < a[left])
    {
        swap(a[left], a[mid]);
    }
    if (++comp && a[right] < a[left])
    {
        swap(a[left], a[right]);
    }
    if (++comp && a[mid] < a[right])
    {
        swap(a[mid], a[right]);
    }
    int p = a[right];
    int i = left - 1;
    int j = right;
    do
    {
        do
            i++;
        while (++comp && a[i] < p);
        do
            j--;
        while (++comp && a[j] > p);
        swap(a[i], a[j]);
    } while (++comp && i < j);
    swap(a[i], a[j]);
    swap(a[right], a[i]);
    return i;
}
//! Quick sort (for time)
void QuickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int s = Partition(a, left, right);
        QuickSort(a, left, s - 1);
        QuickSort(a, s + 1, right);
    }
}
//! Quick Sort (for comparision)
void QuickSort_comp(int* a, int left, int right, long long& comp)
{
    if (left < right)
    {
        int s = Partition_comp(a, left, right,comp);
        QuickSort_comp(a, left, s - 1,comp);
        QuickSort_comp(a, s + 1, right,comp);
    }
}

//// Algorithm Counting Sort

//! Counting sort(for time)
void CountingSort(int *a, int n)
{
    int max = Max(a, n);
    const int RANGE = max;
    int *b = new int[n + 1];
    int *f = new int[RANGE + 1];
    memset(f, 0, (RANGE + 1) * 4);
    memset(b, 0, (n + 1) * 4);
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
    }
    for (int i = 1; i <= RANGE; i++)
    {
        f[i] = f[i - 1] + f[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[f[a[i]]--] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i + 1];
    }
    delete[] b;
    delete[] f;
}

//? Counting sort (for comparision)
void CountingSort_comp(int *a, int n, long long &comp)
{
    int max = Max(a, n);
    const int RANGE = max;
    int *b = new int[n + 1];
    int *f = new int[RANGE + 1];
    memset(f, 0, (RANGE + 1) * 4);
    memset(b, 0, (n + 1) * 4);
    for (int i = 0; ++comp && i < n; i++)
    {
        f[a[i]]++;
    }
    for (int i = 1; ++comp && i <= RANGE; i++)
    {
        f[i] = f[i - 1] + f[i];
    }
    for (int i = n - 1; ++comp && i >= 0; i--)
    {
        b[f[a[i]]--] = a[i];
    }
    for (int i = 0; ++comp && i < n; i++)
    {
        a[i] = b[i + 1];
    }
    delete[] b;
    delete[] f;
}

//// Algorithm Radix Sort

//! Get digit function(for time)
int digit(int n, int k)
{
    while (k > 1)
    {
        n = n / 10;
        k--;
    }
    return n % 10;
}

//? Get digit function(for comparision)
int digit_comp(int n, int k, long long &comp)
{
    while (++comp && k > 1)
    {
        n = n / 10;
        k--;
    }
    return n % 10;
}
//! Find max(for time)
int Max(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
//? Find max(for comparison)
int Max_comp(int *a, int n, long long &comp)
{
    int max = a[0];
    for (int i = 0; ++comp && i < n; i++)
    {
        if (++comp && a[i] > max)
            max = a[i];
    }
    return max;
}
//! digit sort function (for time)
void digitSort(int a[], int n, int k)
{
    int *b = new int[n];
    memset(b, 0, (n + 1) * 4);
    int f[10] = {0};
    for (int i = 0; i < n; i++)
    {
        f[digit(a[i], k)]++;
    }
    for (int i = 1; i <= 9; i++)
    {
        f[i] = f[i - 1] + f[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int j = (digit(a[i], k));
        b[--f[j]] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
//? digit sort function (for comparison)
void digitSort_comp(int a[], int n, int k, long long &comp)
{
    int *b = new int[n];
    memset(b, 0, (n + 1) * 4);
    int f[10] = {0};
    for (int i = 0; ++comp && i < n; i++)
    {
        f[digit(a[i], k)]++;
    }
    for (int i = 1; ++comp && i <= 9; i++)
    {
        f[i] = f[i - 1] + f[i];
    }
    for (int i = n - 1; ++comp && i >= 0; i--)
    {
        int j = (digit(a[i], k));
        b[--f[j]] = a[i];
    }
    for (int i = 0; ++comp && i < n; i++)
    {
        a[i] = b[i];
    }
}

//// Algorithm radix sort

//! Radix sort(for time)
void RadixSort(int *a, int n)
{
    int max = Max(a, n);
    int d = log10(max) + 1;
    for (int i = 1; i <= d; i++)
    {
        digitSort(a, n, i);
    }
}
//? Radix sort(for comparision)
void RadixSort_comp(int *a, int n, long long &comp)
{
    int max = Max_comp(a, n, comp);
    int d = log10(max) + 1;
    for (int i = 1; i <= d; i++)
    {
        digitSort_comp(a, n, i, comp);
    }
}

//// Algorithm Flash Sort

//! Flash Sort(for time)
void FlashSort(int *a, int n)
{
    long long m = (int)(0.45 * n);
    int *L = new int[m];

    for (int i = 0; i < m; i++)
    {
        L[i] = 0;
    }
    long long k;
    int min = a[0];
    int maxIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if (a[i] > a[maxIdx])
        {
            maxIdx = i;
        }
    }
    int max = a[maxIdx];
    if (a[maxIdx] == min)
        return;
    for (int i = 0; i < n; i++)
    {
        k = ((m - 1) * (a[i] - min)) / (max - min);
        L[k]++;
    }
    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }
    swap(a[maxIdx], a[0]);
    int i = 0;
    int x;
    int count = 0;
    k = m - 1;
    int t = 0;
    while (count < n - 1)
    {
        while (i > L[k] - 1)
        {
            i++;
            k = (m - 1) * (a[i] - min) / (max - min);
        }
        x = a[i];
        if (k < 0)
            break;
        while (i != L[k])
        {
            k = (m - 1) * (x - min) / (max - min);
            int temp = a[--L[k]];
            a[L[k]] = x;
            x = temp;
            count++;
        }
    }
    for (int k = 1; k < m; k++)
    {
        for (int i = L[k] - 1; i > L[k - 1] - 1; i--)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                int j = i;
                while (temp > a[j + 1])
                {
                    a[j] = a[j + 1];
                    j++;
                }
                a[j] = temp;
            }
        }
    }
    delete[] L;
}

//! Flash sort(for comparision)
void FlashSort_comp(int *a, int n, long long &comp)
{
    long long m = (int)(0.45 * n);
    int* L = new int[m];

    for (int i = 0; ++comp&&i < m; i++)
    {
        L[i] = 0;
    }
    long long k;
    int min = a[0];
    int maxIdx = 0;
    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[i] < min)
        {
            min = a[i];
        }
        else if (++comp && a[i] > a[maxIdx])
        {
            maxIdx = i;
        }
    }
    int max = a[maxIdx];
    if (++comp && a[maxIdx] == min)
        return;
    for (int i = 0; ++comp && i < n; i++)
    {
        k = ((m - 1) * (a[i] - min)) / (max - min);
        L[k]++;
    }
    for (int i = 1; ++comp && i < m; i++)
    {
        L[i] += L[i - 1];
    }
    swap(a[maxIdx], a[0]);
    int i = 0;
    int x;
    int count = 0;
    k = m - 1;
    int t = 0;
    while (++comp && count < n - 1)
    {
        while (++comp && i > L[k] - 1)
        {
            i++;
            k = (m - 1) * (a[i] - min) / (max - min);
        }
        x = a[i];
        if (++comp && k < 0)
            break;
        while (++comp && i != L[k])
        {
            k = (m - 1) * (x - min) / (max - min);
            int temp = a[--L[k]];
            a[L[k]] = x;
            x = temp;
            count++;
        }
    }
    for (int k = 1; ++comp && k < m; k++)
    {
        for (int i = L[k] - 1; ++comp && i > L[k - 1] - 1; i--)
        {
            if (++comp && a[i] > a[i + 1])
            {
                int temp = a[i];
                int j = i;
                while (++comp && temp > a[j + 1])
                {
                    a[j] = a[j + 1];
                    j++;
                }
                a[j] = temp;
            }
        }
    }
    delete[] L;
}