//
//  stringHandling.c
//  curlHTTPBasics
//
//  Created by Ehsaan Ahmed on 02/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#include "stringHandling.h"

#if DEBUG > 0
void outputStructInfo(int (outputFunction)(const char* m, ...), struct string* x) { // Take a function which has a string parameter and allow extras.
    if (x == NULL) {
        return;
    }
    outputFunction("Address of first character in string: %p\n", x->contents);
    outputFunction("Address of string's struct: %p\n\n", &x);

    return;
}
#endif

void initialiseString(struct string *to_init) {
    to_init->upperIndex = 1;
    to_init->contents = calloc(1, sizeof(char));
    
    #if DEBUG > 0
        outputStructInfo(OUTPUT_FUNC, to_init);
    #endif
    
}

void appendToString(struct string *appendTo, char* appendFrom) {
    // Calculate new size
    size_t new = strlen(appendTo->contents) + strlen(appendFrom) + 1;
    //strlen excludes the null byte
    
    appendTo->upperIndex = new-1; // Update upperIndex's size (-1 because 0-based indexing.)
    
    char* newStr = calloc(new, sizeof(char)); // Allocate num of bytes per character * number of characters
    
    strcat(newStr, appendTo->contents); // Copy existing into new memory location
    strcat(newStr, appendFrom); // Copy new contents into new memory location
    free(appendTo->contents); // Free old memory in the heap
    appendTo->contents = newStr; // Change pointer in string object
    
    #if DEBUG > 0
        outputStructInfo(OUTPUT_FUNC, appendTo);
    #endif

}

void deleteString(struct string *toDelete) {
    void* addr = toDelete;
    free(toDelete->contents); // The struct only contains the pointer to the string, so we should probably free that up first while we sitll have the address.
    free(toDelete); // Free the struct storing its info
#if DEBUG
    OUTPUT_FUNC("Deallocated struct at %p", addr);
#endif
    return;
}

void storeIntoString(struct string* stringToStoreIn, int maxLength) {
    char buffer[maxLength + 1]; // +1 for the null byte
    
    fgets(buffer, maxLength + 1, stdin);
    
    
    
    #if DEBUG
        outputStructInfo(OUTPUT_FUNC, stringToStoreIn);
    #endif
    
}
