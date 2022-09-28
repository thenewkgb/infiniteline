//
// command line - infinite line
//
// mobile version
//
// diagonals OK and averaged
//
// adding OK and averaged
//
// OK for SDL
//
// although little debugging

#include <iostream>
#include <vector>

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

// the final array requires the average
// of four arrays
void putDivideFour(int sum, std::vector<std::vector<int>> &arr, int x, int y)
{
    arr[x][y] = sum/ 4;
}

//
// sums
//
int sum(int a, int b)
{
    return a - b;
}

int total(int a, int b)
{
    return a + b;
}

//
// initialising 
//
void initRight(std::vector<int> &vtr)
{
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

void initLeft(std::vector<int> &vtr)
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

void initDown(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

void initUp(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

// initial steps to complete first grid
void initStepOne(std::vector<std::vector<int>> &arr)
{
    initRight(arr[3]);
    initRight(arr[4]);
    initLeft(arr[3]);
    initLeft(arr[4]);
}

void initStepTwo(std::vector<std::vector<int>> &arr)
{
    initDown(arr[4], arr[3], arr[5], 3);
    initDown(arr[5], arr[4], arr[6], 3);
    initDown(arr[6], arr[5], arr[7], 3);

    initDown(arr[4], arr[3], arr[5], 4);
    initDown(arr[5], arr[4], arr[6], 4);
    initDown(arr[6], arr[5], arr[7], 4);

    initUp(arr[3], arr[4], arr[2], 3);
    initUp(arr[2], arr[3], arr[1], 3);
    initUp(arr[1], arr[2], arr[0], 3);

    initUp(arr[3], arr[4], arr[2], 4);
    initUp(arr[2], arr[3], arr[1], 4);
    initUp(arr[1], arr[2], arr[0], 4);
}

void initStepThree(std::vector<std::vector<int>> &arr)
{
    initRight(arr[0]);
    initRight(arr[1]);
    initRight(arr[2]);
    initLeft(arr[0]);
    initLeft(arr[1]);
    initLeft(arr[2]);

    initRight(arr[5]);
    initRight(arr[6]);
    initRight(arr[7]);
    initLeft(arr[5]);
    initLeft(arr[6]);
    initLeft(arr[7]);
}

void addUp(const std::vector<int> a, const std::vector<int> b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

void addDown(const std::vector<int> a, const std::vector<int> b, std::vector<int> &c, int column)
{
    int first = get(a, column);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column);
}

void addRight(const std::vector<int>a, int column, std::vector<int> &b)
{
    int first = get(a, column);
    int second = get(a, column - 1);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, b, column + 1);
}

void addLeft(const std::vector<int> a, int column, std::vector<int> &b)
{
    int first = get(a, column);
    int second = get(a, column + 1);
    int ans = sum(first, second);
    int t = total(first, ans);
    //std::cout << first << "," << second << std::endl;
    put(t, b, column - 1);
}

//
// diagonally
//
void addUpLeft(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column - 1);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    //std::cout << "upleft col " << column << first << "," << second << "tot " << t << "\n";
    put(t, c, column - 2);
}

void addDownRight(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column + 1);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column + 2);
    //std::cout << "downright col" << column << first << "," << second << "tot " << t << "\n";
}

void addUpRight(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column + 1);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    put(t, c, column + 2);
    //std::cout << "upright col" << column << first << "," << second << "tot " << t << "\n";
}

void addDownLeft(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, int column)
{
    int first = get(a, column - 1);
    int second = get(b, column);
    int ans = sum(first, second);
    int t = total(first, ans);
    //std::cout << "downleft col" << column << first << "," << second << "tot " << t << "\n";
    put(t, c, column - 2);
}

void diagonalsAverage(
        std::vector<std::vector<int>> const a,
        std::vector<std::vector<int>> const b,
        std::vector<std::vector<int>> const c,
        std::vector<std::vector<int>> const d,
        std::vector<std::vector<int>> &result)
{
    int sum = 0;
    
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[0].size(); ++j)
        {
            sum += a[i][j];
            sum += b[i][j];
            sum += c[i][j];
            sum += d[i][j];
            putDivideFour(sum, result, i, j);
            // reset for next square
            sum = 0;
        }
        //std::cout << "\n";
    }
}

