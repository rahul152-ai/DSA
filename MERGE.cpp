#include <iostream>
using namespace std;
void print(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }
}

void merge(int *array,int l,int m,int r)
{
    int j, i, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    for (int i = 0; i < nl; i++)
    {
        larr[i] = array[l + i];
    }
    for (int j = 0; j < nr; j++)
    {
        rarr[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;

    // merge temp array to real array
    while (l < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    { // extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { // extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array,int l,int r)
{
    int m;
    if (l < r)
    {
        m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
int main()
{
    int n;
    
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    mergeSort(array, 0, n - 1);
    print(array, n);

    return 0;
}