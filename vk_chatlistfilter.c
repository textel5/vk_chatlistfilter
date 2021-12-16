#include <stdio.h>

int
main()
{
  const char filter_begin[] = "\"member_id\":";
  int c, i, typing;
  i = 0;
  typing = 0;
  while ((c = getchar()) != EOF) {
    if (!typing) {
      if (filter_begin[i]) {
        if (c == filter_begin[i]) {
          i++;
        } else {
          i = 0;
        }
      } else {
        i = 0;
        typing = 1;
      }
    }
    if (typing) {
      if (c != ',') {
        printf("%c", c);
      } else {
        printf("\n");
        typing = 0;
      }
    }
  }
  return 0;
}