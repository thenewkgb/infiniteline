//
// command line - infinite line
//
//

#include <iostream>
#include <vector>

// depreciated
/*
int get(std::vector<std::vector<int>> &arr, int x, int y)
{
    return arr[y][x];
}
*/

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

// depreciated
/*
void put(int result, std::vector<std::vector<int>> &arr, int x, int y)
{
    arr[y][x] = result;
    return;
}
*/

int sum(int a, int b)
{
    return a - b;
}

int total(int a, int b)
{
    return a + b;
}

void addright(std::vector<int> &vtr)
{
    // where is the middle?
    int coord1 = vtr.size() / 2;

    for (int j = coord1; j < vtr.size() - 1; ++j)
    {
        int first = get(vtr, j);
        int second = get(vtr, j - 1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, vtr, j + 1);
    }
    return;
}

void addleft(std::vector<int> &vtr)
{
    int coord0 = vtr.size() / 2 - 1;

    for (int j = coord0; j > 0; --j)
    {
        int first = get(vtr, j);
        int second = get(vtr, j + 1);
        int ans = sum(first, second);
        int t = total(first, ans);
        put(t, vtr, j - 1);
    }
    return;
}

// must not take 2D array
/*
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
*/

void addDown(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

// must not take 2D array
/*
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
*/

void addUp(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

// must not take 2D array
/*
void calcDiagonals(std::vector<std::vector<int>> &arr, int a, int b, int i)
{
    // recursion
    if(i > 0)
    {
        int first = get(arr, a, b);
        int second = get(arr, a-1, b-1);
        //std::cout << first << "," << second << "\n";
        int ans = sum(second, first);
        int t = total(second, ans);
        put(t, arr, a-1, b-1);
        calcDiagonals(arr, a-1, b-1, i-1);
    }
}
*/

// must not take 2D array
/*
 void diagonalBottom(std::vector<std::vector<int>> &arr)
{
    // 
    int size = arr.size();
    int sum2 = size - 2 - 1;
    
    for(int i = 0; i < sum2; ++i)
    {
        // - 1 as vectors start at 0
        int a = size - 1 - sum2 + i;
        int b = arr[0].size() - 1;
        
        int first = get(arr, a, b);
        int second = get(arr, a-1, b-1);
        std::cout << first << "," << second << ".";
        int ans = sum(second, first);
        int t = total(second, ans);
        put(t, arr, a-2, b-2);
        //calcDiagonals(arr, a-1, b-1, i);
    }
    
    // longest diagonal
    //calcDiagonals(arr, 7, 7, 6);
}
*/

// must not take 2D array
/*
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
*/

/*
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
*/
void addUpLeft(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column - 1);
    int second = get(b, column);
    int ans = sum(first, second);
    //int t = total(first, ans);
    std::cout << first << "," << second << "=" << ans << "\n"; 
    put(ans, c, column - 2);
}

void addDownRight(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column + 1);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column + 2);
    //std::cout << first << "," << second << "\n";
}

// initial steps to complete grid
void addStepOne(std::vector<std::vector<int>> &arr)
{
    addright(arr[3]);
    addright(arr[4]);
    addleft(arr[3]);
    addleft(arr[4]);
}

void addStepTwo(std::vector<std::vector<int>> &arr)
{
    addDown(arr[4], arr[3], arr[5], 3);
    addDown(arr[5], arr[4], arr[6], 3);
    addDown(arr[6], arr[5], arr[7], 3);

    addDown(arr[4], arr[3], arr[5], 4);
    addDown(arr[5], arr[4], arr[6], 4);
    addDown(arr[6], arr[5], arr[7], 4);

    addUp(arr[3], arr[4], arr[2], 3);
    addUp(arr[2], arr[3], arr[1], 3);
    addUp(arr[1], arr[2], arr[0], 3);

    addUp(arr[3], arr[4], arr[2], 4);
    addUp(arr[2], arr[3], arr[1], 4);
    addUp(arr[1], arr[2], arr[0], 4);
}

void addStepThree(std::vector<std::vector<int>> &arr)
{
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

// 
void diagonalStepOne(std::vector<std::vector<int>> &arrOriginal, std::vector<std::vector<int>> &arrNew)
{
    // don't alter values as this calculates each
    // cell in a particular order

    // column 3
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 2);
    // column 4
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 3);
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 2);
    // column 5
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 4);
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 3);
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 2);
    // column 6
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 5);
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 4);
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 3);
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 2);
    //column 7
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 6);
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 5);
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 4);
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 3);
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 2);
    // column 8
    addUpLeft(arrOriginal[6], arrOriginal[7], arrNew[5], 7);
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 6);
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 5);
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 4);
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 3);
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 2);
    // time to traverse upward
    addUpLeft(arrOriginal[5], arrOriginal[6], arrNew[4], 7);
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 6);
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 5);
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 4);
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 3);
    // next traverse
    addUpLeft(arrOriginal[4], arrOriginal[5], arrNew[3], 7);
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 6);
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 5);
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 4);
    // next traverse
    addUpLeft(arrOriginal[3], arrOriginal[4], arrNew[2], 7);
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 6);
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 5);
    // next traverse
    addUpLeft(arrOriginal[2], arrOriginal[3], arrNew[1], 7);
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 6);
    // last one
    addUpLeft(arrOriginal[1], arrOriginal[2], arrNew[0], 7);
}

void diagonalStepTwo(std::vector<std::vector<int>> &arr)
{
    // colum 5
    addDownRight(arr[1], arr[0], arr[2], 5);
    // column 4
    addDownRight(arr[1], arr[0], arr[2], 4);
    addDownRight(arr[2], arr[1], arr[3], 5);
    // column 3
    addDownRight(arr[1], arr[0], arr[2], 3);
    addDownRight(arr[2], arr[1], arr[3], 4);
    addDownRight(arr[3], arr[2], arr[4], 5);
    //column 2
    addDownRight(arr[1], arr[0], arr[2], 2);
    addDownRight(arr[2], arr[1], arr[3], 3);
    addDownRight(arr[3], arr[2], arr[4], 4);
    addDownRight(arr[4], arr[3], arr[5], 5);
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
    // 9 10 6 7 - circle?
    std::cout << "Enter four sensible figures with spaces inbetween them: ";
    int w{0};
    int x{0};
    int y{0};
    int z{0};

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

    std::vector<std::vector<int>> arrDiagUpLeft =
        {{0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}};

    // make copies for multidirection
    std::vector<std::vector<int>> arrDiagDownRight = arrDiagUpLeft;
    std::vector<std::vector<int>> arrDiagUpRight = arrDiagUpLeft;
    std::vector<std::vector<int>> arrDiagDownLeft = arrDiagUpLeft;

    // fill up grid first
    addStepOne(arr);
    addStepTwo(arr);
    addStepThree(arr);
    // print the first grid
    printgrid(arr);

    std::cout << "========= first pass ======="
              << "\n";

    diagonalStepOne(arr, arrDiagUpLeft);
    printgrid(arrDiagUpLeft);

    std::cout << "========= second pass ====="
              << "\n";
}