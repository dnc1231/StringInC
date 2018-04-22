//
// Created by Daniel on 10/3/2017.
//

/*
 *  EE312 Assignment 5.
 *  On my honor, Daniel Canterino, this programming assignment is my own work.
 *
 *  A program to provide a new and improved String type for C.
 *
 *  Name: Daniel Canterino
 *  email address: dnc1231@verizon.net
 *  UTEID: djc3323
 *  Section 5 digit ID: 16115
 *  Number of slip days used on this assignment: 0
 *. Total number of slip days used this semester: 0
 */

#include "String.h"
#include<stdio.h>
#include<stdlib.h>

unsigned int stringLength (const char *string);

/*This function takes a pointer to a string as input and converts it into the newly created String struct
 * It passes the string to stringLength to find the length of the string and stores it in the String struct created as
 * well as the capacity. It also reserves space in dynamic memory for the array for the string and copies the string
 * into that location with the pointer to this location being stored in struct->data*/
String *makeString(const char *src){
    int i = 0;
    unsigned int length;
    length = stringLength(src);
    char *copyData = NULL;
    copyData = calloc(length + 1, sizeof(char));//length + 1 for null terminal
    struct String *copy = malloc(sizeof(struct String));
    copy->capacity = length;
    copy->length = length;
    copy->data = copyData;//this stores the pointer to the first location in the string to the data member of the String
    while (*(src + i) != '\0'){
        copyData[i] = *(src + i);
        i++;
    }
    return (copy);
}

/*stringLength takes a pointer to a string (not the struct String) and counts the length of that string and returns that
 * value as an unsigned int*/
unsigned int stringLength (const char *string){
    unsigned int count = 0;
    while (*string != '\0'){
        count++;
        string++;
    }
    return (count);
}

/*utStrdup takes a pointer to a struct String and creates an exact copy of it and returns a pointer to it*/
String *utStrdup(String *s){
    int i = 0;
    struct String *copy = malloc(sizeof(struct String));
    copy->length = s->length;
    copy->capacity = s->capacity;
    char *copyData = calloc(s->length + 1, sizeof(char));//+1 for null terminal
    copy->data = copyData;
    while (*(s->data + i) != '\0'){
        copyData[i] = *(s->data + i);
        i++;
    }
    return (copy);
}

/*utStrfree frees the dynamic memory allocated for a String struct and its Data member eg the actual string*/
void utStrfree(String *s){
    free(s->data);
    free(s);
    s = NULL;
}

/*utStrlen counts the length of a String and updates that String's length member*/
unsigned int utStrlen(String *s){
    unsigned int count = 0;
    int i = 0;
    while (*(s->data + i) != '\0'){
        count++;
        i++;
    }
    s->length = count;
}

/*utStrcpy replaces the String dst data with String src data. It will not go over the capacity of dst. It then updates
 * the length of the dst length member after attempting to create the copy*/
String *utStrcpy(String *dst, String *src){
    char i = 0;
    while ((i < dst->capacity) && (*(src->data + i) != '\0')){
        *(dst->data + i) = *(src->data + i);
        i++;
    }
    *(dst->data + i) = '\0';
    utStrlen(dst);
    return (dst);
}

/*utStrcat concatenates dst data with the suffix data but will not overflow the capacity of dst. It then updates the
 * length of the data member now stored in dst*/
String *utStrcat(String *dst, String *suffix){
    char i = 0;
    while ((dst->length + i < dst->capacity) && *(suffix->data +i) != '\0'){
        *(dst->data + dst->length + i) = *(suffix->data + i);
        i++;
    }
    utStrlen(dst);
}

/*utStrrealloc reallocates memory space if the new capacity desired for a String is greater than its current assigned
 * capacity. It then copies the data from the original String into the newly allocated memory location. It then frees
 * the original data location and updates the data member of String s to that new pointer.*/
String *utStrrealloc(String *s, unsigned int newCapacity){
    int i = 0;
    if (s->capacity >= newCapacity){
        return (s);
    }
    else{
        s->capacity = newCapacity;
        char *copyData = calloc(s->capacity + 1, sizeof(char));
        while (*(s->data + i) != '\0') {
            copyData[i] = *(s->data + i);
            i++;
        }
        free(s->data);
        s->data = copyData;
        return (s);
    }
}