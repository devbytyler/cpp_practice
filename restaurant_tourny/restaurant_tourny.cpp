/*
TEST CASES
1.Ensure that a restuarant cannot get double added.
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 1
 
    Chipotle, Sizzler, Burger King, Panda Express, Taco Bell, McDonalds, Applebees, Red Robin
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 2
 
    Add Restaurant: Chipotle
    Already in the list. Not added.
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 1
 
    Chipotle, Sizzler, Burger King, Panda Express, Taco Bell, McDonalds, Applebees, Red Robin
 
2.Ensure that the tournamnet will not run if number of restaurnats is not a power of two.
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 2
 
    Add Restaurant: A
    Added.
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 5
 
    Please add or remove restaurants until amount is a power of 2. Current amount is: 9
 
3.Ensure that program will funtion properly for a list greater than 8
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 1
 
    Chipotle, Sizzler, Burger King, Panda Express, Taco Bell, McDonalds, Applebees, Red Robin, A, B, C, D, E, F, G, H
 
    1- Display all restaurants
    2- Add a restaurant
    3- Remove a restaurant
    4- Shuffle the vector
    5- Begin the tournament
    6- Quit the program
    Please select an option: 5
 
    Match 1\8 , Round 1\4 --- 1: Chipotle or 2: Sizzler? 1
    Match 2\8 , Round 1\4 --- 1: Burger King or 2: Panda Express? 2
    Match 3\8 , Round 1\4 --- 1: Taco Bell or 2: McDonalds? 1
    Match 4\8 , Round 1\4 --- 1: Applebees or 2: Red Robin? 2
    Match 5\8 , Round 1\4 --- 1: A or 2: B? 1
    Match 6\8 , Round 1\4 --- 1: C or 2: D? 2
    Match 7\8 , Round 1\4 --- 1: E or 2: F? 1
    Match 8\8 , Round 1\4 --- 1: G or 2: H? 2
    Match 1\4 , Round 2\4 --- 1: Chipotle or 2: Panda Express? 1
    Match 2\4 , Round 2\4 --- 1: Taco Bell or 2: Red Robin? 2
    Match 3\4 , Round 2\4 --- 1: A or 2: D? 1
    Match 4\4 , Round 2\4 --- 1: E or 2: H? 2
    Match 1\2 , Round 3\4 --- 1: Chipotle or 2: Red Robin? 1
    Match 2\2 , Round 3\4 --- 1: A or 2: H? 2
    Match 1\1 , Round 4\4 --- 1: Chipotle or 2: H? 1
    The winner is: Chipotle

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

void printMenu() //funtion prints out the menu to the user to be selected from.
{
    cout << "1- Display all restaurants" << endl
    << "2- Add a restaurant" << endl
    << "3- Remove a restaurant" << endl
    << "4- Shuffle the vector" << endl
    << "5- Begin the tournament" << endl
    << "6- Quit the program" << endl;
}

void addAllRestaurants(vector<string>& restaurants) //funtion intializes the vector to 8 standard restaurants.
{
    restaurants.push_back("Del Taco");
    restaurants.push_back("JCW's");
    restaurants.push_back("Village Baker");
    restaurants.push_back("Arby's");
    restaurants.push_back("Blaze Pizza");
    restaurants.push_back("Chipotle");
    restaurants.push_back("Subway");
    restaurants.push_back("Wendy's");
}

void showRestaurants(vector<string> restaurants) //function prints out the vector with comma separated strings
{
    for (int i = 0; i < restaurants.size(); i++)
    {
        cout << restaurants[i];
        if(i != restaurants.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

int find(vector<string> restaurants, string name) //funtion checks to see if the restuarnat entered by the user in already int he vector or not. Returns the index if it is found and returns -1 if not found.
{
    int NOT_FOUND = -1;
    for (int i = 0; i < restaurants.size(); i++)
    {
        if (restaurants[i] == name)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

void addRestaurant(vector<string>& restaurants) //function alows the user to add a restaurnat to the vector.
{
    const int NOT_FOUND = -1;
    
    cout << "Add Restaurant: ";
    string new_restaurant;
    cin.ignore(1000, '\n');
    getline(cin, new_restaurant);
    
    int index = 0;
    index = find(restaurants, new_restaurant);
    if (index == NOT_FOUND)
    {
        restaurants.push_back(new_restaurant);
        cout << "Added.\n";
    }
    else
        cout << "Already in the list. Not added.\n";
}
void removeRestaurant(vector<string>& restaurants) //function allows the user to remove a restaurant from the vector
{
    const int NOT_FOUND = -1;
    
    cout << "Remove Restaurant: ";
    string to_remove;
    cin.ignore(1000, '\n');
    getline(cin, to_remove);
    
    int index = 0;
    index = find(restaurants, to_remove);
    if (index == NOT_FOUND)
    {
        cout << "Not found. Not removed. \n";
    }
    else
    {
        restaurants.erase(restaurants.begin() + index);
        cout << "Found and removed. \n";
    }
    
}

void shuffle(vector<string>& restaurants) //function shuffles tha values of the vector at random
{
    const int largeNumber = 1000;
    for (int i = 0; i < largeNumber; i++)
    {
        int randNum1 = rand() % restaurants.size();
        int randNum2 = rand() % restaurants.size();
        
        string temp1 = restaurants[randNum1];
        string temp2 = restaurants[randNum2];
        
        restaurants[randNum1] = temp2;
        restaurants[randNum2] = temp1;
    }
}

bool ispowof2(int size) // funtion checks if the number of restaurants is a power of two by a bit-wise & function. returns 0 if it is and 1 if it is not.
{
    return ((size > 0) && ((size & (size - 1)) == 0));
}

bool battle(vector<string> restaurants) //function runs the tournament two restaurants at a time and outputs winner
{
    if (ispowof2(restaurants.size()))
    {
        int leftover = restaurants.size();
        
        int rounds = log2(restaurants.size());
        for (int round = 1; round <= rounds; round++)
        {
            int matches = leftover/ 2; //matches are half the amount of restaurnants
            for ( int match = 1; match <= matches; match++)
            {
                string input;
                while (!(input == "1" || input == "2"))
                {
                    cout << "Match " <<match<<"\\"<<matches<<" , ";
                    cout << "Round " <<round<<"\\"<<rounds << " --- 1: " << restaurants[match -1] << " or 2: "<< restaurants[match] <<"? ";
                
                    cin >> input;
                    if (input == "1" || input == "2")
                    {
                        if (input == "1")
                        {
                            restaurants.erase(restaurants.begin() + match);
                        }
                        if (input == "2")
                        {
                            restaurants.erase(restaurants.begin() + match - 1);
                        }
                    
                    }
                    else
                    {
                        cout << "Invalid input. (" << input << ")\n";
                    }
                }
                leftover--;
                
            }
            
        }
        cout <<"The winner is: " <<restaurants[0] << endl;
        return true;
        
    }
    else
        cout << "Please add or remove restaurants until amount is a power of 2. Current amount is: " << restaurants.size() <<endl;
    return false;
}



int main()
{
    srand(time(0));
    vector<string> restaurants;
    addAllRestaurants(restaurants);
    
    bool keep_going = true;
    while (keep_going == true)
    {
        int selection = 0;
        printMenu();
        cout << "Please select an option: ";
        cin >> selection;
        cout << endl;
        
        if (selection == 1)
        {
            showRestaurants(restaurants);
        }
        else if (selection == 2)
        {
            addRestaurant(restaurants);
        }
        else if (selection == 3)
        {
            removeRestaurant(restaurants);
        }
        else if (selection == 4)
        {
            shuffle(restaurants);
            cout << "Shuffled. \n";
        }
        else if (selection == 5)
        {
          keep_going = !battle(restaurants);
        }
        else if (selection == 6)
        {
            keep_going = false;
        }
        cout << endl;
        
    }
    cout << "Goodbye! \n";
    
    system("pause");
    return 0;
}