#include <iostream>
#include <vector>

void addright(std::vector<int> &vtr)
{
    int middle = vtr.size() / 2;
    int largest = vtr[middle];
    // difference between two
    int ans = vtr[middle] - vtr[middle - 1];
    //std::cout << vtr[size] << vtr[size-1];
    //std::cout << "\n";
    //std::cout << largest << "\n";

    int i = vtr.size() - vtr.size() / 2;
    for (int j = 1; j < i; ++j)
        vtr[middle + j] = largest + ans * j;
    return;
}

void addleft(std::vector<int> &vtr)
{
    int middle = vtr.size() / 2;
    int first = vtr[middle - 1];
    int second = vtr[middle];
    int ans = first - second;

    //std::cout << smallest << "\n";

    int i = vtr.size() - vtr.size() / 2;
    for (int j = 1; j < i; ++j)
    {
        vtr[middle - j - 1] = first + ans * j;
    }
    return;
}

void adddown(std::vector<std::vector<int>> &arr, int column)
{
    int verticlemiddle = arr.size()/2;
    int first = arr[verticlemiddle][column];
    int second = arr[verticlemiddle-1][column];
    int ans = first - second;
        
    int i = arr.size() - arr.size()/2;
    for(int j=1;j<i;++j)
        arr[verticlemiddle + j][column] = first + ans * j;
        return;
}

void addup(std::vector<std::vector<int>> &arr, int column)
{
    int verticlemiddle = arr.size()/2;
    int first = arr[verticlemiddle][column];
    int second = arr[verticlemiddle-1][column];
    int ans = second - first;
    
    int i = arr.size() - arr.size()/2;
    for(int j=1;j<i;++j)
        arr[verticlemiddle - j - 1][column] = second + ans * j;
}

void printline(const std::vector<int> &vtr)
{
    for (int element : vtr)
        std::cout << "\t" << element;
}

void printgrid(const std::vector<std::vector<int>> &arr)
{
    //left side
    for (int i = 0; i < arr.size(); ++i)
    {
        //whole row
        printline(arr[i]);
        std::cout << "\n\n\n\n";
    }
}

int main(int argc, char *argv[])
{
    // good numbers to enter
    // 4 2 8
    std::cout << "Enter three sensible figures with spaces inbetween them: ";
    int one {0};
    int two {0};
    int three {0};
    
    std::cin >> one >> two >> three;
    
    std::vector<std::vector<int>> arr =
        {{0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, one, 0, 0, 0},
         {0, 0, 0, two, three, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}};

    // make a user input vector
    // for later development 
    std::vector<std::vector<int>> arr2 = arr;

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
