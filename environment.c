#include "headers.h"


size_t get_envp_size(char **envp) {
    size_t size = 0;
    while (envp[size] != NULL) {
        size++;
    }
    return size;
}

int get_env_var_index(char **envp, const char *var_name) {
    int i = 0;
    

    while (envp[i] != NULL) {
        if (strncmp(envp[i], var_name, strlen(var_name)) == 0 && envp[i][strlen(var_name)] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

int setenv_builtin(char **args, char ***envp) {
    char *new_var;
    char **new_envp;
    if (args[1] == NULL) {
        fprintf(stderr, "setenv: missing argument\n");
        return 1;
    } else if (args[2] == NULL) {
        fprintf(stderr, "setenv: missing value\n");
        return 1;
    } else {
        int var_index = get_env_var_index(*envp, args[1]);
        if (var_index == -1) { 
            size_t envp_len = 0;
            while ((*envp)[envp_len] != NULL) {
                envp_len++;
            }
            new_envp = realloc(*envp, (envp_len + 2) * sizeof(char *));
            if (new_envp == NULL) {
                fprintf(stderr, "setenv: memory allocation error\n");
                return 1;
            }
            *envp = new_envp;

             new_var = malloc(strlen(args[1]) + strlen(args[2]) + 2);

            if (new_var == NULL) {
                fprintf(stderr, "setenv: memory allocation error\n");
                return 1;
            }
            sprintf(new_var, "%s=%s", args[1], args[2]);
            (*envp)[envp_len] = new_var;
            (*envp)[envp_len + 1] = NULL;
        } else { 
            char *new_value = malloc(strlen(args[1]) + strlen(args[2]) + 2);
            if (new_value == NULL) {
                fprintf(stderr, "setenv: memory allocation error\n");
                return 1;
            }
            sprintf(new_value, "%s=%s", args[1], args[2]);
            free((*envp)[var_index]);
            (*envp)[var_index] = new_value;
        }
        return 0;
    }
}


int unsetenv_builtin(char **args, char ***envp) {
    int i;
    if (args[1] == NULL) {
        fprintf(stderr, "unsetenv: missing argument\n");
        return 1;
    } else {
        int var_index = get_env_var_index(*envp, args[1]);
        if (var_index == -1) { 
            fprintf(stderr, "unsetenv: variable not found\n");
            return 1;
        } else {
            free((*envp)[var_index]);
           
            for (i = var_index; (*envp)[i + 1] != NULL; i++) {
                (*envp)[i] = (*envp)[i + 1];
            }

            (*envp)[get_envp_size(*envp) - 1] = NULL;

            return 0;
        }
    }
}

