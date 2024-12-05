#include "Day2.h"


Day2::Day2(std::string path) : 
 Day(path)
{}


std::string Day2::SolvePart1()
{
 int safeReportsCount = 0;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  int offset = 0;
  int prevNum = 0;
  std::vector<int> numbers;
  bool safe = true;
  //extract numbers
  while (offset != line.npos)
  {
   int nextSpace = line.find(" ", offset);
   std::string sNum;
   if (nextSpace != line.npos)
   {
    sNum = line.substr(offset, nextSpace - offset);
    offset = nextSpace + 1;
   }
   else
   {
    sNum = line.substr(offset, line.length() - offset);
    offset = nextSpace;
   }
   numbers.push_back(std::stoi(sNum));
  }

  if (numbers.size() < 2)
  {
   break;
  }
  //check numbers
  if (numbers[0] < numbers[1]) //ascending
  {
   for (int j = 0; j < numbers.size()-1; j++)
   {
    if (numbers[j+1] <= numbers[j] || numbers[j+1]-3 > numbers[j])
    {
     safe = false;
     break;
    }
   }
  }
  else //descending
  {
   for (int j = 0; j < numbers.size()-1; j++)
   {
    if (numbers[j+1] >= numbers[j] || numbers[j+1]+3 < numbers[j])
    {
     safe = false;
     break;
    }
   }
  }
  
  if (safe)
  {
   safeReportsCount++;
  }

 }

 return std::to_string(safeReportsCount);
}

std::string Day2::SolvePart2()
{
 int safeReportsCount = 0;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  int offset = 0;
  int prevNum = 0;
  std::vector<int> numbers;
  bool safe = true;
  //extract numbers
  while (offset != line.npos)
  {
   int nextSpace = line.find(" ", offset);
   std::string sNum;
   if (nextSpace != line.npos)
   {
    sNum = line.substr(offset, nextSpace - offset);
    offset = nextSpace + 1;
   }
   else
   {
    sNum = line.substr(offset, line.length() - offset);
    offset = nextSpace;
   }
   numbers.push_back(std::stoi(sNum));
  }
  //iterating through the numbers while each position is erased once
  for(int a = 0; a < numbers.size()+1; a++)
  {
   safe = true;
   std::vector<int> numbersNew = numbers;
   if (a != 0)
   {
    numbersNew.erase(numbersNew.begin()+(a-1));
   }
  
   if (numbersNew.size() < 2)
   {
    break;
   }

   //check numbers
   if (numbersNew[0] < numbersNew[1]) //ascending
   {
    for (int j = 0; j < numbersNew.size()-1; j++)
    {
     if (numbersNew[j+1] <= numbersNew[j] || numbersNew[j+1]-3 > numbersNew[j])
     {
      safe = false;
      break;
     }
    }
   }
   else //descending
   {
    for (int j = 0; j < numbersNew.size()-1; j++)
    {
     if (numbersNew[j+1] >= numbersNew[j] || numbersNew[j+1]+3 < numbersNew[j])
     {
      safe = false;
      break;
     }
    }
   }
  
   if (safe)
   {
    safeReportsCount++;
    break;
   }
  }
 }

 return std::to_string(safeReportsCount);
}
