#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_command_type(const char *command){
    if(strncmp(command, "git add", 7) == 0)
        return 0;
    if(strncmp(command, "git commit", 10) == 0)
        return 1;
    if(strncmp(command, "git log", 7) == 0)
        return 2;
    
    return -1;
}

int is_valid_commit_message(const char *message){
    int len = strlen(message);
    if(len < 1 || len > 20)
        return 0;
    return 1;
}

int parse_filenames(char *filenames, char *result[]){
    int cnt = 0, curIdx = 0, file_len = strlen(filenames);
    result[cnt] = (char *)malloc(sizeof(char) * 16);
    for(int i = 0;i < file_len;i++){
        if(filenames[i] == ' '){
            result[cnt][curIdx] = '\0';
            cnt += 1;
            result[cnt] = (char *)malloc(sizeof(char) * 16);
            curIdx = 0;
        } else{
            result[cnt][curIdx] = filenames[i];
            curIdx += 1;
        }
    }
    result[cnt][curIdx] = '\0';
    cnt += 1;
    return cnt;
}

void get_short_commit_id(const char *hex, char *result){
    strncpy(result, hex, 7);
    result[7] = '\0';
}

void generate_commit_message(const char *type, const char *message, char *result){
    int origin_len = strlen(result);
    for(int i = 0;i < origin_len;i++)
        result[i] = '\0';

    if(strcmp(type, "feat") != 0 && strcmp(type, "fix") != 0 && strcmp(type, "docs") != 0){
        strcat(result, "chore");
        result[5] = '\0';
    }
    else{
        strcat(result, type);
        result[strlen(type)] = '\0';
    }
    origin_len = strlen(result);
    strcat(result, ": ");
    origin_len += 2;
    result[origin_len] = '\0';
    int message_len = strlen(message);
    strcat(result, message);
    origin_len += message_len;
    result[origin_len] = '\0';
}