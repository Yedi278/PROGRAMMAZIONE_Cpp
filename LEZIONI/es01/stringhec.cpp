#include "stringhec.h"
#include <cassert>
#include <iostream>
#include <algorithm>

#define LOG(x) std::cout << x << std::endl

void stampa(const char* str){

    assert(str != NULL);

    int i=0;

    while(str[i] != '\0'){
        std::cout << str[i];
        i++;
    }

    std::cout << std::endl;
}

unsigned int lunghezza(const char* str){

    assert(str != NULL);

    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void invertire(char* str){

    assert(str != NULL);

    int l = lunghezza(str);

    int i=0;
    while(i<l/2){
        std::swap(str[i], str[l-i-1]);
        i++;
    }
}

char* copia(const char* str){

    assert(str != NULL);
    // return const_cast<char *>(str);
    int l = lunghezza(str)+1;
    char* tmp = new char[l];

    for(int i=0; i<l; i++){

        tmp[i] = str[i];
    }
    
    return tmp;
}

char* concatena(char* s1, char* s2){

    assert(s1 != NULL);
    assert(s2 != NULL);

    int l1 = lunghezza(s1);
    int l2 = lunghezza(s2);

    // LOG(l1);
    // LOG(l2);

    char* tmp = new char[l1+l2];

    stampa(tmp);

    for(int i=0; i<=l1+l2+1; i++){

        if(i < l1){
            tmp[i] = s1[i];
        }
        else{
            tmp[i] = s2[i-l1];
        }
    }
    return tmp;
}

bool token_trovato(const char* s, const char* st){

    while( (*s == *st) && (*s!='\0') ){
        ++s;
        ++st;
    }

    return (*st == '\0');
}

const char* trova(const char* str,const char* st){

    assert(str != NULL);
    assert(st != NULL);

    int l_st = lunghezza(st);

    for(int i=0; i<lunghezza(str)-lunghezza(st)+1; i++){

        bool trovato = token_trovato(str+i, st);
        if(trovato) return str+i;
    }
    return NULL;
}