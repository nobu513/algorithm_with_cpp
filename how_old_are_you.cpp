#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int get_index(vector<int> numbers, int num)
{
    // {1, 3, 5, 13, 15} then return 5.
    // {1, 3, 5, 13} then return 5.
    auto index = lower_bound(numbers.begin(), numbers.end(), num) - numbers.begin();

    return index;
}

void delete_range_by_answer(vector<int> &numbers, int index, string answer)
{
    // is there the function that allow us to reduce elements by id.
    //
    if (answer == "yes")
        numbers.erase(numbers.begin() + index, numbers.end());
    else
        numbers.erase(numbers.begin(), numbers.begin() + index);
}

int main()
{
    // 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
    vector<int> numbers(16);
    iota(numbers.begin(), numbers.end(), 20);

    cout << "start game!!" << endl;

    int select_num;
    string answer;

    for (int i = 0; i < 4; ++i)
    {
        // show current numbers;
        cout << "current numbers: " << endl;
        for (int num : numbers)
            cout << num << " ";
        cout << endl;

        // select number.
        cout << "select number ";
        cin >> select_num;
        cout << "Is the age less than " << select_num << " ? (yes / no) ";

        // input answer
        cin >> answer;
        delete_range_by_answer(numbers, get_index(numbers, select_num), answer);
    }

    // res
    cout << "You are " << numbers[0] << " years old." << endl;
}
