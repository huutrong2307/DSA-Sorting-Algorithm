
#include "Process.h"
#include "Sort.h"

bool isDigit(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}
//
void copyArray(int *a, int n, int *b)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
//!
chrono::milliseconds sort(int *a, int n, const char *sortType)
{
    if (strcmp(sortType, "selection-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        SelectionSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "insertion-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "bubble-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        BubbleSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "shaker-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        ShakerSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "shell-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        ShellSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "heap-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        HeapSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "merge-sort") == 0)
    {

        auto start = chrono::high_resolution_clock::now();
        MergeSort(a, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "quick-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        QuickSort(a, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "counting-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        CountingSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "radix-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        RadixSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
    else if (strcmp(sortType, "flash-sort") == 0)
    {
        auto start = chrono::high_resolution_clock::now();
        FlashSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto usedTime = chrono::duration_cast<chrono::milliseconds>(end - start);
        return usedTime;
    }
}
//!
void getComp(int *a, int n, const char *sortType, long long &comp)
{
    if (strcmp(sortType, "selection-sort") == 0)
    {
        SelectionSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "insertion-sort") == 0)
    {
        InsertionSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "bubble-sort") == 0)
    {
        BubbleSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "shaker-sort") == 0)
    {
        ShakerSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "shell-sort") == 0)
    {
        ShellSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "heap-sort") == 0)
    {
        HeapSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "merge-sort") == 0)
    {
        MergeSort_comp(a, 0, n - 1, comp);
    }
   /* else if (strcmp(sortType, "quick-sort") == 0)
    {
        QuickSort_comp(a, 0, n - 1, comp);
    }*/
    else if (strcmp(sortType, "counting-sort") == 0)
    {
        CountingSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "radix-sort") == 0)
    {
        RadixSort_comp(a, n, comp);
    }
    else if (strcmp(sortType, "flash-sort") == 0)
    {
        FlashSort_comp(a, n, comp);
    }
}
//!
void outputCMD1(const char *sortType, const char *fileName, int size, chrono::milliseconds time, int comp, const char *out)
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << sortType << endl;
    cout << "Input file: " << fileName << endl;
    cout << "Input size: " << size << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Running time (if required): ";
    if (strcmp(out, "-time") == 0 || strcmp(out, "-both") == 0)
        cout << time.count() << " ms";
    cout << endl;
    cout << "Comparisions (if required): ";
    if (strcmp(out, "-comp") == 0 || strcmp(out, "-both") == 0)
        cout << comp;
    cout << endl;
}
void outputCMD2(const char *sortType, int size, const char *dataType, chrono::milliseconds time, int comp, const char *out)
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << sortType << endl;
    cout << "Input size: " << size << endl;
    cout << "Input order: ";
    if (strcmp(dataType, "-rand") == 0) {
        cout << "Randomized" << endl;
    }
    else if (strcmp(dataType, "-nsorted") == 0) {
        cout << "Nearly sorted" << endl;
    }
    else if (strcmp(dataType, "-sorted") == 0) {
        cout << "Sorted" << endl;
    }
    else if (strcmp(dataType, "-rev") == 0) {
        cout << "Reverse" << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Running time (if required): ";
    if (strcmp(out, "-time") == 0 || strcmp(out, "-both") == 0)
        cout << time.count() << " ms";
    cout << endl;
    cout << "Comparisions (if required): ";
    if (strcmp(out, "-comp") == 0 || strcmp(out, "-both") == 0)
        cout << comp;
    cout << endl;
}
void outputCMD3(chrono::milliseconds time, int comp, const char *out)
{
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Running time (if required): ";
    if (strcmp(out, "-time") == 0 || strcmp(out, "-both") == 0)
        cout << time.count() << " ms";
    cout << endl;
    cout << "Comparisions (if required): ";
    if (strcmp(out, "-comp") == 0 || strcmp(out, "-both") == 0)
        cout << comp;
    cout << endl;
}
void outputCMD4(const char *sortType1, const char *sortType2, const char *fileName, int size, chrono::milliseconds time1, chrono::milliseconds time2, int comp1, int comp2)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << sortType1 << " | " << sortType2 << endl;
    cout << "Input file:" << fileName << endl;
    cout << "Input size: " << size << endl;
    cout << "- - - - - - - - - - - - - - - -- - - - - - - - " << endl;
    cout << "Running time(if required): " << time1.count() << " ms"
         << " | " << time2.count() << " ms" << endl;
    cout << "Comparisions(if required): " << comp1 << " | " << comp2 << endl;
}
void outputCMD5(const char *sortType1, const char *sortType2, int size, const char *dataType, chrono::milliseconds time1, chrono::milliseconds time2, int comp1, int comp2)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << sortType1 << " | " << sortType2 << endl;
    cout << "Input size: " << size << endl;
    cout << "Input order: ";
    if (strcmp(dataType, "-rand") == 0) {
        cout << "Randomized" << endl;
    }
    else if (strcmp(dataType, "-nsorted") == 0) {
        cout << "Nearly sorted" << endl;
    }
    else if (strcmp(dataType, "-sorted") == 0) {
        cout << "Sorted" << endl;
    }
    else if (strcmp(dataType, "-rev") == 0) {
        cout << "Reverse" << endl;
    }
    cout << "- - - - - - - - - - - - - - - -- - - - - - - - " << endl;
    cout << "Running time(if required): " << time1.count() << " ms"
         << " | " << time2.count() << " ms" << endl;
    cout << "Comparisions(if required): " << comp1 << " | " << comp2 << endl;
}
void writeFile(const char* fileName, int* a, int n) {
    fstream f;
    f.open(fileName, ios_base::out);
    f << n << endl;
    for (int i = 0; i < n; i++) {
        f << a[i] << " ";
    }
    f.close();
}
void readFile(const char* fileName, int*& a, int& n) {
    fstream f;
    f.open(fileName, ios_base::in);
    f >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        f >> a[i];
    }
    f.close();
}