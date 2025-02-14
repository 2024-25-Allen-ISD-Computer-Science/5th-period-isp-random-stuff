#include "stdio.h"
#include "string.h"

int main() {
	char* css = "header{ main: hello; main2: hola; } header2{ main3: como; main4: estas; }";

	// loop through each char in the string
	for (int i = 0; css[i] != '\0'; i++) {
    	// header checking
    	if (css[i] != ' ' && css[i] != '{' && css[i] != '}' && css[i] != ':' && css[i] != ';') {
        	int start = i;
        	while (css[i] != '{' && css[i] != ' ' && css[i] != '\0') {
            	i++;
        	}
        	char header[50];
        	strncpy(header, &css[start], i - start);
        	header[i - start] = '\0'; // end the string
        	printf("header: %s\n", header);
    	}
   	 
    	// skip '{' after the header
    	if (css[i] == '{') {
        	continue;
    	}


    	// get the property name
    	if (css[i] != ' ' && css[i] != ':' && css[i] != ';') {
        	int start = i;
        	while (css[i] != ':' && css[i] != ' ' && css[i] != ';' && css[i] != '\0') {
            	i++;
        	}
        	char property[50];
        	strncpy(property, &css[start], i - start);
        	property[i - start] = '\0'; // end the string
        	printf("property: %s\n", property);
    	}

    	// skip ':'
    	if (css[i] == ':') {
        	i++;
    	}

    	// get the value
    	if (css[i] != ' ' && css[i] != ';' && css[i] != '\0') {
        	int start = i;
        	while (css[i] != ';' && css[i] != '}' && css[i] != '\0') {
            	i++;
        	}
        	char value[50];
        	strncpy(value, &css[start], i - start);
        	value[i - start] = '\0'; // end the string
        	printf("value: %s\n", value);
    	}

    	// skip '}' at the end
    	if (css[i] == '}') {
        	continue;
    	}
	}

	return 0;
}





