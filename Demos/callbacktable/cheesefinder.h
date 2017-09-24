
typedef void (*cheesefunc)(char *name, void *user_data);
typedef int (*calclenfunc)(char *name, void *user_data);

void test_cheesefunc(char *name, void *user_data);
void find_cheeses(cheesefunc user_func, void *user_data);

struct _cheesetable
{
cheesefunc f1;
calclenfunc f2;
} ;
typedef struct _cheesetable cheesetable;

int value;
