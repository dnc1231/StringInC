#include<stdio.h>
#include<string.h>
#include "String.h"

void test1() {
    const char *q = "Daniel is the coolest kid in EE312 and he made these test cases";
    const char *p = "hi there";
    String *s = makeString(q);
    String *u = makeString(p);

    printf("%s", s->data);
    printf("\n");

    String *t = utStrdup(s);
    printf("%s", t->data);
    printf("\n");

    String *a = utStrdup(t);
    a = utStrrealloc(a, 200);
    a = utStrcat(a, s);
    printf("%s", a->data);
    printf("\n");

    printf(s->data);
    printf("%d\n", s->capacity);
    printf("%d\n", s->length);

    utStrcpy(s, u);

    printf(s->data);
    printf("%d\n", s->capacity);
    printf("%d\n", s->length);

    utStrfree(t);
    utStrfree(s);
    utStrfree(a);
}

void test2() {
    char str1[60] = "You catch flies with honey and this is just a test to see ";
    char str2[60] = " but you catch more honies being fly and this is just a te";
    String *utStr1;
    String *utStr2;

    utStr1 = makeString(str1);
    utStr2 = makeString(str2);

    utStr1 = utStrrealloc(utStr1, 80);

    utStr1 = utStrcat(utStr1, utStr2);

    String *utStr3 = utStrdup(utStr1);
    utStr3 = utStrrealloc(utStr3, 100);
    utStrcpy(utStr3, utStr2);

    printf("utStr3: %s\n", utStr3->data);
    printf("\tlength: %u\n", utStr3->length);
    printf("\tcapacity: %u\n", utStr3->capacity);

    printf("utStr1: %s\n", utStr1->data);
    printf("\tlength: %u\n", utStr1->length);
    printf("\tcapacity: %u\n", utStr1->capacity);

    printf("utStr2: %s\n", utStr2->data);
    printf("\tlength: %u\n", utStr2->length);
    printf("\tcapacity: %u\n", utStr2->capacity);

    utStrfree(utStr1);
    utStrfree(utStr2);
    utStrfree(utStr3);

}

void test3() {
    String *s = makeString("get it all you deserve it kendrick");
    s = utStrrealloc(s, 10000);
    fflush(stdout);

    String *ast = makeString(" too much and enough both we know");

    for(int k = 0; k < 9000; k++) utStrcat(s, ast);
    if(s->data[9000] != 't') printf("Test 3 fails\n");
    else if(strlen(s->data) != 10000) printf("Wrong string length - test 3 fails\n");

    printf("String: %s\n", s->data);
    printf("\tlength: %d", s->length);
    printf("\tcapacity: %d", s->capacity);

    utStrfree(s);
}

int main() {
    test1();
    test2();
    test3();
}

  
  