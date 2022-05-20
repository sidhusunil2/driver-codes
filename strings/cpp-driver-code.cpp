#include<bits/stdc++.h>

using namespace std;

      
// Function to find recycled pairs

int recycledPairs(int a[], int n)
{

    int count = 0;

      

    // Sorting array

    sort(a, a + n);

          

    // Removing duplicates by creating new array temp.

    int temp[n];

    memset(temp, -1, n);

    int j = 0;

          

    for (int i = 0; i < n - 1; i++)

        if (a[i] != a[i + 1])

            temp[j++] = a[i];

    temp[j++] = a[n - 1];

    int size = n;

          

    // Finding number of locations in temp 

    // which are occupied from copying.

    for (int i = n - 1; i >= 0; i--)

        if (temp[i] != -1) 

        {

            size = i;

            break;

        }

      

    // Hashset to store new Rotations

    set<int>hs;

      

    for (int i = 0; i < size + 1; i++) 

    {

          

        // Clearing hashset for each number in temp.

        hs.clear();

        int x = temp[i];

          

        // Finding number of digits of taken number

        int d1 = (int)log10(temp[i]) + 1;

  

        int f = (int)pow(10, d1 - 1);

        for (j = 1; j <= d1 - 1; j++) 

        {

              

            // Remainder

            int r = x % 10;

              

            // Quotient

            int q = x / 10;

                  

            // Forming new number by rotating.

            x = r * f + q;

              

            // Number of digits of newly formed rotated number

            // to avoid duplicate numbers.

            int d2 = (int)log10(x) + 1;

            set<int>::iterator it = hs.find(x);

                  

            // Inserting formed rotated number to set s

            if (it == hs.end()) 

            {

                hs.insert(x);

                  

                // Checking for number of digits of new number.

                if ((d1 == d2))

                { 

                          

                    // Searching for the formed element in rest of array.

                    int position = lower_bound(temp + i,

                                temp + size + 1 , x)-(temp + i + 1);

                      

                    // If position found

                    if(position >= 0)

                    {

                        // Increment counter.

                        count++;

                    }

                }

            }

        }

    }

  

    // Return counter

    return count;
}

  
// Driver function

int main()
{

    int a[] = { 32, 42, 13, 23, 9, 5, 31 };

    int n = sizeof(a)/sizeof(a[0]);

    int result = recycledPairs(a,n);

    cout << (result);

    return 0;  
}
