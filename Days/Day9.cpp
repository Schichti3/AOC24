#include "Day9.h"
#include <cassert>

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
  if (sequenceLength == 0 && !fileBlock)
  {
   continue; 
  }

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

void Day9::Compress(std::map<int, int> files, std::map<int, int> freeSpaces, std::map<int, int>& dest)
{
 int pos = 0;
 int mostRecentHandledFileId = -1;
 auto lastUnfinishedFileIt = files.rbegin();
 auto filesIt = files.begin();
 auto freeSpaceIt = freeSpaces.begin();


 while (filesIt != lastUnfinishedFileIt.base())
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
    lastUnfinishedFileIt++;
    lastUnfinishedFileIt->second--;
    dest[pos] = lastUnfinishedFileIt->first;
    pos++;
   }
  }
 }

 for (int i = 0; i < lastUnfinishedFileIt->second; i++)
 {
  dest[pos] = lastUnfinishedFileIt->first;
  pos++;
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

std::string Day9::SolvePart1()
{
 std::map<int, int> files;
 std::map<int, int> freeSpaces;
 DecompressInput(files, freeSpaces);

 std::map<int, int> compressed;
 Compress(files, freeSpaces, compressed);

 return std::to_string(GetCheckSum(compressed));
}

std::string Day9::SolvePart2()
{
 return "none";
}
