#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 2000          // Maximum number of words the list can store
#define MAX_LEN 101             // Maximum length of a word (100 chars + null)
#define FILE_NAME "words.txt"


// COP 3223C Fall 2025
// Student Name: TODO_your_name_here
// File Name: practice10_yoursurname.c

// IMPORTANT: Rename this file using your actual surname in lowercase,
// removing any whitespace or dashes. Do not modify or remove any TODO
// comments, as doing so will interfere with the grading system.
// Only make changes within the function bodies. No other parts of
// the file will be graded, so do not alter any other code.


typedef struct WordFreq_s {
    char word[MAX_LEN];         // a single word
    int freq;                   // how many times it appeared
} WordFreq;

typedef struct WordList_s {
    WordFreq words[MAX_WORDS];  // array of WordFreq structs
    int size;                   // current logical size (number of elements used)
    int capacity;               // maximum number of elements allowed
} WordList;


// Function Prototypes
WordFreq create_word(const char *word);
WordList create_list(int capacity);
WordFreq *get_word(WordList *list, const char *query);
void increment_count(WordFreq *word);
void add_word(WordList *list, const char *word);
void process_word(WordList *list, char *line);
void print_list(const WordList *list);
int populate_list(WordList *list, const char *filename);
void selection_sort(WordList *list);

// Helper Functions (in case you need them)
char *to_lower(char *str);
void clear_buffer(FILE *fp);
char *trim_string(char *str);



// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Create an empty word list with the MAX_WORDS capacity
    WordList words = create_list(MAX_WORDS);

    // Load words from the text file and build the frequency list
    if( !populate_list(&words, FILE_NAME) )
        return 0;

    // Sort by frequency (descending), breaking ties alphabetically
    selection_sort(&words);

    // Display results
    print_list(&words);

    return 0;
}
#endif
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION



// Function Definitions
WordFreq create_word(const char *word) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    WordFreq wf;
    strcpy(wf.word, word);
    wf.freq = 1;



    return wf;
    // TODO 1 END
}
WordList create_list(int capacity) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    WordList list;
    list.capacity = capacity;
    list.size = 0;
    return list;

    // TODO 2 END
}

WordFreq *get_word(WordList *list, const char *query) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    //Search the list to see if the word already exists
    //If found, return pointer to that WordFreq
    //If not found, return Null;
        //Use ->  in place of .*
    for(int i=0;i<list->size;i++){
            //list struct to the value of
        if(strcmp(list->words[i].word,query)==0)return list->words+i;
    }
    return NULL;



    // TODO 3 END
}

void increment_count(WordFreq *word) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    word->freq = word->freq +1;
    //(*word).freq = (*word).freq +1; same just cleaner





    // TODO 4 END
}

void add_word(WordList *list, const char *word) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    WordFreq wf = create_word(word);
    //Add to the list only if we have not excedded capacity
    if(list->size < list->capacity)list->words[list->size++] = wf;




    // TODO 5 END
}

void process_word(WordList *list, char *line) {
    // TODO: Complete this function
    // TODO 6 BEGIN
    WordFreq *wf_ptr;
    //convert the word to lowercase
    line = to_lower(line);
    //Check if the word already exists
    wf_ptr = get_word(list, line);
        //if found increment count
         if(wf_ptr!=NULL)increment_count(wf_ptr);
    //Otherwise new WordFreq entry
    else add_word(list, line);






    // TODO 6 END
}

void print_list(const WordList *list) {
    // TODO: Complete this function
    // TODO 7 BEGIN
    for(int i=0;i<list->size;i++){
        printf("%d %s\n", list->words[i].freq, list->words[i].word);
    }




    // TODO 7 END
}

int populate_list(WordList *list, const char *filename) {
    // TODO: Complete this function
    // TODO 8 BEGIN
    FILE *ifile = fopen(filename, "r");
    //check if file is opened
    if(!ifile)return 0;
    int count;
    char line[MAX_LEN];
    //scan in first number
    fscanf(ifile, "%d", &count);
    //read words one at a time
    for(int i=0;i<count && list->size < list->capacity;i++){
        //read word, ignore leading whitespace
        fscanf(ifile, "%s", line);
        //process the word
        process_word(list,line);

    }

    fclose(ifile);
    return 1;


    // TODO 8 END
}

void selection_sort(WordList *list) {
    // TODO: Complete this function
    // TODO 9 BEGIN
    //Sort array
    //Array key is descnding freq
    //Secondary key: alphabetical order
    WordFreq tmp;
    for(int i=0;i<list->size -1;i++){
        int max_idx = i;
        //search unsorted portion
        for(int j =i+1; j<list->size;j++){
            //higher freq comes first
            if(list->words[j].freq > list->words[max_idx].freq){
                max_idx = j;
            }
            //if freq tie, alphabetical order
            else if(list->words[j].freq == list->words[max_idx].freq){
                if(strcmp(list->words[j].word, list->words[max_idx].word)<0){
                    max_idx = j;
                }
            }
        }
        //swap elements
        tmp = list->words[max_idx];
        list->words[max_idx ]= list->words[i];
        list->words[i] = tmp;

    }




    // TODO 9 END
}



// Provided Helper Functions

char *to_lower(char *str) {
    // Convert a string to lowercase (in place)
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void clear_buffer(FILE *fp) {
    // Clear all characters until newline or EOF.
    int c;
    if(fp == NULL) return;

    while( (c = fgetc(fp)) != '\n' && c != EOF );
}

char *trim_string(char *str) {
    // Remove the first newline character from a string.
    int pos = strcspn(str, "\n");
    str[pos] = '\0';
    return str;
}
