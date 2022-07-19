#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
	if(argc != 3){
		printf("exactly 2 arguments are required.\n");
		return 1;
	}
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
	if( f1 == NULL ){
		printf("file1 open error\n");
		return 2;
	}
	if( f2 == NULL ){
		printf("file2 open error\n");
		return 2;
	}

	uint32_t n1, n2;

	if(fread(&n1, 4, 1, f1) != 1){
		printf("file1 read error\n");
		return -1;
	}
	if(fread(&n2, 4, 1, f2) != 1) {
		printf("file2 read error\n");
		return -1;
	}

	n1 = ntohl(n1);
	n2 = ntohl(n2);

	printf("%d(%#x) + %d(%#x) = %d(%#x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
	return 0;
}