void addingAverage(
     const std::vector<std::vector<int>> a,
     const std::vector<std::vector<int>> b,
     const std::vector<std::vector<int>> c,
     const std::vector<std::vector<int>> d,
      std::vector<std::vector<int>> &result
      )
{
    int sum = 0;
    
    for(int i = 0; i < a.size() ; ++i)
    {
        for(int j = 0; j < a[0].size(); ++j)
        {
            sum += a[i][j];
            sum += b[i][j];
            sum += c[i][j];
            sum += d[i][j];
            putDivideFour(sum, result, i, j);
            sum = 0;
        }
    }
}

void addStepOne(std::vector<std::vector<int>> const a, std::vector<std::vector<int>> &b)
{
    addRight(a[0], 1, b[0]);
    addRight(a[0], 2, b[0]);
    addRight(a[0], 3, b[0]);
    addRight(a[0], 4, b[0]);
    addRight(a[0], 5, b[0]);
    addRight(a[0], 6, b[0]);
    
    addRight(a[1], 1, b[1]);
    addRight(a[1], 2, b[1]);
    addRight(a[1], 3, b[1]);
    addRight(a[1], 4, b[1]);
    addRight(a[1], 5, b[1]);
    addRight(a[1], 6, b[1]);
    
    addRight(a[2], 1, b[2]);
    addRight(a[2], 2, b[2]);
    addRight(a[2], 3, b[2]);
    addRight(a[2], 4, b[2]);
    addRight(a[2], 5, b[2]);
    addRight(a[2], 6, b[2]);
    
    addRight(a[3], 1, b[3]);
    addRight(a[3], 2, b[3]);
    addRight(a[3], 3, b[3]);
    addRight(a[3], 4, b[3]);
    addRight(a[3], 5, b[3]);
    addRight(a[3], 6, b[3]);
    
    addRight(a[4], 1, b[4]);
    addRight(a[4], 2, b[4]);
    addRight(a[4], 3, b[4]);
    addRight(a[4], 4, b[4]);
    addRight(a[4], 5, b[4]);
    addRight(a[4], 6, b[4]);
    
    addRight(a[5], 1, b[5]);
    addRight(a[5], 2, b[5]);
    addRight(a[5], 3, b[5]);
    addRight(a[5], 4, b[5]);
    addRight(a[5], 5, b[5]);
    addRight(a[5], 6, b[5]);
    
    addRight(a[6], 1, b[6]);
    addRight(a[6], 2, b[6]);
    addRight(a[6], 3, b[6]);
    addRight(a[6], 4, b[6]);
    addRight(a[6], 5, b[6]);
    addRight(a[6], 6, b[6]);
    
    addRight(a[7], 1, b[7]);
    addRight(a[7], 2, b[7]);
    addRight(a[7], 3, b[7]);
    addRight(a[7], 4, b[7]);
    addRight(a[7], 5, b[7]);
    addRight(a[7], 6, b[7]);
}

void addStepTwo(const std::vector<std::vector<int>> a, std::vector<std::vector<int>> &b)
{
    addLeft(a[0], 6, b[0]);
    addLeft(a[0], 5, b[0]);
    addLeft(a[0], 4, b[0]);
    addLeft(a[0], 3, b[0]);
    addLeft(a[0], 2, b[0]);
    addLeft(a[0], 1, b[0]);
    
    addLeft(a[1], 6, b[1]);
    addLeft(a[1], 5, b[1]);
    addLeft(a[1], 4, b[1]);
    addLeft(a[1], 3, b[1]);
    addLeft(a[1], 2, b[1]);
    addLeft(a[1], 1, b[1]);
    
    addLeft(a[2], 6, b[2]);
    addLeft(a[2], 5, b[2]);
    addLeft(a[2], 4, b[2]);
    addLeft(a[2], 3, b[2]);
    addLeft(a[2], 2, b[2]);
    addLeft(a[2], 1, b[2]);
    
    addLeft(a[3], 6, b[3]);
    addLeft(a[3], 5, b[3]);
    addLeft(a[3], 4, b[3]);
    addLeft(a[3], 3, b[3]);
    addLeft(a[3], 2, b[3]);
    addLeft(a[3], 1, b[3]);
    
    
    addLeft(a[4], 6, b[4]);
    addLeft(a[4], 5, b[4]);
    addLeft(a[4], 4, b[4]);
    addLeft(a[4], 3, b[4]);
    addLeft(a[4], 2, b[4]);
    addLeft(a[4], 1, b[4]);
    
    addLeft(a[5], 6, b[5]);
    addLeft(a[5], 5, b[5]);
    addLeft(a[5], 4, b[5]);
    addLeft(a[5], 3, b[5]);
    addLeft(a[5], 2, b[5]);
    addLeft(a[5], 1, b[5]);
    
    addLeft(a[6], 6, b[6]);
    addLeft(a[6], 5, b[6]);
    addLeft(a[6], 4, b[6]);
    addLeft(a[6], 3, b[6]);
    addLeft(a[6], 2, b[6]);
    addLeft(a[6], 1, b[6]);
    
    addLeft(a[7], 6, b[7]);
    addLeft(a[7], 5, b[7]);
    addLeft(a[7], 4, b[7]);
    addLeft(a[7], 3, b[7]);
    addLeft(a[7], 2, b[7]);
    addLeft(a[7], 1, b[7]);
}

