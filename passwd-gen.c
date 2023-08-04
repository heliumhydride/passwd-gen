#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include "config.h"

unsigned long passwd_len;
int quantity = 1;
const char _version[] = "v2023.03.08";
unsigned long max_size = (unsigned long) -1;
// const char charset[]; is defined in config.h

void print_version() {
	printf("passwd-gen version %s\n", _version);
}

void print_help() {
	print_version();
	printf("\nUsage: passwd-gen [-v|-h] | [passwd_len quantity*]\n\n");
	printf("  -h   display this help page\n");
	printf("  -v   display this program's version\n\n");
	printf("* if not specified, quantity=1\n");
}

void error(char* str) {
	fprintf(stderr, "\033[1;31m=> %s\033[0m", str);
}

int main(int argc, char* argv[]) {
	srand(time(0));
	if(argc < 2) {
		//fprintf(stderr, "\033[31m: please specify a number of characters! (or an amount if needed)\n");
		error("please input a number of chars (w/ passwd amount if needed)\n");
		return 1;
	} else {
		int opt;
		while((opt = getopt(argc, argv, "vh")) != -1){
			switch(opt){
				case 'v':
					print_version();
					return 0;
				case 'h':
					print_help();
					return 0;
				default:
					break;
			}
		}
	}

	passwd_len = atoi(argv[1]);
	if(passwd_len >= max_size) {
		//fprintf(stderr, "password too long (passwd_len >= max_size)");
		error("password too long (passwd_len >= max_size)");
		return -1;
	}
	char password[passwd_len];

	if(argv[2]){
		quantity = atoi(argv[2]);
	}

	for(int i = 0; i <= quantity-1; i++){
		for(int j = 0; j < passwd_len; j++) {
			password[j] = charset[rand() % strlen(charset)];
		}
		password[passwd_len] = '\0';
		printf("%s\n", password);
	}
	return 0;
}

