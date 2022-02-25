#include "Sort.h"
#include "DataGenerator.h"
#include "Process.h"

;
int main(int argc, char *argv[])

{
    if (argc == 5)
    {
        if (strcmp(argv[1], "-a") == 0 && !isDigit(argv[3])) // Command 1
        {
            int *array, *b;
            int n;
            readFile(argv[3], array, n);
            b = new int[n];
            copyArray(array, n, b);
            long long comp = 0;
            chrono::milliseconds time = sort(array, n, argv[2]);
            getComp(b, n, argv[2], comp);
            outputCMD1(argv[2], argv[3], n, time, comp, argv[4]);
            writeFile("output.txt", array, n);
            delete[] array;
            delete[] b;
        }
        else if (strcmp(argv[1], "-a") == 0 && isDigit(argv[3])) // Command 3
        {
            cout << "ALGORITHM MODE" << endl;
            int n = atoi(argv[3]);
            int *array = new int[n];
            int *b = new int[n];
            cout << "Algorithm: " << argv[2] << endl;
            cout << "Input size: " << argv[3] << endl
                 << endl;
            chrono::milliseconds time;
            long long comp = 0;
            for (int i = 0; i < 4; i++)
            {
                GenerateData(array, n, i);
                string fileName = "output";
                fileName += char(i + 1 + 48);
                fileName += ".txt";
                writeFile(fileName.c_str(), array, n);
                copyArray(array, n, b);
                time = sort(array, n, argv[2]);
                getComp(b, n, argv[2], comp);
                cout << "Input order: ";
                if (i == 0)
                {
                    cout << "Randomize" << endl;
                }
                else if (i == 1)
                {
                    cout << "Nearly Sorted" << endl;
                }
                else if (i == 2)
                {
                    cout << "Sorted" << endl;
                }
                else if (i == 3)
                {
                    cout << "Reversed" << endl;
                }
                outputCMD3(time, comp, argv[4]);
                cout << endl;
            }
            delete[] array;
            delete[] b;
        }

        else if (strcmp(argv[1], "-c") == 0) // Command 4
        {
            fstream f;
            f.open(argv[4], ios_base::in);
            int *arr1, *arr2;
            int *b1, *b2;
            int n;
            f >> n;
            arr1 = new int[n];
            arr2 = new int[n];
            b1 = new int[n];
            b2 = new int[n];
            copyArray(arr1, n, arr2);
            copyArray(arr1, n, b1);
            copyArray(arr2, n, b2);
            chrono::milliseconds time1, time2;
            long long comp1 = 0, comp2 = 0;
            time1 = sort(arr1, n, argv[2]);
            time2 = sort(arr2, n, argv[3]);
            getComp(b1, n, argv[2], comp1);
            getComp(b2, n, argv[3], comp2);
            outputCMD4(argv[2], argv[3], argv[4], n, time1, time2, comp1, comp2);
            delete[] arr1, arr2, b1, b2;
        }
    }
    else if (argc == 6)
    {
        if (strcmp(argv[1], "-a") == 0) // Command 2
        {
            int n = atoi(argv[3]);
            int *array = new int[n];
            int *b = new int[n];
            copyArray(array, n, b);
            GenerateData(array, n, dataType(argv[4]));
            writeFile("output.txt", array, n);
            chrono::milliseconds time;
            long long comp = 0;
            time = sort(array, n, argv[2]);
            getComp(array, n, argv[2], comp);
            outputCMD2(argv[2], n, argv[4], time, comp, argv[5]);
            writeFile("output.txt", array, n);
            delete[] array, b;
        }
        else if (strcmp(argv[1], "-c") == 0) // Command 5
        {
            int n = atoi(argv[4]);
            int *a1 = new int[n];
            int *a2 = new int[n];
            GenerateData(a1, n, dataType(argv[5]));
            writeFile("output.txt", a1, n);
            int *b1 = new int[n];
            int *b2 = new int[n];
            chrono::milliseconds time1, time2;
            long long comp1 = 0, comp2 = 0;
            time1 = sort(a1, n, argv[2]);
            time2 = sort(a2, n, argv[3]);
            getComp(a1, n, argv[2], comp1);
            getComp(a2, n, argv[2], comp2);
            outputCMD5(argv[2], argv[3], n, argv[5], time1, time2, comp1, comp2);
            delete[] a1, a2, b1, b2;
        }
    }
}
