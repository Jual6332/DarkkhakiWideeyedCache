#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX_DOLLARS = 100;
const int MAX_TURN = 2;

void PrintHBD(string name);

string users[2] = {"John","Diane"};

bool FindUserName(string users[],string user_name);

class BankAccount
{
  private:
    float balance;
  public:
    BankAccount();
    void DepositFunds(float);
    float getBalance();
    void Widthdrawl(float);
};

// Constructor
BankAccount::BankAccount(){
  balance=0;
}

float BankAccount::getBalance()
{
  return balance;
}

void BankAccount::DepositFunds(float newMoney)
{
  balance = balance + newMoney;
}

// Struct Example
struct Student
{
  int age;
  float gpa;
  string courses[5];
};

struct Node
{
  int value;
  Node *next;
};

typedef Node* nodePtr;

int main() {
  // Arrays
  string userNames[2];
  userNames[0] = "Justin";
  userNames[1] = "Alice";

  cout << "Hello World!\n";

  // Example Switch Case
  switch(0)
  {
    case 1:
      cout << "Case A\n";
      break;
    case 2:
      cout << "Case B\n";
      break;
    default:
      cout << "Default case\n";
      break;
  }

  // Similar to Java and C, C++ is compiled at run-time and does not rely on events

  // Flow of assignment is right to left

  // Cout stands for console output

  string customerName = "Sarah";
  int customer_qty_pizzas = 2;
  float pizzas_cost = 7.50;

  float customer_total = customer_qty_pizzas*pizzas_cost;

  cout << customerName << "'s order costs $" << customer_total << endl;
  
  // Chapter 1 Challenge: Ask user for their favorite type of food
  string favorite_food;
  cout << "Enter your favorite food:" << endl;
  cin >> favorite_food;
  cout << "My favorite food is also " << favorite_food << endl;

  // Chapter 2: Casting Data Types Lesson
  int numEggs = 2;
  cout << static_cast<int>(numEggs*0.75) << endl;
  cout << static_cast<float>(numEggs)*0.75 << endl;
  // Notice how the decimal portion is truncated during cast to int but not to float

  // Chapter 2: Math operators lesson
  // Ceil and floor
  int taxRate = floor(5.95);
  cout << "Send 5.95 to floor results in " << taxRate << endl;
  taxRate = ceil(5.95);
  cout << "Send 5.95 to ceil results in " << taxRate << endl;
  // Modulus operator
  bool isEven = 6%2;
  if (isEven == 0)
  {
    cout << "6 is even."<< endl;
  } else {
    cout << "6 is odd."<< endl;
  }
  // Power, sqrt, abs, fabs
  int power = pow(5,2);
  int square_me = sqrt(4.0);
  int value = -1;
  int value_abs = abs(value);
  int value_fabs = fabs(value);
  int random_num = rand()%6;

  // Chapter 2 Challenge: Create a value to
  int chipsInPile = rand()%100 +1;
  int maxTake = MAX_TURN * chipsInPile;

  int numberChipsTaken = MAX_TURN * rand()%50;

  // Arrays are passed by reference to the address in memory of the array
  // When writing a function, there are no optional parameters. Each parameter defined by a user-made function is required.
  PrintHBD("Jacob");

  bool result = FindUserName(users,"John");
  if (result)
  {
    cout << "John is a ClubPenguin user." << endl; 
  } else {
    cout << "John is not a ClubPenguin user." << endl;
  }
  result = FindUserName(users,"Jacob");
  if (result)
  {
    cout << "Jacob is a ClubPenguin user." << endl; 
  } else {
    cout << "Jacob is not a ClubPenguin user." << endl;
  }

  char answer;
  cout << "Do you want to enable cookis? (Y/n)" << endl;
  cin >> answer;

  if (toupper(answer) == 'Y'){
    cout << "Cookies are enabled.\n";
  } else {
    cout << "Cookies are not enabled.\n";
  }

  // Chapter 5: Reading and Writing Files
  // Part 1: Reading in file 
  ifstream inputFileA;
  string word;
  inputFileA.open("fileA.txt");

  if (!inputFileA.fail())
  {
    while (inputFileA >> word)
    {
      cout << word << endl;
    }
    inputFileA.close();
  }

  // Part 2: Writing to File
  ofstream outputFileA;
  outputFileA.open("fileB.txt", ios::app);
  outputFileA << "Me llamo Brian."<< endl;
  outputFileA.close();

  // Chapter 6: Data Structures
  // Part 1: Structs
  Student student1;
  student1.courses[0]="biology";
  student1.gpa = 3.6;
  //"calculus 1","economics","intro to programming"};

  // The individual data housed in a struct have to be assigned individually, not collectively

  // Part 2: Classes
  BankAccount checking;
  BankAccount savings;
  cout << savings.getBalance() << endl;

  // Part 3: Pointers

  // Part 4: Linked Lists
  // A linked list is a list of classes or structs with a defining pointer
  // A linked list is a dynamic way to link data. No need to define a set amount of elements like in an arry
  nodePtr head;
  nodePtr second;
  head->value = 10;
  head->next = second;
  second->value = 11;
  second->next = NULL;

  return 0;
}

void PrintHBD(string name)
{
  cout << "Happy birthday to " << name << endl;
}

bool FindUserName(string users[], string user_name)
{
  for (int i=0; i<2; i++)
  {
    if (users[i] == user_name)
    {
      return true;
    }
  }
  return false;
}