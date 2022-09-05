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

// add on top of previous square
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

void calcDiagonals(std::vector<std::vector<int>> &arr, int a, int b, int i)
{
    if(i > 0)
    {
        int first = get(arr, a, b);
        int second = get(arr, a-1, b-1);
        //std::cout << first << "," << second << "\n";
        int ans = sum(second, first);
        int t = total(second, ans);
        put(t, arr, a-2, b-2);
        calcDiagonals(arr, a-1, b-1, i-1);
    }
   // std::cout << "\n";
    return;
}

void diagonalBottom(std::vector<std::vector<int>> &arr)
{
    // include longest diagonal
    // top right, bottom left
    int size = arr.size();
    int sum2 = size - 2 -1;
    
    for(int i = 0; i < sum2; ++i)
    {
        // - 1 for vector[0]
        int a = size - 1 - sum2 + i;
        // -1 for vector[0]
        int b = arr[0].size() - 1;
        int first = get(arr, a, b);
        int second = get(arr, a-1, b-1);
        //std::cout << first << "," << second << ".";
        int ans = sum(second, first);
        int t = total(second, ans);
        put(t, arr, a-2, b-2);
        calcDiagonals(arr, a-1, b-1, i);
    }
    
    // longest diagonal
    calcDiagonals(arr, 7, 7, 6);
}

void diagonalTop(std::vector<std::vector<int>> &arr)
{
    int size = arr.size();
    int sum2 = size - 2 - 1;
    
    for(int i = 0; i < sum2; ++i)
    {
        // - 1 for vector[0]
        int b = size - 1 - sum2 + i;
        // -1 for vector[0]
        int a = arr[0].size() - 1;
        int first = get(arr, a, b);
        int second = get(arr, a-1, b-1);
        //std::cout << first << "," << second << ".";
        int ans = sum(second, first);
        int t = total(second, ans);
        put(t, arr, a-2, b-2);
        calcDiagonals(arr, a-1, b-1, i);
    }
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

void initGridHorz(std::vector<std::vector<int>> &arr)
{
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
}

int main(int argc, char *argv[])
{
    // good numbers
    // 0 4 2 8
    // 0 4 8 10
    // 9 10 6 7 - circle?
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

    // fill the grid to begin with
    initGridHorz(arr);
    printgrid(arr);

    std::vector<std::vector<int>> arr2 = arr;

    std::cout << "==========" << "\n";
    diagonalBottom(arr2);
    diagonalTop(arr2);
    printgrid(arr2);

    std::vector<std::vector<int>> arr3 = arr2;
    std::cout << "==========" << "\n";

    initGridHorz(arr3);
    //diagonalBottom(arr3);
    //diagonalTop(arr3);
    printgrid(arr3);
}