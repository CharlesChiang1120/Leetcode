// 暴力解

bool backspaceCompare(char * s, char * t){
    int len_S = strlen(s);
    char result_S[len_S+1];
    {
        int j = 0;
        for (int i = 0; i < len_S; i++) {
            if (s[i] != '#') {
                result_S[j] = s[i];
                j++;
            } else {
                if (j > 0) {
                    j--;
                }  
            }
        }
        result_S[j] = '\0';  
    }
    
    int len_T = strlen(t);
    char result_T[len_T+1];
    {   
        int j = 0;
        for (int i = 0; i < len_T; i++) {
            if (t[i] != '#') {
                result_T[j] = t[i];
                j++;
            } else {
                if (j > 0) {
                    j--;  
                }   
            }
        }
        result_T[j] = '\0';
    }

    return strcmp(result_S, result_T) == 0;
}

// ========================================================

//Function

void process(char* result, const char* str) {
    int len_str = strlen(str);
    int j = 0;
    for (int i = 0; i < len_str; i++) {
        if (str[i] != '#') {
            result[j] = str[i];
            j++;
        } else {
            if (j > 0) {
            j--;
            }  
        }
    }
    result[j] = '\0';  
}

bool backspaceCompare(char * s, char * t){
    
    int len_S = strlen(s);
    char result_S[len_S+1];
    process(result_S, s);
    
    
    int len_T = strlen(t);
    char result_T[len_T+1];
    process(result_T, t);

    return strcmp(result_S, result_T) == 0;
}


// ========================================================

// Dynamic Programming

char* process(const char* str) {
    int len_str = strlen(str);
    char* result = malloc(sizeof(char)*(len_str+1));
    int j = 0;
    for (int i = 0; i < len_str; i++) {
        if (str[i] != '#') {
            result[j] = str[i];
            j++;
        } else {
            if (j > 0) {
            j--;
            }  
        }
    }
    result[j] = '\0';  
    return result;
}

bool backspaceCompare(char * s, char * t){
    char *result_s = process(s);
    char *result_t = process(t);
    bool areEqual = (strcmp(result_s,result_t) == 0);
    free(result_s);
    free(result_t);
    return areEqual;
}

// ========================================================
//O(n) time and O(1) space

char* process(char* str) {
    int len_str = strlen(str);
    int j = 0;
    for (int i = 0; i < len_str; i++) {
        if (str[i] != '#') {
            str[j] = str[i];
            j++;
        } else {
            if (j > 0) {
            j--;
            }  
        }
    }
    str[j] = '\0';  
    return str;
}

bool backspaceCompare(char * s, char * t){
    return strcmp( process(s),process(t)) == 0;
}




