#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

  struct Box b1,b2;

  initBox(&b1,2.9,3.9,1.4,1.1);
  assertEquals("ul=(2.9,3.9),w=1.4,h=1.1", boxToString(b1,3), "boxToString(b1,3)");

  initBox(&b2,3.14,3.14,3.14,3.14);
  assertEquals("ul=(3.14,3.14),w=3.14,h=3.14", boxToString(b2), "boxToString(b2)");
  assertEquals("ul=(3,3),w=3,h=3",     boxToString(b2,1), "boxToString(b2,1)");
  assertEquals("ul=(3.14,3.14),w=3.14,h=3.14", boxToString(b2,4), "boxToString(b2,4)");
  assertEquals("ul=(3.14,3.14),w=3.14,h=3.14", boxToString(b2,5), "boxToString(b2,5)");

  return 0;
}
