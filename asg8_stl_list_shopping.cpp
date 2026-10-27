#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

// Function to print all items in the list
void printList(const list<string>& shopping)
{
    for (auto it = shopping.begin(); it != shopping.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{
    // 1. Create an empty list
    list<string> shopping;

    // 2. Insert items at the end
    shopping.push_back("eggs");
    shopping.push_back("milk");
    shopping.push_back("sugar");
    shopping.push_back("chocolate");
    shopping.push_back("flour");

    cout << "Original list: ";
    printList(shopping);

    // 3. Remove the first element
    shopping.pop_front();

    cout << "After removing first item: ";
    printList(shopping);

    // 4. Insert coffee at the beginning
    shopping.push_front("coffee");

    cout << "After inserting coffee: ";
    printList(shopping);

    // 5. Replace sugar with honey
    replace(shopping.begin(), shopping.end(),
            "sugar", "honey");

    cout << "After replacing sugar: ";
    printList(shopping);

    // 6. Insert baking powder before milk
    auto it = find(shopping.begin(), shopping.end(), "milk");

    if (it != shopping.end())
    {
        shopping.insert(it, "baking powder");
    }

    cout << "After inserting baking powder: ";
    printList(shopping);

    // 7. Sort the list
    shopping.sort();

    cout << "Sorted list: ";
    printList(shopping);

    // 8. Search for an item entered by the user
    string item;

    cout << "Enter item to search: ";
    getline(cin, item);

    auto searchIt = find(shopping.begin(), shopping.end(), item);

    if (searchIt != shopping.end())
    {
        cout << "Item found: " << *searchIt << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }

    return 0;
}