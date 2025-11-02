#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TFOBJ_TYPE_INT 0
#define TFOBJ_TYPE_STR 1
#define TFOBJ_TYPE_BOOL 2
#define TFOBJ_TYPE_LIST 3
#define TFOBJ_TYPE_SYMBOL 4

//-----------------------------------------
// Data structure
// ----------------------------------------
typedef struct tfobj {
  int refcount;
  int type; // TFOBJ_TYPE
  union {
    int i;
    struct {
      char *ptr;
      size_t len;
    } str;
    struct {
      struct tfobj **ele; // ele[0] contains a pointer
      size_t len;
    } list;
  };
} tfobj;

typedef struct tfparser{
  char *prg; // the program compile into a list
  char *p; //next token to parse
} tfparser;

typedef struct tfctx { //contesto di esecuzione
  tfobj *stack;
} tfctx;

// -----------------------------
// Object related function
// -----------------------------

// Allocation wrappers
void *xmalloc(size_t size){
 void *ptr = malloc(size);
 if (ptr == NULL){
   fprintf(stderr, "Out of memory allcoating %zu bytes\n", size);
   exit(1);
 }
 return ptr;
}

// allocater and init a new ToyForth obj
tfobj *createObject(int type){
  tfobj *o = malloc(sizeof(tfobj));
  o->type = type;
  o->refcount = 1;
  return o;
}

tfobj *createStringObject(char *s, size_t len){
  tfobj *o = createObject(TFOBJ_TYPE_STR);
  o->str.ptr = s;
  o->str.len = len;
  return o;
}

tfobj *createIntObject(int i){
  tfobj *o = createObject(TFOBJ_TYPE_INT);
  o->i = i;
  return o;
}

tfobj *createBoolObject(int i){
  tfobj *o = createObject(TFOBJ_TYPE_BOOL);
  o->i = i;
  return o;
}

tfobj *createSymbolObject(char *s, size_t len){
  tfobj *o = createStringObject(s, len);
  o->type = TFOBJ_TYPE_SYMBOL;
  return o;
}

tfobj *createListObject(int i){
  tfobj *o = createObject(TFOBJ_TYPE_LIST);
  o->list.ele = NULL;
  o->list.len = 0;
  return o;
}

tfobj compile(char *prgtext){
};

void exec(char *prgtext){};

int main(int argc, char **argv){
  if (argc != 2){
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  char *prgtext = "";
  tfobj *prg = compile(prgtext);
  exec(prgtext);
  printf("%s %d\n", argv[0], argc);
  return 0;
}



