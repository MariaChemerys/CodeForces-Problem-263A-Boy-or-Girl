#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void define_gender(string n)
{
    int n_size = n.size();
    int* indexes_n = new int[n_size];
    //filling the array with indexes of the string elements
    for (int i = 0; i < n_size; i++)
    {
        indexes_n[i] = (int)n[i];
    }
    //sorting the array with indexes of the string elements
    sort(indexes_n, indexes_n + n_size);
    //creating an array with distinct characters
    int* dist_chars = new int[n_size];
    for (int i = 0, dist_chars_i = 0; i < n_size; i++)
    {
        if (i >= 1)
        {
            /*if the current element is the same as previous,
            we put zero to the array dist_chars instead of it, if not - we add
            it to the array*/
            if (indexes_n[i] == indexes_n[i - 1])
            {
                dist_chars[dist_chars_i] = 0;
                dist_chars_i++;
            }
            else
            {
                dist_chars[dist_chars_i] = indexes_n[i];
                dist_chars_i++;
            }
        }
        else
        {
            dist_chars[dist_chars_i] = indexes_n[i];
            dist_chars_i++;
        }
    }
    //counting zeros
    int zeros = 0;
    for (int i = 0; i < n_size; i++)
    {
        if (dist_chars[i] == 0)
        {
            zeros++;
        }
    }
    int dist_chars_cleaned_size = n_size - zeros;
    int* dist_chars_cleaned = new int[dist_chars_cleaned_size];

    if ((dist_chars_cleaned_size % 2) == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }
}

int main()
{
    string name;
    getline(cin, name);
    define_gender(name);
    return 0;
}