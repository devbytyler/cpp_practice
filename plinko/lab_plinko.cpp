/*
1. To make sure bad values are never accepted:
  MENU: a = bad input return to menu
  MENU: -1 = bad input return to menu
  MENU: 6 = bad input retrun to menu

    Option 1:
    start slot -1 = bad input retrun to menu
    start slot r = bad input retrun to menu
    start slot 9 = bad input retrun to menu

    Option 2:
    number of chips -2 = bad input retrun to menu
    number of chips d = bad input retrun to menu
    start slot t = bad input retrun to menu
    start slot -1 = bad input retrun to menu
    start slot 10 = bad input retrun to menu

    Option 3:
    number of chips -5 = bad input retrun to menu
    number of ship q = bad input retrun to menu

2. ensure that option 1 is correctly formatted and get the correct winnings and never fall ofd the board
(for slots 5, 0, and 8)
  MENU: Please enter a option:
  1) Drop a single chip into the one slot
  2) Drop multiple chips into one slot
  3) Drop multiple chips into all slots
  4) Quit the program
  Enter your selection now: 1

  *** Drop SINGLE Chip ***
  Starting slot (0-8): 5
  Path: [5.0 5.5 6.0 5.5 5.0 5.5 5.0 4.5 4.0 3.5 3.0 3.5 4.0]
  Winnings: $10000.00

  MENU: Please enter a option:
  1) Drop a single chip into the one slot
  2) Drop multiple chips into one slot
  3) Drop multiple chips into all slots
  4) Quit the program
  Enter your selection now: 1

  *** Drop SINGLE Chip ***
  Starting slot (0-8): 0
  Path: [0.0 0.5 1.0 1.5 2.0 2.5 2.0 2.5 2.0 2.5 2.0 1.5 2.0]
  Winnings: $1000.00

  MENU: Please enter a option:
  1) Drop a single chip into the one slot
  2) Drop multiple chips into one slot
  3) Drop multiple chips into all slots
  4) Quit the program
  Enter your selection now: 1

  *** Drop SINGLE Chip ***
  Starting slot (0-8): 8
  Path: [8.0 7.5 7.0 7.5 7.0 6.5 7.0 7.5 7.0 7.5 7.0 7.5 7.0]
  Winnings: $500.00

3. ensure correct calculation and formatting of the new option 3 feature with averages and an way to see that the bell curve is being manifest
*** Drop MULTIPLE Chips in ALL slots ***
Number of chips to drop into every slot: 100
SLOT 0: Winnings = $60400.00, Average per chip= $604.00
SLOT 1: Winnings = $71900.00, Average per chip= $719.00
SLOT 2: Winnings = $185000.00, Average per chip= $1850.00
SLOT 3: Winnings = $220800.00, Average per chip= $2208.00
SLOT 4: Winnings = $252900.00, Average per chip= $2529.00
SLOT 5: Winnings = $279500.00, Average per chip= $2795.00
SLOT 6: Winnings = $189100.00, Average per chip= $1891.00
SLOT 7: Winnings = $89100.00, Average per chip= $891.00
SLOT 8: Winnings = $91400.00, Average per chip= $914.00

*** Drop MULTIPLE Chips in ALL slots ***
Number of chips to drop into every slot: 56
SLOT 0: Winnings = $49600.00, Average per chip= $885.71
SLOT 1: Winnings = $50500.00, Average per chip= $901.79
SLOT 2: Winnings = $94800.00, Average per chip= $1692.86
SLOT 3: Winnings = $79800.00, Average per chip= $1425.00
SLOT 4: Winnings = $140700.00, Average per chip= $2512.50
SLOT 5: Winnings = $107400.00, Average per chip= $1917.86
SLOT 6: Winnings = $100600.00, Average per chip= $1796.43
SLOT 7: Winnings = $59600.00, Average per chip= $1064.29
SLOT 8: Winnings = $46600.00, Average per chip= $832.14

*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_OF_ROWS = 12;
int my_rand = 0;

//winning cash
double const WINNINGS_ZERO = 100;
double const WINNINGS_ONE = 500;
double const WINNINGS_TWO = 1000;
double const WINNINGS_THREE = 0;
double const WINNINGS_FOUR = 10000;
double const WINNINGS_FIVE = 0;
double const WINNINGS_SIX = 1000;
double const WINNINGS_SEVEN = 500;
double const WINNINGS_EIGHT = 100;

int menu(int option) //print menu and return user input
{
  cout << "MENU: Please enter a option:\n1) Drop a single chip into the one slot \n2) Drop multiple chips into one slot \n3) Drop multiple chips into all slots \n4) Quit the program \n";
  cout << "Enter your selection now: ";
  cin >> option;
  return option;
}

bool badInput() // clears the cin and prints error message
{
  if (cin.fail())
  {
    cin.clear();
    string waste;
    cin >> waste;
  }
  cout << "BAD INPUT: TRY AGAIN\n\n";
  return true;
}

double getWinnings(double current_column) // calculates the winnings based on constants and final position
{
  double winnings = 0;
  if (current_column == 0) { winnings = WINNINGS_ZERO; }
  else if (current_column == 1) { winnings = WINNINGS_ONE; }
  else if (current_column == 2) { winnings = WINNINGS_TWO; }
  else if (current_column == 3) { winnings = WINNINGS_THREE; }
  else if (current_column == 4) { winnings = WINNINGS_FOUR; }
  else if (current_column == 5) { winnings = WINNINGS_FIVE; }
  else if (current_column == 6) { winnings = WINNINGS_SIX; }
  else if (current_column == 7) { winnings = WINNINGS_SEVEN; }
  else if (current_column == 8) { winnings = WINNINGS_EIGHT; }
  return (winnings);
}

double oneChip(double startSlot, int option) // Runs the one chip through one slot
{
  if (startSlot <0 || startSlot > 8 || cin.fail())
  {
    badInput();
  }
  else
  {
    double current_column = startSlot;
    if (option == 1)
    {
      cout << "Path: [" << fixed << setprecision(1) << current_column << " "; // print out first part of path
    }
    for (int current_row = 1; current_row <= NUM_OF_ROWS; current_row++)
    {
      my_rand = rand() % 2;

      if (my_rand == 1)
      {
        if (current_column != 8)// so that it dosent fall of the the right
        {
          current_column += 0.5;
        }
        else
        {
          current_column -= 0.5;
        }
      }
      else
      {
        if (current_column != 0) // so that it doesnet fall of the left
        {
          current_column -= 0.5;
        }
        else
        {
          current_column += 0.5;
        }

      }
      if (option == 1) 
      { 
        cout << fixed << setprecision(1) << current_column << " "; //continue printing out path
      }
    }
    if (option == 1) 
    {
      cout << "\b]\n"; // end printing out path
      cout << fixed << setprecision(2) << "Winnings: $" << getWinnings(current_column) << endl << endl;
    }
    return current_column;
  }
}

double multiChip(double chipQuantity, double startSlot, int option) // runs oneCoin multiple times though one slot
{
  double winnings_added = 0;
  for (int current_chip = 1; current_chip <= chipQuantity; current_chip++)
  {
    winnings_added += getWinnings(oneChip(startSlot, option));
  }
  if (option == 2)
  {
    cout << "Your winnings from " << fixed << setprecision(0) << chipQuantity << " chips: $" << fixed << setprecision(2) << winnings_added << endl;
    cout << "Average winings per chip: $" << winnings_added / chipQuantity << endl;
  }
  if (option == 3)
  {
    cout << fixed << setprecision(2) << winnings_added;
    cout << ", Average per chip= $" << winnings_added / chipQuantity << endl << endl;
  }
  
  return 0;
}

double allSlotMultiChip(double chipQuantity, int option) // runs multichip for every slot 0 through 8
{
  for (double currentslot = 0; currentslot <= 8; currentslot++)
  {
    cout << fixed << setprecision(0) << "SLOT " << currentslot <<": " <<  "Winnings = $";
    multiChip(chipQuantity, currentslot, option);
  }
  return 0;
}



int main()
{
  bool start_over = true;
  while (start_over == true)
  {
    int option_select = 0;
    option_select = menu(option_select);
    if (cin.fail())
    {
      badInput();
    }
    else if (option_select <= 0 || option_select > 4)
    {
      badInput();
    }
    else
    {
      if (option_select == 1)
      {
        cout << "\n*** Drop SINGLE Chip ***\n";
        int start_slot;
        cout << "Starting slot (0-8): ";
        cin >> start_slot;
        oneChip(start_slot, option_select);
      }
      else if (option_select == 2)
      {
        cout << "\n*** Drop MULTIPLE Chips in ONE slot ***\n";
        double chip_quantity;
        cout << "Number of chips: ";
        cin >> chip_quantity;
        if (!cin.fail() && chip_quantity > 0)
        {
          cout << "Starting slot (0-8): ";
          double start_slot;
          cin >> start_slot;
          if (start_slot >= 0 && start_slot <= 8)
          {
            multiChip(chip_quantity, start_slot, option_select);
            start_slot = -1; //ensure start slot gets reset between runs. sentinel value
          }
          else
          {
            badInput();
          }
        }
        else
        {
          badInput();
        }
      }
      else if (option_select == 3)
      {
        cout << "\n*** Drop MULTIPLE Chips in ALL slots ***\n";
        double chip_quantity;
        cout << "Number of chips to drop into every slot: ";
        cin >> chip_quantity;
        if (!cin.fail() && chip_quantity > 0)
        {
          allSlotMultiChip(chip_quantity, option_select);
        }
        else
        {
          badInput();
        }

      }
      else if (option_select == 4)
      {
        cout << "Goodbye!\n"<< endl;
        system("pause");
        return 0;
      }
      cout << endl;
    }
  }
  
  return 0;
}