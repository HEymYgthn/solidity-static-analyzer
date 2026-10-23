#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void tokenize_solidity(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File open error");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, sizeof(line), file)) {
        line_num++;
        
        if (line[0] == '/' || line[0] == '\n' || line[0] == '\r') continue;

        if (strstr(line, "function")) {
            printf("[TOKEN:%d] KEYWORD: function -> %s", line_num, line);
        }
        if (strstr(line, ".call{")) {
            printf("[TOKEN:%d] VULN_PATTERN: low_level_call -> %s", line_num, line);
        }
        if (strstr(line, "tx.origin")) {
            printf("[TOKEN:%d] VULN_PATTERN: tx.origin_auth -> %s", line_num, line);
        }
        if (strstr(line, "balance") || strstr(line, "balances")) {
            printf("[TOKEN:%d] STATE_VAR: balance_state -> %s", line_num, line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file.sol>\n", argv[0]);
        return 1;
    }
    tokenize_solidity(argv[1]);
    return 0;
}