void addStepThree(const std::vector<std::vector<int>> a, std::vector<std::vector<int>> &b)
{
    // column 0
    addUp(a[6], a[7], b[5], 0);
    addUp(a[5], a[6], b[4], 0);
    addUp(a[4], a[5], b[3], 0);
    addUp(a[3], a[4], b[2], 0);
    addUp(a[2], a[3], b[1], 0);
    addUp(a[1], a[2], b[0], 0);
    // column 1
    addUp(a[6], a[7], b[5], 1);
    addUp(a[5], a[6], b[4], 1);
    addUp(a[4], a[5], b[3], 1);
    addUp(a[3], a[4], b[2], 1);
    addUp(a[2], a[3], b[1], 1);
    addUp(a[1], a[2], b[0], 1);
    // column 2
    addUp(a[6], a[7], b[5], 2);
    addUp(a[5], a[6], b[4], 2);
    addUp(a[4], a[5], b[3], 2);
    addUp(a[3], a[4], b[2], 2);
    addUp(a[2], a[3], b[1], 2);
    addUp(a[1], a[2], b[0], 2);
    // column 3
    addUp(a[6], a[7], b[5], 3);
    addUp(a[5], a[6], b[4], 3);
    addUp(a[4], a[5], b[3], 3);
    addUp(a[3], a[4], b[2], 3);
    addUp(a[2], a[3], b[1], 3);
    addUp(a[1], a[2], b[0], 3);
    // column 4
    addUp(a[6], a[7], b[5], 4);
    addUp(a[5], a[6], b[4], 4);
    addUp(a[4], a[5], b[3], 4);
    addUp(a[3], a[4], b[2], 4);
    addUp(a[2], a[3], b[1], 4);
    addUp(a[1], a[2], b[0], 4);
    // column 5
    addUp(a[6], a[7], b[5], 5);
    addUp(a[5], a[6], b[4], 5);
    addUp(a[4], a[5], b[3], 5);
    addUp(a[3], a[4], b[2], 5);
    addUp(a[2], a[3], b[1], 5);
    addUp(a[1], a[2], b[0], 5);
    // column 6
    addUp(a[6], a[7], b[5], 6);
    addUp(a[5], a[6], b[4], 6);
    addUp(a[4], a[5], b[3], 6);
    addUp(a[3], a[4], b[2], 6);
    addUp(a[2], a[3], b[1], 6);
    addUp(a[1], a[2], b[0], 6);
    // column 7
    addUp(a[6], a[7], b[5], 7);
    addUp(a[5], a[6], b[4], 7);
    addUp(a[4], a[5], b[3], 7);
    addUp(a[3], a[4], b[2], 7);
    addUp(a[2], a[3], b[1], 7);
    addUp(a[1], a[2], b[0], 7);
}

