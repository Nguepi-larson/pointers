#include <iostream>


//function prototype 
int longeur(const char* chaine);
void inverse(char* chaine);
char* cherche_mot(const char* phrase,const char* mot);
void to_upper(char* chaine);
void to_lower(char* chaine);
char* cherche_char(const char* chaine ,char caractere);
int compare(const char* chaine1,const char* chaine2);
void concatene(char* dest,const char* source);//add source to the end of dest
void copie(char* dest,const char* source);//copy the content of source to dest
void sous_chaine(const char* source,char* dest,int debut,int longeur);
void supprime_caractere(char* chaine,char caractere);
int compte_mots(const char *phrase);
//main function .........
int main(int argc, char** argv) 
{
//variable that will be used in the program 
	int value=0;
	int num;
	int option;//to get the option of an operation 
	char word[100];
	char word1[100];
	char c;
	const char*  m=word;
	char* n=word1;
//possible option that the user can perform	
    std::cout<<"Choose an option \n";
	std::cout<<"1.Get the length of a word\n2.Copy  a string to another one\n3.Join 2 string\n4.Determine which one comes before the other\n";
	std::cout<<"5.Search for a character in a string\n6.Inverse a word\n7.Upper case to lower case \n8.Lower case to upper case\n9.Found a word in a sentence \n";
	std::cout<<"10.Extraction  of a sub string\n11.Removing a  character  in a giving   sting\n12.Get the num word in  a sentence\n";
	std::cout<<"Enter the option(1-12) :";
	std::cin>>option;
	
	switch(option)
	{
		case 1://longeur()
		{
			std::cout<<"enter a word \n";
	        std::cin>>word;
	        value=longeur(m);
	        std::cout<<"the lenght of the words is "<<value;

		}break;
		
		case 2:// copie()
		{
			std::cout<<"enter the word to be copy in the string \n";
			std::cin>>word;
			copie(n,m);
			
		}break;
		
		case 3://concatene()
		{
			std::cout<<"enter two words \n";
			std::cin>>word1>>word;
			std::cout<<"the joint word is ";
			concatene(n,m);
			std::cout<<n;
			
		}break;
		
		case 4://compare()
		{
			std::cout<<"enter two words \n";
			std::cin>>word1>>word;
			if(compare(n,m)==1)
			{
				std::cout<<n<<" comes before "<<m;
			}
			else if(compare(n,m)==-1)
			{
				std::cout<<m<<" comes before "<<n;
			}
			else
			{
				std::cout<<"the words are the same";
			}
			
		}break;
		
		case 5://cherche_char()
		{
			
			
		}break;
		
		case 6://inverse()
		{
			std::cout<<"enter the word you want to reverse\n";
			std::cin>>word1;
			inverse(n);
			std::cout<<n;
			break;
		}
		
		case 7://to_lower()
		{
			std::cout<<"enter the word you want to bring to lower case\n";
			std::cin>>word1;
			to_lower(n);
			std::cout<<n;
		}break;
		
		case 8://to_upper()
		{
		    std::cout<<"enter the word you want to bring to upper case\n";
			std::cin>>word1;
			to_upper(n);
			std::cout<<n;
			
			
		}break;
		
		case 9://cherche_mot()
		{
			std::cout<<"enter a sentence \n";
			//std::cin>>//////////
			std::cout<<"enter a word \n";			
		}break;
		
		case 10://sous_chaine()
		{
			
			std::cout<<"enter a string \n";
			std::cin>>word;
			std::cout<<"enter a starting point for the extraction\n";
			std::cin>>num;
			if(num<(longeur(m)-1)){
			sous_chaine(m,n,(num-1),longeur(m));
			std::cout<<n;
		    }
		    else
			{
				std::cout<<"we cant take this starting point \n";
			}
			
			break;
		}
		
		case 11://supprime_caractere()
		{
			std::cout<<"enter a word \n";
			std::cin>>word1;
			std::cout<<"enter a caracter you want to delete : ";
			std::cin>>c;
			supprime_caractere(n,c);
			std::cout<<word1;
			
			break;
		}
		
		case 12://compte_mots(m)
		{
			std::cout<<"Enter a sentence :\n";
			std::cin>>word;
			std::cout<<"the number of words in the sentences is "<<compte_mots(m);
			break;
		}
		
		default :
		{
			std::cout<<"Wrong input\n";
			break;
		} 
	
    }
	return 0;
}


