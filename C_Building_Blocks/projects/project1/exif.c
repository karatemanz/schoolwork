#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct header{

	unsigned short appLength;	// 2 byte app1 block marker
	char exif_s[4];				// 4 byte "EXIF" string
	unsigned short nulP;		// NULL TERMINATOR 0x00
	char end[2];				// 2 endianess characters
	unsigned short version;		// 2 byte version number '42'
	int startOffset;			// 4 byte int offset

};

typedef struct tag_table { unsigned short id; char name[30]; } tag_table;

static tag_table table[13] = {
	{ 0x8769 , "Exif sub address" },
	{ 0x010f , "Manufacture:    " },
	{ 0x0110 , "Model:          " },
	{ 0x011a , "X Res/Unit:     " },
	{ 0x011b , "Y Res/Unit:     " },
	{ 0xa002 , "Width:          " },
	{ 0xa003 , "Height:         " },
	{ 0x8827 , "ISO:            " },
	{ 0x829a , "Exposure Time:  " },
	{ 0x829d , "F-stop:         " },
	{ 0x920a , "Focal Length:   " },
	{ 0x9003 , "Date Taken:     " },
	{ 0x0000 , "null"}
};

struct tiff{

	unsigned short id;		// 2 byte hex tag
	short int data_type;	// 2 byte int for data type
	int items;				// 4 byte int for number
	int offset;				// 4 byte offset value

};

int searchTag(unsigned short *id){

	struct tag_table *t;
	for(t = table; t->id != 0x0000; *t++){

		//printf("id: 0x%x\n", *id);
		//printf("&t->id: 0x%x\n", t->id);
		//printf("[%i]\n", *id == t->id);

		if(*id == t->id){
			//printf("found id: 0x%x\n", *id);
			if(*id != 0x8769){
				printf("%s", t->name);
			}else{
				//doesn't display null or exif sub block
				//strings
			}

			return 1;
		}

	}

	//printf("not found id: 0x%x\n", *id);

return 0;
}


int main(int argc, char *argv[]){

	// File initialization values
	struct header exif;
	struct tiff tag;
	unsigned short *id_ptr;
	unsigned char start[2], seek[2];
	char exif_s[4];
	unsigned short count;
	int app1Location, off, cur;
	FILE *fp = fopen(argv[1], "r");

	//tag info for output
	int rat[2], exif_off, val;
	char info[50];

	// display file name being processed
	printf("\nFile: %s\n", argv[1]);
	printf("--------------------\n\n");

	fread(&start, sizeof(unsigned char), 2, fp);
	/*printf("short unsigned int size: %lu\n", sizeof(short unsigned int));
	printf("short int size: %lu\n", sizeof(short int));
	printf("int size: %lu\n", sizeof(int));
	printf("char size: %lu\n", sizeof(char));
	printf("unsigned char size: %lu\n", sizeof(unsigned char));*/

	if(start[0] == 0xff && start[1] == 0xd8){

		//printf("trace 1 = 0x%x & 0x%x. FOUND\n", start[0], start[1]);
		
			printf("[loc  %lu]\n", ftell(fp));

	// seek the APP1 start point
	while(seek[0] != 0xff || seek[1] != 0xe1){
 		fread(&seek, sizeof(unsigned char), 2, fp);
	}

		// location of the APP1 marker
		// **-2 accounts for being 2 bytes beyond the APP1 location
		app1Location = ftell(fp)-2;

		fread(&exif, sizeof(struct header), 1, fp);
			
		if(exif.end[0] == 'I'){

			fread(&count, sizeof(unsigned short), 1, fp);
				//printf("count: %i\n\n", count);
				//printf("[loc  %lu]\n", ftell(fp));

		while(count > 0){

			fread(&tag, sizeof(struct tiff), 1, fp);

				//printf("[%i] tag id: 0x%x\n", count, tag.id);

			id_ptr = &tag.id;
			if(searchTag(id_ptr)){

				off = (app1Location + 10) + tag.offset;
				cur = ftell(fp);

				if(tag.id != 0x8769){
					if(tag.data_type == 2){

						fseek(fp, off, SEEK_SET);

						fread(&info, sizeof(char), tag.items, fp);

						printf("%s\n", info);

						fseek(fp, cur, SEEK_SET);

					}else if(tag.data_type == 4){

						fseek(fp, off, SEEK_SET);

						fread(&rat, sizeof(int), 2, fp);

						printf("%i / %i\n", rat[0], rat[1]);

						fseek(fp, cur, SEEK_SET);

					}else if(tag.data_type == 5){

						fseek(fp, off, SEEK_SET);

						fread(&val, sizeof(int), 1, fp);

						printf("%i\n",val);

						fseek(fp, cur, SEEK_SET);

					}

				}else{
					
					cur = tag.offset + (10 + app1Location);
					fseek(fp, cur, SEEK_SET);
					//printf("%i\n", ftell(fp));
					fread(&count, sizeof(unsigned short), 1, fp);

				}	
				//printf("[ 0x%x | %i | %i | %i ]\n\n", tag.id, tag.data_type, tag.items, tag.offset);

			}else{

				//printf("!!{Tag Not Supported}!!\n\n");

			}




		count--;
		}






		}else{

			printf("The endianess of the image is not supported for this exif viewer.");
			return 0;

		}

	}else{

		printf("Your current file is uncompatible with the EXIF viewer.");

	}

	fclose(fp);

return 0;	
}