void addStepFour(const std::vector<std::vector<int>> a, std::vector<std::vector<int>> &b)
{
    // column 1
    addDown(a[1], a[0], b[2], 0);
    addDown(a[2], a[1], b[3], 0);
    addDown(a[3], a[2], b[4], 0);
    addDown(a[4], a[3], b[5], 0);
    addDown(a[5], a[4], b[6], 0);
    addDown(a[6], a[5], b[7], 0);
    // column 2
    addDown(a[1], a[0], b[2], 1);
    addDown(a[2], a[1], b[3], 1);
    addDown(a[3], a[2], b[4], 1);
    addDown(a[4], a[3], b[5], 1);
    addDown(a[5], a[4], b[6], 1);
    addDown(a[6], a[5], b[7], 1);
    // column 2
    addDown(a[1], a[0], b[2], 2);
    addDown(a[2], a[1], b[3], 2);
    addDown(a[3], a[2], b[4], 2);
    addDown(a[4], a[3], b[5], 2);
    addDown(a[5], a[4], b[6], 2);
    addDown(a[6], a[5], b[7], 2);
    // column 3
    addDown(a[1], a[0], b[2], 3);
    addDown(a[2], a[1], b[3], 3);
    addDown(a[3], a[2], b[4], 3);
    addDown(a[4], a[3], b[5], 3);
    addDown(a[5], a[4], b[6], 3);
    addDown(a[6], a[5], b[7], 3);
    // column 4
    addDown(a[1], a[0], b[2], 4);
    addDown(a[2], a[1], b[3], 4);
    addDown(a[3], a[2], b[4], 4);
    addDown(a[4], a[3], b[5], 4);
    addDown(a[5], a[4], b[6], 4);
    addDown(a[6], a[5], b[7], 4);
    // column 5
    addDown(a[1], a[0], b[2], 5);
    addDown(a[2], a[1], b[3], 5);
    addDown(a[3], a[2], b[4], 5);
    addDown(a[4], a[3], b[5], 5);
    addDown(a[5], a[4], b[6], 5);
    addDown(a[6], a[5], b[7], 5);
    // column 6
    addDown(a[1], a[0], b[2], 6);
    addDown(a[2], a[1], b[3], 6);
    addDown(a[3], a[2], b[4], 6);
    addDown(a[4], a[3], b[5], 6);
    addDown(a[5], a[4], b[6], 6);
    addDown(a[6], a[5], b[7], 6);
    // column 7
    addDown(a[1], a[0], b[2], 7);
    addDown(a[2], a[1], b[3], 7);
    addDown(a[3], a[2], b[4], 7);
    addDown(a[4], a[3], b[5], 7);
    addDown(a[5], a[4], b[6], 7);
    addDown(a[6], a[5], b[7], 7);
}

// don't alter values as this calculates each
// cell in a particular order
void diagonalStepOne(std::vector<std::vector<int>> &arrOriginal, std::vector<std::vector<int>> &arrNew)
{
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
    // column 0
    addDownRight(arrOriginal[1], arrOriginal[0], arrNew[2], 0);
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 1);
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 2);
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 3);
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 4);
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 5);
    // traverse downwards
    addDownRight(arrOriginal[2], arrOriginal[1], arrNew[3], 0);
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 1);
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 2);
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 3);
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 4);
    // traverse
    addDownRight(arrOriginal[3], arrOriginal[2], arrNew[4], 0);
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 1);
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 2);
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 3);
    // traverse
    addDownRight(arrOriginal[4], arrOriginal[3], arrNew[5], 0);
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 1);
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 2);
    // traverse
    addDownRight(arrOriginal[5], arrOriginal[4], arrNew[6], 0);
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 1);
    // traverse
    addDownRight(arrOriginal[6], arrOriginal[5], arrNew[7], 0);
}

void diagonalStepThree(std::vector<std::vector<int>> &arrOriginal, std::vector<std::vector<int>> &arrNew)
{
    // row 1
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 0);
    // row 2
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 0);
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 1);
    // row 3
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 0);
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 1);
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 2);
    // row 4
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 0);
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 1);
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 2);
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 3);
    // row 5
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 0);
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 1);
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 2);
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 3);
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 4);
    // row 6
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 0);
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 1);
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 2);
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 3);
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 4);
    addUpRight(arrOriginal[1], arrOriginal[2], arrNew[0], 5);
    // traverse right
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 1);
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 2);
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 3);
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 4);
    addUpRight(arrOriginal[2], arrOriginal[3], arrNew[1], 5);
    // traverse right
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 2);
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 3);
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 4);
    addUpRight(arrOriginal[3], arrOriginal[4], arrNew[2], 5);
    // traverse right
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 3);
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 4);
    addUpRight(arrOriginal[4], arrOriginal[5], arrNew[3], 5);
    // traverse right
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 4);
    addUpRight(arrOriginal[5], arrOriginal[6], arrNew[4], 5);
    // traverse right
    addUpRight(arrOriginal[6], arrOriginal[7], arrNew[5], 5);
}

