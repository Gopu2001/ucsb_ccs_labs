#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "strFuncs.h"
#include "tddFuncs.h"
using namespace std;


/* Precondition: Two valid strings s1 and s2, each containing a mix of alphabets, spaces and punctuations
 * Post condition: Return true if one string is an anagram of the other string. White spaces, punctuations and
 * the case for the letters (upper or lower) should not
 * affect your result.
 */
bool isAnagram(string s1, string s2){
  //const int len = s1.size();
  //string* d2 = new string[len];
  for(int i = 0; i < s1.size(); i++) {
    //string row = s1[0];
    if(!(isalpha(s1[i]) || isdigit(s1[i]))) {
      continue;
    }
    if(count(s1.begin(),s1.end(),s1[i]) != count(s2.begin(),s2.end(),s1[i])) {
      return false;
    }
  }
  return true;
}

/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 * You should provide a recursive solution
 */
bool isPalindrome(const string s1){
  cout << "        " << s1 << endl;
  if(s1 == "") {
    return true;
  }
  //cout << s1 << s1[0] << s1[s1.size()-1] << endl;
  //cout << s1[0] << "  " << s1[s1.size()-1] << endl;
  if(s1[0] == s1[s1.size()-1]) {
    //cout << ".." << endl;
    return isPalindrome(s1.substr(1,s1.size()-2));
  } else {
    return false;
  }
  // return true;
}

int main() {
  //cout << "--- isAnagram() ---" << endl;
  //cout << "TRUE   " << isAnagram("123", "321") << endl;
  //cout << "FALSE  " << isAnagram("123", "324") << endl << endl;
  //cout << "--- isPalindrome() ---" << endl;
  //bool pal1 = isPalindrome("1234321");
  //bool pal2 = isPalindrome("1233230");
  //cout << "(1234321) TRUE   " << pal1 << endl;
  //cout << "(1232320) FALSE  " << pal2 << endl;
  assertEquals(1, isAnagram("abc", "cba"), "isAnagram(abc, cba)");
  assertEquals(1, isAnagram("abc", "abc"), "isAnagram(abc, abc)");
  assertEquals(1, isAnagram("abc", "bac"), "isAnagram(abc, bac)");
  assertEquals(1, isAnagram("PiZzA", "PiZzA"), "isAnagram(PiZzA, PiZzA)");
  assertEquals(0, isAnagram("abc", "ccba"), "isAnagram(abc,ccba)");
  assertEquals(0, isAnagram("cba", "ccba"), "isAnagram(cba, ccba)");
  assertEquals(0, isAnagram("hello", "helo"), "isAnagram(hello, helo)");
  assertEquals(0, isAnagram("hello", "PiZzA"), "isAnagram(hello, PiZzA)");
  assertEquals(0, isAnagram("bac", "helo"), "isAnagram(bac, helo)");
  return 0;
}
