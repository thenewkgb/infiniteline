//
// command line - infinite line
//
// PC version
//
// removed depreciated functions

#include <iostream>
#include <vector>

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

void addDown(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

void addUp(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

//
// find the differences between each cell
//
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
    //int t = total(first, ans);
    put(ans, c, column + 2);
    std::cout << first << "," << second << "=" << ans << "\n";
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

void diagonalStepTwo(std::vector<std::vector<int>> &arrOriginal, std::vector<std::vector<int>> &arrNew)
{
    // column 5
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 5);
    // column 4
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 4);
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 5);
    // column 3
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 3);
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 4);
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 5);
    //column 2
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 2);
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 3);
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 4);
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 5);
    // column 1
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 1);
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 2);
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 3);
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 4);
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 5);
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
    diagonalStepTwo(arr, arrDiagDownRight);
    printgrid(arrDiagDownRight);
}