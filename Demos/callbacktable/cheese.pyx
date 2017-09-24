#
#   Cython wrapper for the cheesefinder API
#

cdef extern from "cheesefinder.h":
    ctypedef void (*cheesefunc)(char *name, void *user_data)
    void find_cheeses(cheesefunc user_func, void *user_data)
    ctypedef int (*calclenfunc)(char *name, void *user_data)
    ctypedef struct cheesetable:    # reference in clang's cheesetable type
        cheesefunc f1
        calclenfunc f2
    int register_table(cheesetable t)
    int value
    
cdef cheesetable g_table3
   
def find(f):
    global g_table3
    global value
    g_table3.f1 = mycallback
    g_table3.f2 = mycalclen
    value = register_table(g_table3)
    print ("before")
    find_cheeses(callback, <void*>f)
    print ("after")

cdef int mycalclen(char *name, void *f):
    l = 0
    if name:
        l = len(name.decode('utf-8'))
    print("inside mycalclen " + str(l))
    return l
    
cdef void mycallback(char *name, void *f):
    print("inside mycallback " + name.decode('utf-8'))
    
cdef void callback(char *name, void *f):
    print("callback infront")
    (<object>f)(name.decode('utf-8'))
    print("callback end")
    
