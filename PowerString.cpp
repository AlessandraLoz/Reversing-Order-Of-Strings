/* 
 * File:   PowerString.cpp
 * File:   PowerString.cpp
 * Purpose:The PowerString class is meant to take input and then reverse it using a loop, recursion, and a stack. The program also determines whether the inputted string is a palindrome
 *
 * Author: Alessandra Lozano
 *
 */
#include <iostream>
#include <stack>
#include "PowerString.h"

// initialize str with ini_str passing as a parameter
PowerString::PowerString(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string PowerString::getString() const
{
    return str;
}

// set the value of str to be the passed in parameter input_str
void PowerString::setString(string input_str)
{
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_loop() const
{
    string loopstr = "";
    string temp = "";
    for(int i = 0; i <= str.length(); i++)
    {
        temp = str.substr(str.length()-i,1);
        loopstr = loopstr + temp;
    }
   
    return loopstr;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_recursion() const
{
    if (str.length() == 0)
    {
        return str;
    }
    else
    {
        PowerString reverse(str.substr(1, str.length()-1));
        return(reverse.rev_recursion() + str[0]);
    }
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_stack() const
{
    string temp = "";
    stack<char> stackstr; 
    for (int i = 0; i < str.length(); i++)
    {
        stackstr.push(str[i]);
    }
    
    for (int i = 0; i < str.length(); i++)
    {
        temp = temp + stackstr.top();
        stackstr.pop();
    }
    
    return temp;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome() const
{
   int right = 0;
   int left = str.length() - 1;
   while(right < left) 
    {  
        if (str[right]!=str[left])
        {
            return false;
        }

        right ++;
        left --;
    }
   return true;

}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome_recursion() const
{
    // base case
    if (str.length() <= 1)
        return true;
    else // recursive case
    {
        PowerString shorter(str.substr(1, str.length()-2));
        bool firstPair = str[0] == str[str.length()-1];
        return (firstPair && shorter.isPalindrome_recursion());
    }    
}
        
// displays str followed by a new line marker
// to the standard output
void PowerString::print() const
{
    cout << str << endl;
}
