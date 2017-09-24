/*
 *   An example of a C API that provides a callback mechanism.
 */

#include <stdio.h>
#include "cheesefinder.h"


//cheesetable g_table2;
cheesetable g_table2;
cheesetable g_table;

static char *cheeses[] = {
  "cheddar",
  "camembert",
  "that runny one",
  0
};

void test_cheesefunc(char *name, void *user_data);

void test_cheesefunc(char *name, void *user_data)
{
    char *p_data = (char *)user_data;
    printf("test_cheesefunc %s %d\n", name, (int)p_data);
}

int main(){
    cheesefunc ptr = test_cheesefunc;
    g_table2.f1 = ptr;
    printf("function %x\n", g_table2.f1);
    register_table(g_table2);
    find_cheeses(test_cheesefunc, (void *)99);
	printf("press any key to end\n");
	getch();
    return 0;
}

int register_table(cheesetable t){
    printf("register_table init!\n");
    g_table = t;
    printf("register_table init done! %x\n", g_table.f1);
    return (g_table.f1 == 0)?1:0;
    //return 0;
}

void find_cheeses(cheesefunc user_func, void *user_data) {
  char **p = cheeses;
  printf("find_cheese begin %x\n", g_table.f1);
  if( g_table.f1 != 0){
    g_table.f1("this f1", (void *)1);
  }
  printf("in the middle\n");
  while (*p) {
    user_func(*p, user_data);
    ++p;
  }
  if( g_table.f2 != 0){
    g_table.f2("this f2", (void *)2);
  }
  printf("find_cheese end\n");
}

