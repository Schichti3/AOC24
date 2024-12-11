#include "Day5.h"
#include <algorithm>
#include <utility>

/*
Ich entschuldige mich jetzt schonmal an die arme CPU, welche diese unschöne Lösung durcharbeiten muss :)
*/


Day5::Day5(std::string path, int dayNum) : 
 Day(path, dayNum)
{}

std::vector<OrderingRule> Day5::ExtractOrderingRules(std::vector<std::string>& lines)
{
 std::vector<OrderingRule> output;
 for (int i = 0; i < lines.size(); i++)
 {
  std::string line = lines[i];
  if (line.find("|") != line.npos)
  {
   std::string sNum1 = line.substr(0, line.find("|"));
   std::string sNum2 = line.substr(line.find("|")+1, line.length() - line.find("|"));
   int num1 = std::stoi(sNum1);
   int num2 = std::stoi(sNum2);
   output.push_back({num1, num2});
  }
  else
  {
   break;
  }
 }
 return output;
}

std::vector<std::vector<int>> Day5::ExtractUpdates(std::vector<std::string>& lines)
{
 std::vector<std::vector<int>> output;
 for (int i = 0; i < lines.size(); i++)
 {
  std::vector<int> nums;
  std::string line = lines[i];
  std::string num;
  if (line.find(",") != line.npos)
  {
   for (int j = 0; j < line.size(); j++)
   {
    if (isdigit(line[j]))
    {
     num += line[j];
    }
    else
    {
     nums.push_back(std::stoi(num));
     num.clear();
    }
    if (j == line.size()-1)
    {
     nums.push_back(std::stoi(num));
    }
   }
   output.push_back(nums);
  }
 }
 return output;
}

std::string Day5::SolvePart1()
{
 int result = 0;
 std::vector<OrderingRule> rules = ExtractOrderingRules(mLines);
 std::vector<std::vector<int>> updates = ExtractUpdates(mLines);

 for (int i = 0; i < updates.size(); i++)
 {
  std::vector<int> update = updates[i];
  bool updateValid = true;
  
  for (int j = 0; j < rules.size(); j++)
  {
   std::vector<int>::iterator itEarlierPage = std::find(update.begin(), update.end(), rules[j].EarlierPage);
   std::vector<int>::iterator itLaterPage = std::find(update.begin(), update.end(), rules[j].LaterPage);

   if (itEarlierPage != update.end() && itLaterPage != update.end())
   {
    int indexEarlierPage = std::distance(update.begin(), itEarlierPage);
    int indexLaterPage = std::distance(update.begin(), itLaterPage);

    if (indexEarlierPage > indexLaterPage)
    {
     updateValid = false;
     break;
    }
   }
  }
  if (updateValid)
  {
   result += update[update.size()/2]; 
  }
 }

 return std::to_string(result);
}

std::string Day5::SolvePart2()
{
 int result = 0;
 std::vector<OrderingRule> rules = ExtractOrderingRules(mLines);
 std::vector<std::vector<int>> updates = ExtractUpdates(mLines);

 for (int i = 0; i < updates.size(); i++)
 {
  std::vector<int> update = updates[i];
  bool updateValid = true;
  std::vector<OrderingRule> applyingRules;
  for (int j = 0; j < rules.size(); j++)
  {
   std::vector<int>::iterator itEarlierPage = std::find(update.begin(), update.end(), rules[j].EarlierPage);
   std::vector<int>::iterator itLaterPage = std::find(update.begin(), update.end(), rules[j].LaterPage);

   if (itEarlierPage != update.end() && itLaterPage != update.end())
   {
    applyingRules.push_back(rules[j]);
    int indexEarlierPage = std::distance(update.begin(), itEarlierPage);
    int indexLaterPage = std::distance(update.begin(), itLaterPage);

    if (indexEarlierPage > indexLaterPage && updateValid)
    {
     updateValid = false;
    }
   }
  }
  if (!updateValid)
  {
   bool updateFixed = false;
   while(!updateFixed)
   {
    for (int a = 0; a < applyingRules.size(); a++)
    {
     std::vector<int>::iterator itEarlierPage = std::find(update.begin(), update.end(), applyingRules[a].EarlierPage);
     std::vector<int>::iterator itLaterPage = std::find(update.begin(), update.end(), applyingRules[a].LaterPage);
     int indexEarlierPage = std::distance(update.begin(), itEarlierPage);
     int indexLaterPage = std::distance(update.begin(), itLaterPage);
     if (indexEarlierPage > indexLaterPage)
     {
      std::swap(update[indexEarlierPage], update[indexLaterPage]);
      a = -1;
      continue;
     }
    }
    updateFixed = true;
   }
   result += update[update.size()/2]; 
  }
 }

 return std::to_string(result);
}