void diagonalStepFour(std::vector<std::vector<int>> &arrOriginal, std::vector<std::vector<int>> &arrNew)
{
    // row 2
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 2);
    // row 3
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 3);
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 2);
    // row 4
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 4);
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 3);
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 2);
    // row 5
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 5);
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 4);
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 3);
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 2);
    // row 6
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 6);
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 5);
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 4);
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 3);
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 2);
    // row 7
    addDownLeft(arrOriginal[1], arrOriginal[0], arrNew[2], 7);
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 6);
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 5);
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 4);
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 3);
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 2);
    // traverse down
    addDownLeft(arrOriginal[2], arrOriginal[1], arrNew[3], 7);
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 6);
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 5);
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 4);
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 3);
    // traverse down
    addDownLeft(arrOriginal[3], arrOriginal[2], arrNew[4], 7);
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 6);
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 5);
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 4);
    // traverse down
    addDownLeft(arrOriginal[4], arrOriginal[3], arrNew[5], 7);
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 6);
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 5);
    // traverse down
    addDownLeft(arrOriginal[5], arrOriginal[4], arrNew[6], 7);
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 6);
    // traverse down
    addDownLeft(arrOriginal[6], arrOriginal[5], arrNew[7], 7);
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
    std::cout << "Enter four sensible figures with spaces inbetween them: ";
    int w{0};
    int x{3};
    int y{5};
    int z{7};

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
         
     std::vector<std::vector<int>> arrEmpty =
        {{0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}};
         
     std::vector<std::vector<int>> arrReady = arr;

    // make copies for diagonal addition
    std::vector<std::vector<int>> arrDiagUpLeft = arrEmpty;
    std::vector<std::vector<int>> arrDiagDownRight = arrEmpty;
    std::vector<std::vector<int>> arrDiagUpRight = arrEmpty;
    std::vector<std::vector<int>> arrDiagDownLeft = arrEmpty;
    
    // final diagonal average
    std::vector<std::vector<int>> arrDiagFinal = arrEmpty;
    
    // some vectors for bringing addition
    // together
    std::vector<std::vector<int>> arrAddedLeft = arrEmpty;
    std::vector<std::vector<int>> arrAddedRight = arrEmpty;
    std::vector<std::vector<int>> arrAddedUp = arrEmpty;
    std::vector<std::vector<int>> arrAddedDown = arrEmpty;
    std::vector<std::vector<int>> arrAddedAvg = arrEmpty;
    
    //
    // how to start the grid off
    //
    
    // have a backup grid
    initStepOne(arr);
    initStepTwo(arr);
    initStepThree(arr);

    // fill up grid which will serve us in future
    initStepOne(arrReady);
    initStepTwo(arrReady);
    initStepThree(arrReady);
    
    std::cout << "===== init =====" << "\n";
    printgrid(arrReady);

    //
    // start the cycle
    //
    
    // read from arrReady and place into arrDiag
    diagonalStepOne(arrReady, arrDiagUpLeft);
    diagonalStepTwo(arrReady, arrDiagDownRight);
    diagonalStepThree(arrReady, arrDiagUpRight);
    diagonalStepFour(arrReady, arrDiagDownLeft);
    
    //std::cout << "======== diag averages =======" << "\n";

    // sum up each diagonal and
    // average them out
    // write average to arrFinal
    diagonalsAverage(
        arrDiagUpLeft,
        arrDiagDownRight,
        arrDiagUpRight,
        arrDiagDownLeft,
        arrDiagFinal);

    // do we need arrReady
    // to receive new input each time?
    arrReady = arrEmpty;

    
    std::cout << "===== stage complete =====" << "\n";
    // read from Final to Ready
    addStepOne(arrDiagFinal, arrAddedRight);
    addStepTwo(arrDiagFinal, arrAddedLeft);
    addStepThree(arrDiagFinal, arrAddedUp);
    addStepFour(arrDiagFinal, arrAddedDown);
    
    // take all four added and average them
    addingAverage(arrAddedLeft, arrAddedRight, arrAddedUp, arrAddedDown, arrAddedAvg);
    
    //
    // now we have our new array
    // which will be ready
    // for diagonal addition again
    //
}