// function implementation 
void to_upper(char* chaine)
{
	int n=longeur(chaine);
	int i;
	for(i=0;i<n;i++)
	{
		if(chaine[i]>='a' && chaine[i]<='z')
		{
			chaine[i]=chaine[i]-32;
		}
     }
	
}

void to_lower(char* chaine)
{
	int n=longeur(chaine);
	int i;
	for(i=0;i<n;i++)
	{
		if(chaine[i]>='A' && chaine[i]<='Z')
		{
			chaine[i]=chaine[i]+32;//converting to lower character using 32 (from ASCII)
		}
     }
	 	
}                   
	 
void inverse(char* chaine)
{
	int i;
	char m[100];//declerain a character to store the reverse 
	int n=longeur(chaine);
	for(i=0;i<n;i++)
	{
		m[i]=chaine[n-(i+1)];//n-(1+i) calculating the index of the last element ,the before last and so on
	}
	
	for(i=0;i<n;i++)
	{
		chaine[i]=m[i];//assigning back those element back to chaine 
	}
}


void copie(char* dest,const char* source)
{
	int i=0;
	int n=longeur(source);
	
	for(i=0;i<n;i++)
	{
		dest[i]=source[i];//just making assigment of source of index i to dest of same index
	}
	
}
//a problem may arise base on the size of dest if too smalll
void concatene(char* dest,const char* source)
{
	int i;
	int n,m;
	n=longeur(dest);
	m=longeur(source);
	int j=0;
	for(i=n;i<(m+n);i++)//ending at the end of the sumof length of the two string 
	{
		if(j<m)
		{
		dest[i]=source[j];//assigninh as from the ennd of the string of dest
		j++;
	    }
	}
	
}

void supprime_caractere(char* chaine,char caractere)
{
	int i,j;//to performe interation
	int n=longeur(chaine);
	for(i=0;i<n;i++)
	{
		if(chaine[i]==caractere)//if a character that if to de leleted is found 
		{
			for(j=i;j<n;j++)
			{
				chaine[j]=chaine[j+1];//then we assgned the next character to the character at that ndex and we do so for the next charaters of the string
			}
		}
	}
	
}

int longeur(const char* chaine)
{
	int i=0;
	while(chaine[i] != '\0')//looping tll we meet the null character 
	{
		i++;
	}
	return i;//returning the last ndex
}

void sous_chaine(const char* source,char* dest,int debut,int longeur)
{
	int i;// for the loop of source 
	int j=0;//for the loop of dest
	//starting the loop as for ndex debut to the last ndesk
	for(i=debut,j=0;i<=longeur;i++,j++)
	{
		dest[j]=source[i];//assigning element of sorce to dest
	}
}

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


//***********************************************************************************************************

char* cherche_char(const char* chaine ,char caractere)
{
	return nullptr;
}


char* cherche_mot(const char* phrase,const char* mot)
{
	
	
	return nullptr;
} 

/*
int compte_mots(const char *phrase) {
    int i = 0;
    int c = 0;

    while (phrase[i] != '\0') 
	{

		 if((phrase[i]>=65 && phrase[i]<=90) ||(phrase[i]>=97 && phrase[i]<=122) )
		{
			c++;
			while((phrase[i]>=65 && phrase[i]<=90) ||(phrase[i]>=97 && phrase[i]<=122))
			{
				i++;
			}
		}
		else
		{
		i++;	
		}	
    }

    return c;
}

*/
int compte_mots(const char *phrase) {
    int i = 0;
    int c = 0;

    // Skip any leading spaces
    while (phrase[i] == 32) {
        i++;
    }

    while (phrase[i] != '\0') {
        // If we encounter a letter (alphabetic character), it's part of a word
        if ((phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122)) {
            c++;  // Start a new word
            // Skip over the entire word
            while ((phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122)) {
                i++;  // Move to the next character
            }
        } else {
            // If the character is a space, just skip it
            i++;
        }
        
        // Skip any additional spaces between words
        while (phrase[i] == 32) {
            i++;
        }
    }

    return c;
}


