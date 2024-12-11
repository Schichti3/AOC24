#include "Day3.h"


Day3::Day3(std::string path, int dayNum) : 
 Day(path, dayNum)
{}


std::string Day3::SolvePart1()
{
 int result = 0;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  int offset = 0;
  while (line.find("mul(", offset) != line.npos)
  {
   int paranthesisStart = line.find("mul(", offset) + 4;
   offset = paranthesisStart;
   //check for valid paranthesis content
   std::string firstNum;
   std::string secondNum;
   bool commaReached = false;
   bool closingParenthesisReached = false;
   for (int j = paranthesisStart; j < line.size(); j++)
   {
    char c = line[j];
    if (line[j] != ',' && !isdigit(line[j]) && line[j] != ')')
    {
     break;
    }

    if (isdigit(line[j]) && !commaReached)
    {
     firstNum += line[j];
    }
    else if (line[j] == ',')
    {
     commaReached = true;
    }
    else if (isdigit(line[j]) && commaReached)
    {
     secondNum += line[j];
    }
    else if (line[j] == ')' && commaReached)
    {
     closingParenthesisReached = true;
    }
   }

   if(closingParenthesisReached)
   {
    int num1 = std::stoi(firstNum);
    int num2 = std::stoi(secondNum); 

    if (num1 > 999 || num2 > 999)
    {
     break;
    }

    result += num1 * num2;
   }
  }
 }
 return std::to_string(result);
}

std::string Day3::SolvePart2()
{
 int result = 0;
 bool mulAllowed = true;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  int offset = 0;
  while (line.find("mul(", offset) != line.npos)
  {
   int paranthesisStart = line.find("mul(", offset) + 4;

   if (line.rfind("do()", paranthesisStart) != line.npos && line.rfind("do()", paranthesisStart) > offset)
   {
    mulAllowed = true;
   }


   if (line.rfind("don't()", paranthesisStart) != line.npos && line.rfind("don't()", paranthesisStart) > offset)
   {
    mulAllowed = false;
   }
   
   offset = paranthesisStart;

   if (!mulAllowed)
   {
    continue;
   }
   //check for valid paranthesis content
   std::string firstNum;
   std::string secondNum;
   bool commaReached = false;
   bool closingParenthesisReached = false;
   for (int j = paranthesisStart; j < line.size(); j++)
   {
    char c = line[j];
    if (line[j] != ',' && !isdigit(line[j]) && line[j] != ')')
    {
     break;
    }

    if (isdigit(line[j]) && !commaReached)
    {
     firstNum += line[j];
    }
    else if (line[j] == ',')
    {
     commaReached = true;
    }
    else if (isdigit(line[j]) && commaReached)
    {
     secondNum += line[j];
    }
    else if (line[j] == ')' && commaReached)
    {
     closingParenthesisReached = true;
    }
   }

   if(closingParenthesisReached)
   {
    int num1 = std::stoi(firstNum);
    int num2 = std::stoi(secondNum); 

    if (num1 > 999 || num2 > 999)
    {
     break;
    }

    result += num1 * num2;
   }
  }
 }
 return std::to_string(result);
}
