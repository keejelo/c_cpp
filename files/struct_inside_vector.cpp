//----------------------------------------------------------------------------------------------
// ** struct_inside_vector.cpp
//----------------------------------------------------------------------------------------------
// ** Example of how to use struct inside a vector. Great for lists with items and subitems etc.
//----------------------------------------------------------------------------------------------
#include <stdio.h>
#include <vector>

int main()
{
    //------------------------------------------------------------------------------------------
    // ** A struct that contains an integer array
    //------------------------------------------------------------------------------------------

    // ** Create struct of an integer array that holds 3 values
    struct Int3
    {
        int arr[3] = { 0 };
    };

    // ** Create a vector that holds the struct
    std::vector<Int3> vec;

    // ** Insert values into vector
    vec.push_back({ 8, 5, 6 });

    // ** Output values
    printf("%d\n", vec[0].arr[0]);
    printf("%d\n", vec[0].arr[1]);
    printf("%d\n\n", vec[0].arr[2]);

    // ..change them one by one
    vec[0].arr[0] = 9;
    vec[0].arr[1] = 4;
    vec[0].arr[2] = 7;

    // ** Output values
    printf("%d\n", vec[0].arr[0]);
    printf("%d\n", vec[0].arr[1]);
    printf("%d\n\n", vec[0].arr[2]);




    //------------------------------------------------------------------------------------------
    // ** A struct that contains several types
    //------------------------------------------------------------------------------------------

    // ** Create struct that holds two integers and a string (char array)
    struct MyItem
    {
        int n1 = 0;
        int n2 = 0;
        char s1[255] = { 0 };
    };

    // ** Create a vector that holds the struct
    std::vector<MyItem> vMyList;

    // ** Insert one "MyItem" with values and put it into vector
    vMyList.push_back({ 2, 5, "hello" });

    // ** Output values
    printf("%d, %d, %s\n", vMyList[0].n1, vMyList[0].n2, vMyList[0].s1);

    // ..change them one by one
    vMyList[0].n1 = 156;
    vMyList[0].n2 = 63;
    strcpy_s(vMyList[0].s1, "goodbye");

    // ** Output values
    printf("%d, %d, %s\n", vMyList[0].n1, vMyList[0].n2, vMyList[0].s1);

    // ** Pause before exit
    getchar();

    return 0;
};
