#pragma once
#include <iostream>
;
using namespace std;

void SelectionSort(int *a, int n);
void SelectionSort_comp(int *a, int n, long long &comp);

void InsertionSort(int *a, int n);
void InsertionSort_comp(int *a, int n, long long&comp);

void BubbleSort(int *a, int n);
void BubbleSort_comp(int *a, int n, long long&comp);

void ShakerSort(int *a, int n);
void ShakerSort_comp(int *a, int n, long long&comp);

void ShellSort(int *a, int n);
void ShellSort_comp(int *a, int n, long long&comp);

void Sift(int a[], int left, int right);
void Sift_comp(int a[], int left, int right, long long&comp);
void Heapify(int a[], int n);
void Heapify_comp(int a[], int n, long long&comp);
void HeapSort(int *a, int n);
void HeapSort_comp(int *a, int n, long long&comp);

void merge(int a[], int left, int mid, int right);
void merge_comp(int a[], int left, int mid, int right, long long&comp);
void MergeSort(int *a, int left, int right);
void MergeSort_comp(int *a, int left, int right, long long&comp);

void Sort(int *a, int left, int right);
void Sort_comp(int *a, int left, int right, long long&comp);

int Partition(int a[], int left, int right);
int Partition_comp(int a[], int left, int right, long long& comp);
void QuickSort(int *a, int left, int right);
void QuickSort_comp(int* a, int left, int right,long long& comp);

void CountingSort(int *a, int n);
void CountingSort_comp(int *a, int n, long long&comp);

int digit(int n, int k);
int digit_comp(int n, int k, long long&comp);
void digitSort(int a[], int n, int k);
void digitSort_comp(int a[], int n, int k, long long&comp);
void RadixSort(int *a, int n);
void RadixSort_comp(int *a, int n, long long&comp);

void FlashSort(int *a, int n);
void FlashSort_comp(int *a, int n, long long&comp);

int Max(int *a, int n);
int Max_comp(int *a, int n, long long&comp);
