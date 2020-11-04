#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include "strFuncs.h"
#include "recLinkedListFuncs.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [num of test to run]" << std::endl;
    return 1;
  } else {

    int threeNums[3]={10,20,30};
    LinkedList *list1 = arrayToLinkedList(threeNums,3);
    int fourNums[4]={10,20,30,0};
    LinkedList *list2 = arrayToLinkedList(fourNums,4);
    int fiveNums[5]={10,20,30,0,100};
    LinkedList *list3 = arrayToLinkedList(fiveNums,5);
    int sixNums[6]={10,20,30,100,0,300};
    LinkedList *list4 = arrayToLinkedList(sixNums,6);

    int testNum = atoi(argv[1]);
    if (testNum == 1) {

      START_TEST_GROUP("IS_ANAGRAM");

      assertEquals(1, isAnagram("abc", "cba"), "isAnagram(abc, cba)");
      assertEquals(1, isAnagram("abc", "abc"), "isAnagram(abc, abc)");
      assertEquals(1, isAnagram("abc", "bac"), "isAnagram(abc, bac)");
      assertEquals(1, isAnagram("PiZzA", "PiZzA"), "isAnagram(PiZzA, PiZzA)");
      assertEquals(0, isAnagram("abc", "ccba"), "isAnagram(abc,ccba)");
      assertEquals(0, isAnagram("cba", "ccba"), "isAnagram(cba, ccba)");
      assertEquals(0, isAnagram("hello", "helo"), "isAnagram(hello, helo)");
      assertEquals(0, isAnagram("hello", "PiZzA"), "isAnagram(hello, PiZzA)");
      assertEquals(0, isAnagram("bac", "helo"), "isAnagram(bac, helo)");

    } else if (testNum == 2) {

      START_TEST_GROUP("IS_PALINDROME");

      string p1 = "abcba";
      string p2 = "agaga";
      string p3 = "qwwq";
      string p4 = "asdsa";
      string p5 = "FGHJHGF";
      string np1 = "sdfgh";
      string np2 = "yuikj";
      string np3 = "ikjh";
      string np4 = "trdfhg";
      string np5 = "htfflH";

      assertEquals(1, isPalindrome(p1), "isPalindrome(p1)");
      assertEquals(1, isPalindrome(p2), "isPalindrome(p2)");
      assertEquals(1, isPalindrome(p3), "isPalindrome(p3)");
      assertEquals(1, isPalindrome(p4), "isPalindrome(p4)");
      assertEquals(1, isPalindrome(p5), "isPalindrome(p5)");
      assertEquals(0, isPalindrome(np1), "isPalindrome(np1)");
      assertEquals(0, isPalindrome(np2), "isPalindrome(np2)");
      assertEquals(0, isPalindrome(np3), "isPalindrome(np3)");
      assertEquals(0, isPalindrome(np4), "isPalindrome(np4)");
      assertEquals(0, isPalindrome(np5), "isPalindrome(np5)");

    } else if (testNum == 3) {

      START_TEST_GROUP("RECURSIVE_SUM");

      assertEquals(60, recursiveSum(list1->head), "recursiveSum(list1->head)");
      assertEquals(60, recursiveSum(list2->head), "recursiveSum(list2->head)");
      assertEquals(160, recursiveSum(list3->head), "recursiveSum(list3->head)");
      assertEquals(460, recursiveSum(list4->head), "recursiveSum(list4->head)");

    } else if (testNum == 4) {

      START_TEST_GROUP("RECURSIVE_LARGEST_VALUE");

      assertEquals(30, recursiveLargestValue(list1->head), "recursiveLargestValue(list1->head)");
      assertEquals(30, recursiveLargestValue(list2->head), "recursiveLargestValue(list2->head)");
      assertEquals(100, recursiveLargestValue(list3->head), "recursiveLargestValue(list3->head)");
      assertEquals(300, recursiveLargestValue(list4->head), "recursiveLargestValue(list4->head)");

    }
  }

  return 0;
}
