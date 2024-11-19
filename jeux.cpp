#include <iostream>


void verification(char* a, char* b, int n, char c);
int longeur(const char* chaine);
void assign_print(char na[100], int n);
void display(char na[100], int n);
void perdu(int n);
int compare(const char* chaine1, const char* chaine2);
int vef(const char* b, char c, int n);

int main() {
    char word1[100];  // The word to guess
    char word[100];   // The user input word (obfuscated word)
    char c;           // The user's guess
    int n;            // Length of the word
    int part = 0;     // Part of the stick man (number of wrong attempts)
    int test = false;

    std::cout << "Enter a word to be found: ";
    std::cin >> word;
    n = longeur(word);
    system("CLS");  // Clear the console
    std::cout << "________________________________\n";
    perdu(part);

    // Initialize word1 with underscores (for the guessing word)
    assign_print(word1, n);
    
    // Copy the input word into word1, initially hidden by underscores
    for (int i = 0; i < n; i++) {
        word1[i] = '_';
    }
    word1[n] = '\0';  // Null-terminate the string

    // Game loop
    while (true) {
        std::cout << "Try to guess the word\nEnter a letter that you think is present in the word: ";
        std::cin >> c;
        test = vef(word, c, n);  // Check if the letter exists in the word
        
        if (test == 0) {
            std::cout << "No such letter, try again.\n";
            std::cout << "The stick man loses a part.\n";
            part++;
            if (part == 6) {
                std::cout << "The stick man has lost all its parts. You have lost (>_<) \n";
                perdu(part);
                break;
            }
            perdu(part);
        } else {
            verification(word, word1, n, c);  // Reveal the letter in the word
            std::cout << "You have found a letter!\n";
        }

        display(word1, n);  // Display the partially guessed word
        
        // Check if the word is fully guessed
        if (compare(word, word1) == 0) {
            std::cout << "You have won (^--^) \n";
            display(word1, n);  // Show the fully guessed word
            break;
        }
    }

    return 0;
}

// Function to check if a letter is present in the word
int vef(const char* b, char c, int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] == c) {
            return 1;  // Letter is found
        }
    }
    return 0;  // Letter is not found
}

// Function to reveal the guessed letter in word1
void verification(char* a, char* b, int n, char c) {
    for (int i = 0; i < n; i++) {
        if (a[i] == c) {
            b[i] = c;  // Update the partially guessed word with the correct letter
        }
    }
}

// Function to calculate the length of the string
int longeur(const char* chaine) {
    int i = 0;
    while (chaine[i] != '\0') {
        i++;
    }
    return i;
}

// Function to assign the word with blanks and print it
void assign_print(char na[100], int n) {
    for (int i = 0; i < n; i++) {
        na[i] = '_';
    }
    na[n] = '\0';  // Null-terminate the string
    display(na, n);
}

// Function to display the word
void display(char na[100], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << na[i] << " ";
    }
    std::cout << "\n";
}

// Function to compare two strings
int compare(const char* chaine1, const char* chaine2) 
{
    int i = 0;

    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i] < chaine2[i]) {
            return -1;  // if chaine1 comes before chaine2
        }
        else if (chaine1[i] > chaine2[i]) {
            return 1;  // if chaine2 comes before chaine 
        }
        i++;//incrementation of the characters of chaine1 and 2 at index i are the same 
    }

    // If both strings are the same
    if (chaine1[i] == '\0' && chaine2[i] == '\0') 
	{
        return 0;  // Strings are equal
    }
    
    return (chaine1[i] == '\0') ? -1 : 1;
    //if (chaine[i]=='\0' is true t return 1 f false it return 1
   
}

// Function to display the stick man based on wrong attempts
void perdu(int n) {
    switch (n) {
        case 0: std::cout << "               O\n              /|\\   \n              /*\\ \n"; break;
        case 1: std::cout << "               O\n              /|\\   \n              /* \n"; break;
        case 2: std::cout << "               O\n              /|\\   \n               * \n"; break;
        case 3: std::cout << "               O\n              /|   \n"; break;
        case 4: std::cout << "               O\n               |   \n"; break;
        case 5: std::cout << "               O\n"; break;
        case 6: std::cout << "___________\n     |    \n    O|       \n    /)\\       \n    /\\        \n"; break;
    }
}
