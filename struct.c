#include<stdio.h>
#include<stdlib.h>

struct fract {
  int num;
  int den;
  //unsigned char a; // ci sono i byte di padding per allineare le dimensioni
};

int *create_fraction(int num, int den){
  int *f = malloc(sizeof(int)*2);
  if(f == NULL) return NULL; // malloc error checking
  f[0] = num;
  f[1] = den;
  return f;
}

void print_fraction(int *f){
   printf("%d/%d\n", f[0], f[1]);
}

void simplify_fraction(int *f){
  for (int d = 2; d <= f[0] && d <= f[1]; d++){
    while (f[0]%d == 0 && f[1]%d == 0){
      f[0] /= d;
      f[1] /= d;
    }
  }
}

struct fract *create_fraction1(int num, int den){
  struct fract *f = malloc(sizeof(*f));
  if(f == NULL) return NULL; // malloc error checking
  f->num = num;
  f->den = den;
  return f;
}

// ritorno una struct
struct fract create_fraction2(int num, int den){
  struct fract f;
  f.num = num;
  f.den = den;
  return f;
}

void print_fraction1(struct fract *f){
   printf("%d/%d\n", f->num, f->den);
}

void simplify_fraction1(struct fract *f){
  for (int d = 2; d <= f->num && d <= f->den; d++){
    while (f->num%d == 0 && f->den%d == 0){
      f->num /= d;
      f->den /= d;
    }
  }
}

int main(void){
# if 0
  int *f1 = create_fraction(10,20);
  int *f2 = create_fraction(2,4);

  simplify_fraction(f1);
  print_fraction(f1);
  print_fraction(f2);
# endif

  // ------------------------------------------
  printf("%d\n",(int) sizeof(struct fract));

  struct fract a;
  //a.num = 1;
  //a.den = 2;
  printf("%d %d\n", a.num, a.den);
  struct fract *b = &a;
  b->num = 1;
  b->den = 2;
  printf("%d %d\n", b->num, b->den);


  // ------------------------------------------- 
  struct fract *f1 = create_fraction1(10,20);
  struct fract *f2 = create_fraction1(2,4);
  print_fraction1(f1);
  simplify_fraction1(f1);
  print_fraction1(f1);

  // ------------------------------------------
  // in questo caso ritorn ole struccture per valore
  // non si fa mai, perchè è inefficiente
  // il c fa una copia della struttura ritornata nelle variabile nuova
  struct fract f3 = create_fraction2(10,20);
  struct fract f4 = create_fraction2(2,4);
  print_fraction1(&f3);
  simplify_fraction1(&f3);
  print_fraction1(&f3);


  return 0;
}


