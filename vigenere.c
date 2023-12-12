#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

void cipher(const char *key, const char *msg, char *res) {
    size_t keyLen = strlen(key);
    size_t msgLen = strlen(msg);

    for (size_t i = 0, j = 0; i < msgLen; i++) {
        if (isalpha(msg[i])) {
            char base = 'A';
            res[i] = (toupper(msg[i]) - base + toupper(key[j % keyLen]) - base) % 26 + base;
            j++;
        } else {
            res[i] = msg[i];
        }
    }
    res[msgLen] = '\0';
}

void decipher(const char *key, const char *msg, char *res) {
    size_t keyLen = strlen(key);
    size_t msgLen = strlen(msg);

    for (size_t i = 0, j = 0; i < msgLen; i++) {
        if (isalpha(msg[i])) {
            char base = 'A';
            res[i] = (toupper(msg[i]) - toupper(key[j % keyLen]) + 26) % 26 + base;
            j++;
        } else {
            res[i] = msg[i];
        }
    }
    res[msgLen] = '\0';
}

int main(void) {
    const char key[] = "Penguin";
    const char msg[] = "The temperature here is equal to your grade!";
    char encrypted[100];
    char decrypted[100];

    cipher(key, msg, encrypted);
    printf("Encrypted: %s\n", encrypted);

    decipher(key, encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
