#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100. Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number (" << secretNumber << ") correctly in "
                      << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}

