
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter the filename to open: ");
    scanf("%99s", filename);

    // Try opening the file in read mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
	    perror("Error opening file.");

	    // optional : detailed custom error explanation

	    switch(errno) {
		    case ENOENT :
			    printf("Reason : The file '%s' does not exist.\n",filename);
				    break;

		    case EACCES :
		printf("Reason : permission denied for file '%s'.\n",filename);
		break;

		    case ENOTDIR:
		printf("Reason : '%s' is a directory, not a file.\n",filename);
		break;

		    case EISDIR:
		printf("Reason : '%s' is a directory, not a file.\n",filename);
		break;

		    default:
		printf("Reason : %s\n",strerror(errno));
		break;
	    }
	    return 1;
          }

      printf("File '%s' opened successfully!\n",filename);

      fclose(fp);
      return 0;
}
