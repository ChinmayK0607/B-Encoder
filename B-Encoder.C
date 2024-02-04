#include <stdio.h>
#include <stdlib.h>
#include<string.h>



// define structures for pair

typedef struct StringPair{
    char s[100];
    int length;
}StringPair;

int readInt(char*s,int ans,int index){
    int retval = -1;
    if(s[index]=='i'){
        retval = readInt(s,ans,index+1);
    }
    else if(s[index] >='1' && s[index] <='9'){
        ans = ans * 10 + (s[index]-'0');
        retval = readInt(s,ans,index+1);
    }
    else{
        retval = ans;
    }
    return retval;
}

void readString(char *s, int index, StringPair *p) {
    if (s[index] == 'e') {
        return;
    }

    if (s[index] >= '0' && s[index] <= '9') {
        p->length = s[index] - '0';
    } else {
        return; // Invalid character, terminate the function
    }

    if (s[index + 1] == ':') {
        index += 2; // Move past the ':'

        // Clear the string in the StringPair before appending characters
        p->s[0] = '\0';

        // Append characters to the string
        for (int i = 0; i < p->length; i++) {
            strncat(p->s, &s[index + i], 1); // Use strncat to append one character at a time
        }

        // Move the index to the next position after the read string
        index += p->length;
    }

    readString(s, index, p);
}


int main() {
    // Allocate memory for the string
    char s[100];  // Adjust the size based on your needs
    StringPair P;
    // Read input into the string
    scanf("%s", s);

    // Print the string
    printf("%s\n", s);
   // int ans = readInt(s,0,0);
    //printf("%d\n",ans);
    readString(s,0,&P);
    printf("string is %s and its length is %d",P.s,P.length);
    return 0;
}
