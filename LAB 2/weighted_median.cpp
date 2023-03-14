#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void swap(int i, int j, vector<int> &a)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int parent(int ind)
{
    if (ind == 0)
        return 0;
    return (ind - 1) / 2;
}

int rchild(int ind)
{
    return 2 * ind + 2;
}

int lchild(int ind)
{
    return 2 * ind + 1;
}

void min_heap_down(int i, vector<int> &a)
{
    int l = lchild(i);
    int r = rchild(i);
    int smallest = i;
    if (l < a.size() && a[l] < a[i])
        smallest = l;
    if (r < a.size() && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(i, smallest, a);
        min_heap_down(smallest, a);
    }
}

void min_heap_up(int i, vector<int> &a)
{
    if (i > 0 && a[parent(i)] > a[i])
    {
        swap(i, parent(i), a);
        min_heap_up(parent(i), a);
    }
    else
        return;
}

void max_heap_down(int i, vector<int> &a)
{
    int l = lchild(i);
    int r = rchild(i);
    int largest = i;
    if (l < a.size() && a[l] > a[i])
        largest = l;
    if (r < a.size() && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(i, largest, a);
        max_heap_down(largest, a);
    }
}

void max_heap_up(int i, vector<int> &a)
{
    if (i > 0 && a[parent(i)] < a[i])
    {
        swap(i, parent(i), a);
        max_heap_up(parent(i), a);
    }
}

void remove_element(int i, vector<int> &a)
{
    for (int j = i; j < a.size() - 1; j++)
    {
        a[j] = a[j + 1];
    }
    a.pop_back();
}

int main()
{
    float t = 0;
    float smin = 0;
    float smax = 0;
    vector<int> minh;
    vector<int> maxh;
    map<int, float> weights;
    int n = 100;
    while (n-- >= 0)
    {
        cout << "1)Add" << endl
             << "2)Delete" << endl;
        int a;
        cin >> a;
        int x, w;
        switch (a)
        {
        case 1:

            cin >> x;

            cin >> w;
            t += w;
            weights[x] = w;
            if (minh.size() == 0 && maxh.size() == 0)
            {
                minh.push_back(x);
                smin += weights[x];
                min_heap_up(minh.size() - 1, minh);
            }
            else
            {
                if (x < minh[0])
                {
                    maxh.push_back(x);
                    smax += weights[x];
                    max_heap_up(maxh.size() - 1, maxh);
                }
                else
                {
                    minh.push_back(x);
                    smin += weights[x];
                    min_heap_up(minh.size() - 1, minh);
                }
            }

            while (smax / t <= 0.5 && minh.size() > 0)
            {
                if ((smax + weights[minh[0]]) / t < 0.5)
                {
                    smax += weights[minh[0]];
                    smin -= weights[minh[0]];
                    maxh.push_back(minh[0]);
                    max_heap_up(maxh.size() - 1, maxh);
                    // remove_element(0, minh);
                    minh.erase(minh.begin());
                    min_heap_down(0, minh);
                }
                else
                    break;
            }

            while (smax / t > 0.5 && maxh.size() > 0)
            {
                smax -= weights[maxh[0]];
                smin += weights[maxh[0]];
                minh.push_back(maxh[0]);
                min_heap_up(minh.size() - 1, minh);
                // remove_element(0, maxh);
                maxh.erase(maxh.begin());
                max_heap_down(0, maxh);
            }

            if (maxh.size() > 0)
                cout << "median is = " << maxh[0] << endl;
            else
                cout << "No median yet" << endl;

            break;

        case 2:

            cin >> x;
            if (x >= minh[0])
            {
                int ind = 0;
                for (int i = 0; i < minh.size(); i++)
                {
                    if (minh[i] == x)
                    {
                        ind = i;
                        break;
                    }
                }
                minh.erase(minh.begin() + ind);
            }
            // minh.erase(minh.find(x));

            else
            {
                int ind = 0;
                for (int i = 0; i < maxh.size(); i++)
                {
                    if (maxh[i] == x)
                    {
                        ind = i;
                        break;
                    }
                }
                maxh.erase(maxh.begin() + ind);
            }
            // maxh.erase(maxh.find(x));

            cout << "The Median is = " << maxh[0] << endl;
            break;
        }
    }
}