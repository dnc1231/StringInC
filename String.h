#ifndef _String_h
#define _String_h 1


typedef
struct String {
    unsigned int capacity;
    unsigned int length;
    char *data;
} String;

String *makeString(const char *src);
String *utStrdup(String *s);
void utStrfree(String *s);
unsigned int utStrlen(String *s);
String *utStrcpy(String *dst, String *src);
String *utStrcat(String *dst, String *suffix);
String *utStrrealloc(String *s, unsigned int newCapacity);
void printut(String *s); // print string 


#endif /* _String_h */