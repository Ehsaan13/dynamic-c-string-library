//
//  stringHandling.h
//  curlHTTPBasics
//
//  Created by Ehsaan Ahmed on 02/04/2024.
//

#ifndef stringHandling_h
#define stringHandling_h



#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

struct string {
    size_t upperIndex;
    char* contents;
};

#if DEBUG > 0
#define OUTPUT_FUNC printf
void outputStructInfo(int (outputFunction)(const char* m, ...), struct string* x);
#endif

void initialiseString(struct string *to_init);

void appendToString(struct string *appendTo, char* appendFrom);

void storeIntoString(struct string *stringToStoreIn, int maxLength);

#endif /* stringHandling_h */
