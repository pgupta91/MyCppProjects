/*In the programming language of your choice, write a program generating the first n Fibonacci numbers F(n), printing

"Buzz" when F(n) is divisible by 3.
"Fizz" when F(n) is divisible by 5.
"FizzBuzz" when F(n) is divisible by 15.
"BuzzFizz" when F(n) is prime.
the value F(n) otherwise.
We encourage you to compose your code for this question in a way that represents the quality of code you produce in the workplace - e.g. tests, documentation, linting, dependency management (though there's no need to go this far).

Please upload your code to GitHub or bitbucket and post a link to the repo or gist as your answer in the Lever form.
*/

#include <iostream>
#include <string>
using namespace std;

bool checkPrime(unsigned long int number)
{
	unsigned long int i;
	bool isPrime = true;
	if (number == 1)
		return false;

	for (i = 2; i <= number / 2; ++i)
	{
		if (number % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}


void F(unsigned long int n)
{
	unsigned long int firstTerm = 0;
	unsigned long int secondTerm = 1;
	unsigned long int nextTerm = 0;
	bool divBy3 = false;
	bool divBy5 = false;
	bool printedFirstTwoTerms = false;
	bool isPrime = false;

	cout << "Fibonacci Series: ";

	for ( unsigned long int i = 1; i <= n; ++i)
	{
		if (!printedFirstTwoTerms)
		{
			// Prints the first two terms.
			if (i == 1)
			{
				cout << " " << firstTerm << " ";
				continue;
			}
			if (i == 2)
			{
				cout << secondTerm << " ";
				printedFirstTwoTerms = true;
				continue;
			}
		}
		nextTerm = firstTerm + secondTerm;
		firstTerm = secondTerm;
		secondTerm = nextTerm;
		divBy3 = (nextTerm % 3 == 0);
		divBy5 = (nextTerm % 5 == 0);
		// Executes code and check for prime Number for first 3 and 5 it will force to check prime Number.
		// otherwise it wont check if number is divisible by 3 and 5 after first 5 terms got printed
		if ((nextTerm <= 5) || !(divBy3 || divBy5))
		{
			isPrime = checkPrime(nextTerm);
		}
		//isPrime = (!(divBy3 || divBy5) ? false : checkPrime(nextTerm));
		cout << (divBy3 ? "Buzz" : "") << (divBy5 ? "Fizz" : "") << ((isPrime)? "BuzzFizz": "") <<((divBy3 || divBy5 || isPrime)? "": to_string(nextTerm))<< " ";
		isPrime = false;
	}
}
int main()
{
	 unsigned long int n;
	cout << "Enter the number of terms: ";
	cin >> n;
	F(n);
	return 0;
}
