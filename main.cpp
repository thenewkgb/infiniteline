//
// command line - infinite line
//
//

#include <iostream>
#include <vector>

int get(std::vector<std::vector<int>> &arr, int x, int y)
{
    return arr[y][x];
}

int get(std::vector<int> vtr, int x)
{
    int result = vtr[x];
    return result;
}

void put(int result, std::vector<int> &vtr, int x)
{
    vtr[x] = result;
    return;
}

void put(int result, std::vector<std::vector<int>> &arr, int x, int y)
{
    arr[y][x] = result;
    return;
}

int sum(int a, int b)
{
    return a-b;
}

int total(int a, int b)
{
    return a+b;
}

void addright(std::vector<int> &vtr)
{
    // where is the middle?
    int coord1 = vtr.size() / 2;
    
    for (int j = coord1; j < vtr.size()-1; ++j)
    {
        int first = get(vtr, j);
        int second = get(vtr, j-1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, vtr, j+1);
    }
    return;
}

void addleft(std::vector<int> &vtr)
{
    int coord0 = vtr.size() / 2 - 1;
    
    for (int j = coord0; j > 0; --j)
    {
        int first = get(vtr, j);
        int second = get(vtr, j+1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, vtr, j-1);
    }
    return;
}

void adddown(std::vector<std::vector<int>> &arr, int column)
{
    int coord1 = arr.size()/2;
    
    for(int j = coord1; j < arr.size()-1; ++j)
    {
        int first = get(arr, column, j);
        int second = get(arr, column, j-1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, arr, column, j+1);
    }
    return;
}

void addup(std::vector<std::vector<int>> &arr, int column)
{
    int coord0 = arr.size()/2 - 1;
    
    for(int j = coord0 ; j > 0; --j)
    {
        int first = get(arr, column, j);
        int second = get(arr, column, j+1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, arr, column, j-1);
    }
    
    return;
}

void printline(const std::vector<int> &vtr)
{
    for (int element : vtr)
        std::cout << "\t" << element;
}

void printgrid(const std::vector<std::vector<int>> &arr)
{
    // each row
    for (int i = 0; i < arr.size(); ++i)
    {
        //print column
        printline(arr[i]);
        std::cout << "\n\n\n\n";
    }
}

int main(int argc, char *argv[])
{
    // good numbers
    // 0 4 2 8
    // 0 4 8 10
    std::cout << "Enter four sensible figures with spaces inbetween them: ";
    int w {0};
    int x {0};
    int y {0};
    int z {0};
    
    std::cin >> w >> x >> y >> z;
    
    std::vector<std::vector<int>> arr =
        {{0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, w, x, 0, 0, 0},
         {0, 0, 0, y, z, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}};

    // todo
    // make a user input vector
    // std::vector<std::vector<int>> arr2 = arr;

    // first pass
    addright(arr[3]);
    addright(arr[4]);;
    addleft(arr[3]);
    addleft(arr[4]);
    adddown(arr, 3);
    adddown(arr, 4);
    addup(arr, 3);
    addup(arr, 4);
    
    // second pass
    addright(arr[0]);
    addright(arr[1]);
    addright(arr[2]);
    addleft(arr[0]);
    addleft(arr[1]);
    addleft(arr[2]);
    addright(arr[5]);
    addright(arr[6]);
    addright(arr[7]);
    addleft(arr[5]);
    addleft(arr[6]);
    addleft(arr[7]);

    printgrid(arr);
}
