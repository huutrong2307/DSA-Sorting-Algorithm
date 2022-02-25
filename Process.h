#pragma once
#include "DataGenerator.h"
#include <chrono>

bool isDigit(const char *str);
chrono::milliseconds sort(int *a, int n, const char *sortType);
void getComp(int *a, int n, const char *sortType, long long&comp);
void copyArray(int *a, int n, int *b);
void outputCMD1(const char *sortType, const char *fileName, int size, chrono::milliseconds time, int comp, const char *out);
void outputCMD2(const char *sortType, int size, const char *dataType, chrono::milliseconds time, int comp, const char *out);
void outputCMD3(chrono::milliseconds time, int comp, const char *out);
void outputCMD4(const char *sortType1, const char *sortType2, const char *fileName, int size, chrono::milliseconds time1, chrono::milliseconds time2, int comp1, int comp2);
void outputCMD5(const char *sortType1, const char *sortType2, int size, const char *dataType, chrono::milliseconds time1, chrono::milliseconds time2, int comp1, int comp2);
void writeFile(const char* fileName, int* a, int n);
void readFile(const char* fileName, int*& a, int& n);