#ifndef STRINGHEC_H
#define STRINGHEC_H

/**
    @brief Stampa una stringa

    Funzione per stampare una stringa c su cout

    @param str stringa da stampare

    @return void
*/
void stampa(const char* str);

/**
 * @brief Calcola la lunghezza di una stringa
 * 
 * @param str 
 * @return unsigned int 
 */
unsigned int lunghezza(const char* str);

/**
 * @brief Inverte l'odine dei caratteri in una stringa
 * 
 * @param str
 * @return Non ritorna nulla
 */
void invertire(char *str);

/**
 * @brief Fornisce la copia della stringha in input.
 * 
 * Fornisce la copia della stringha in input. La stringa è creata in Heap e ne è ceduta la proprietà al chiamante. 
 * @param str  puntatore a stringa di input
 * @return puntatore alla stringa creata 
 */
char* copia(const char* str);

/**
 * @brief Concatenazione di due stringhe.
 * 
 * 
 * Fornisce una stringa composta dalla concatenazione delle due stringhe fornite. Viene ceduta la proprietà al chiamante della stringa allocata in Heap
 * @param s1 
 * @param s2 
 * @return char* 
 */
char* concatena(char* s1, char* s2);

const char* trova(const char* str, const char* st);

#endif