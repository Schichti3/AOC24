#include "Day9.h"
#include <cassert>
#include <iostream>
#include <algorithm>

Day9::Day9(std::string path, int dayNum) : 
 Day(path, dayNum)
{}


void Day9::DecompressInput(std::map<int, int>& files, std::map<int, int>& freeSpaces)
{
 bool fileBlock = true; 
 int fileId = 0;
 int spaceId = 0;

 //since the input is said to only be one long line we can directly do this:
 for (int i = 0; i < mLines[0].size(); i++)
 {
  int sequenceLength = mLines[0][i] - '0';

  if (sequenceLength == 0 && fileBlock)
  {
   assert("Seems like there are files with length 0, oh god.");
  }
//   if (sequenceLength == 0 && !fileBlock)
//   {
//    fileBlock = !fileBlock;
//    continue; 
//   }

  if (fileBlock)
  {
   files[fileId] = sequenceLength;
   fileId++;
  }
  else
  {
   freeSpaces[spaceId] = sequenceLength;
   spaceId++;
  }

  fileBlock = !fileBlock;
 }
 
}

void Day9::CompressPart1(std::map<int, int> files, std::map<int, int> freeSpaces, std::map<int, int>& dest)
{
 int pos = 0;
 auto lastUnfinishedFileIt = std::prev(files.end());
 auto filesIt = files.begin();
 auto freeSpaceIt = freeSpaces.begin();


 while (true)
 {
  //File block
  int length = filesIt->second;
  for (int i = 0; i < length; i++)
  {
   dest[pos] = filesIt->first;
   pos++;
  }
  filesIt++;

  //Space block
  length = freeSpaceIt->second;
  for (int i = 0; i < length; i++)
  {
   if (lastUnfinishedFileIt->second > 0)
   {
    lastUnfinishedFileIt->second--;
    dest[pos] = lastUnfinishedFileIt->first;
    pos++;
   }
   else
   {
    lastUnfinishedFileIt--;
    lastUnfinishedFileIt->second--;
    dest[pos] = lastUnfinishedFileIt->first;
    pos++;
    
    if (filesIt == lastUnfinishedFileIt)
    { 
     return;
    }
   }
  }
  freeSpaceIt++;
 }

 for (int i = 0; i < lastUnfinishedFileIt->second; i++)
 {
  dest[pos] = lastUnfinishedFileIt->first;
  pos++;
 }
}

void Day9::CompressPart2(std::map<int, int> files, std::map<int, int> freeSpaces, std::vector<int>& dest)
{
 int pos = 0;
 auto lastUnfinishedFileIt = std::prev(files.end());

 //convert freeSpaces Map to vector of vector
 std::vector<std::vector<int>> vFreeSpaces;
 for (auto freeSpaceIt = freeSpaces.begin(); freeSpaceIt != freeSpaces.end(); freeSpaceIt++)
 {
  std::vector<int> spaces;
  spaces.reserve(freeSpaceIt->second);
  for (int i = 0; i < freeSpaceIt->second; i++)
  {
   if (freeSpaceIt->second)
   {
    spaces.emplace_back(-1);
   }
  }
  vFreeSpaces.push_back(std::move(spaces));
 }

 std::vector<int> emptyFileIds;

 for (auto filesIt = std::prev(files.end()); filesIt != files.begin(); filesIt--)
 {
  for (int i = 0; i < filesIt->first; i++)
  {
   if (std::count(vFreeSpaces[i].begin(), vFreeSpaces[i].end(), -1) >= filesIt->second)
   {
    for (int j = 0; j < vFreeSpaces[i].size(); j++)
    {
     if (vFreeSpaces[i][j] == -1)
     {
      for (int a = j; a <  vFreeSpaces[i].size() && a < filesIt->second; a++)
      {
       vFreeSpaces[i][a] = filesIt->first;
      }
      break;
     }
    }
    emptyFileIds.push_back(filesIt->first);
    //filesIt->second = 0;
    break;
   }
  }
 }

 int spacesIndex = 0;
 for (auto filesIt = files.begin(); filesIt != files.end() || filesIt->second != 0; filesIt++)
 {
  bool fillWithEmptiness = false;

  if (std::find(emptyFileIds.begin(), emptyFileIds.end(), filesIt->first) != emptyFileIds.end())
  {
   fillWithEmptiness = true; 
  }

  for (int i = 0; i < filesIt->second; i++)
  {
   if (fillWithEmptiness)
   {
    dest.push_back(-1);
   }
   else
   {
    dest.push_back(filesIt->first);
   }
  }

  for (int j = 0; j < vFreeSpaces[spacesIndex].size(); j++)
  {
   dest.push_back(vFreeSpaces[spacesIndex][j]);
  }
  spacesIndex++;
 }

}

unsigned long long Day9::GetCheckSum(const std::map<int, int>& compressed)
{
 unsigned long long result = 0;
 for (auto it = compressed.begin(); it != compressed.end(); it++)
 {
  result += it->first * it->second;
 }
 return result;
}

unsigned long long Day9::GetCheckSum(const std::vector<int>& compressed)
{
 unsigned long long result = 0;
 for (int i = 0; i < compressed.size(); i++)
 {
  if (compressed[i] >= 0)
  {
   result += i * compressed[i];
  }
 }
 return result;
}

void Day9::PrintCompressed(const std::map<int, int>& compressed)
{
 std::cout << std::endl;
 for (auto it = compressed.cbegin(); it != compressed.cend(); it++)
 {
  std::cout << it->second << " ";
 }
 std::cout << std::endl;
}

void Day9::PrintCompressed(const std::vector<int>& compressed)
{
 std::cout << std::endl;
 for (auto it = compressed.cbegin(); it != compressed.cend(); it++)
 {
  std::cout << *it << " ";
 }
 std::cout << std::endl;
}

std::string Day9::SolvePart1()
{
 std::map<int, int> files;
 std::map<int, int> freeSpaces;
 DecompressInput(files, freeSpaces);

 std::map<int, int> compressed;
 CompressPart1(files, freeSpaces, compressed);

 unsigned long long ergebnis = GetCheckSum(compressed);

 return std::to_string(ergebnis);
}

std::string Day9::SolvePart2()
{
 std::map<int, int> files;
 std::map<int, int> freeSpaces;
 DecompressInput(files, freeSpaces);

 std::vector<int> compressed;
 CompressPart2(files, freeSpaces, compressed);

 //PrintCompressed(compressed);

 unsigned long long ergebnis = GetCheckSum(compressed);

 return std::to_string(ergebnis);
}
