#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

void abs_value(int num);
void sqrt_val(int num);
void randNum();
void largeNum(int num, int num2);
void even(int num);
void multiples(int num, int num2);
void perfectNum(int num);

int main() {
  int num, num2;
  char choice;
  cout << "\nWhich would you like to do?: " << endl;
  cout << "A. Absolute Value" << endl;
  cout << "B. Square Root" << endl;
  cout << "C. Random Number Guessing Game" << endl;
  cout << "D. Finding the Bigger Number" << endl;
  cout << "E. Even Number Finder" << endl;
  cout << "F. Multiples of Integers" << endl;
  cout << "G. Perfect Number" << endl;
  cout << "Q. Quit" << endl;
  cin >> choice;
  switch (choice) {
    case 'a':
      cout << "Please enter a number: " << endl;
      cin >> num;
      abs_value(num);
      break;
    
    case 'b':
      cout << "Please enter a number: " << endl;
      cin >> num;
      sqrt_val(num);
      break;

    case 'c':
      randNum();
      break;

    case 'd':
      cout << "Please enter a number" << endl;
      cin >> num;
      cout << "Please enter another number" << endl;
      cin >> num2;
      largeNum(num, num2);
      break;

    case 'e':
      cout << "Please enter a number" << endl;
      cin >> num;
      even(num);
      break;

    case 'f':
      cout << "Please provide a number: " << endl;
      cin >> num;
      cout << "Please provide ANOTHER number: " << endl;
      cin >> num2;
      multiples(num, num2);
      break;

    case 'g':
      cout << "Enter a number: " << endl;
      cin >> num;
      perfectNum(num);
      break;

    case 'q':
      cout << "Thanks for playing. Good bye!" << endl;
      return 0;

    default:
      cout << "You chose a wrong option. You are done." << endl;
      return 0;
  }
}


void abs_value(int num) {
  float abs_val;
  abs_val = abs(num);
  cout << "The absolute value of " << num << " is " << abs_val << endl;
  main();
}

void sqrt_val(int num) {
  float val = sqrt(num);
  do {
    float val = sqrt(num);
    cout << "The square root of " << num << " is " << val << endl;
    cout << "Please enter another value: " << endl;
    cin >> num;
  } while (num > 0);
  cout << "You entered a negative number. No more square rooting." << endl;
  main();
}

void randNum() {
  int rand_num;
  int guesses = 0;
  int guess;
  string playAgain;
  srand(time(NULL));
  rand_num = rand() % 25 + 1;
  cout << "Please guess a number between 0 and 25" << endl;
  while (guesses < 10) {
    cin >> guess;
    if (guess < rand_num) {
      cout << "Your guess is too low." << endl;
      guesses++;
      cout << "Guesses: " << guesses << endl;
    } else if (guess > rand_num) {
      cout << "Your guess is too high." << endl;
      guesses++;
      cout << "Guesses: " << guesses << endl;
    } else {
      cout << "Yes! You guessed the number in " << guesses << " tries!" << endl;
      cout << "Would you like to play again?" << endl;
      cin >> playAgain;
      if (playAgain == "yes" || playAgain == "Yes") {
        randNum();
      } else {
        main();
      }
    }
  }
  cout << "I am sorry. But you were not able to guess the answer." << endl;
  cout << "Would you like to play again?" << endl;
  cin >> playAgain;
  if (playAgain == "yes" || playAgain == "Yes") {
    randNum();
  } else {
    main();
  }
}

void largeNum(int num, int num2) {
  if (num < num2) {
    cout << num2 << " is the bigger number\n" << endl;
    main();
  } else {
    cout << num << " is the bigger number\n" << endl;
    main();
  }
}

void even(int num) {
  int test = 0;
  do {
    if (num % 2 == 0) {
      test++;
      cout << "Your number is even!" << endl;
      cout << "Type in another number" << endl;
      cin >> num;
  } else {
    test++;
    cout << "Your number is odd...." << endl;
    cout << "Type in another number: " << endl;
    cin >> num;
    }
  } while (test < 5);
  main();
}

void multiples(int num, int num2) {
  int total;
  total = num % num2;
  if (num < 0 || num2 < 0) {
    cout << "You did not provide valid numbers." << endl;
    main();
  } else if (total == 0) {
    cout << "Yes, " << num2 << " is a multiple of " << num << endl;
  } else {
    cout << "No. These numbers are not multiples of each other." << endl;
  }
}

void perfectNum(int num) {
  int i, perf, sum = 0;
  for (i = 1; i <= (num/2); i++) {
    perf = num % 1;
    if (perf == 0) {
      sum = sum + i;
    }
  }
  if (sum == num) {
    cout << num << " is a perfect number" << endl;
    main();
  } else {
    cout << num << " is not a perfect number" << endl;
    main();
  }
}
