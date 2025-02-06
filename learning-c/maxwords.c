int mostWordsFound(char** sentences, int sentencesSize) {
    int best = 0;
    for (int i = 0; i < sentencesSize; i++){
        int local_best = 0;
        char* newString = sentences[i];
        for (int j = 0; j < strlen(newString); j++){
            char current = newString[j];
            if (current == ' '){
                local_best++;
            }
        }
        local_best++;
        if (best < local_best){
            best = local_best;
        }
    }
    return best;
}
