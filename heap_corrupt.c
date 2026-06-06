#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("[*] Allocating chunk_A and chunk_B...\n");
    char *chunk_A = (char *)malloc(16);
    char *chunk_B = (char *)malloc(16);

    printf("[*] chunk_A: %p, chunk_B: %p\n", (void*)chunk_A, (void*)chunk_B);

    printf("[*] Corrupting chunk_B metadata via chunk_A overflow...\n");
    memset(chunk_A, 'A', 32);

    printf("[*] Attempting to free chunk_B...\n");
    free(chunk_B);

    printf("[+] Done!\n");
    free(chunk_A);
    return 0;
}
