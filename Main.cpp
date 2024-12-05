#include "DayHeaders.h"
#include <iostream>
#include <memory>

int main()
{
 std::vector<std::unique_ptr<Day>> days; 
 days.push_back(std::make_unique<Day1>(".\\input\\day1.txt")); days.push_back(std::make_unique<Day2>(".\\input\\day2.txt"));
 days.push_back(std::make_unique<Day3>(".\\input\\day3.txt")); days.push_back(std::make_unique<Day4>(".\\input\\day4.txt"));
 days.push_back(std::make_unique<Day5>(".\\input\\day5.txt"));

 for (int i = 0; i < days.size(); i++)
 {
  std::cout << "Day" << i+1 << " Result Part1: " << days[i]->SolvePart1() << "\n";
  std::cout << "Day" << i+1 << " Result Part2: " << days[i]->SolvePart2() << "\n";

  std::cout << "\n";
 }
 std::cout << "Press enter to close...";
 std::cin.get();
}