#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
          static bool checkInclusion(string s1, string s2)
          {
                    map<char, int> mp;
                    int windowStart = 0;
                    int matched = 0;
                    for (int windowEnd = 0; windowEnd < s1.size(); windowEnd++)
                    {
                              mp[s1[windowEnd]]++;
                    }
                    for (int windowEnd = 0; windowEnd < s2.size(); windowEnd++)
                    {
                              char c = s2[windowEnd];
                              if (mp.find(c) != mp.end())
                              {
                                        mp[c]--;
                                        if (mp[c] == 0)
                                                  matched++;
                              }
                              if (matched == mp.size())
                                        return true;
                              if (windowEnd >= s1.size() - 1)
                              {
                                        if (mp.find(s2[windowStart]) != mp.end())
                                        {
                                                  mp[s2[windowStart]]++;
                                                  if (mp[s2[windowStart]] == 1)
                                                  {
                                                            matched--;
                                                  }
                                        }
                                        windowStart++;
                              }
                    }
                    return false;
          }
};

int main()
{
          string string1 = "abcccd";
          string string2 = "cbc";
          // To check in any premutation of string 2 exists in string 1 or not
          cout << Solution::checkInclusion(string2, string1) << endl;
}