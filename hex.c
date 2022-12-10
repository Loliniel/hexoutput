/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Lydia
 *
 * Created on April 9, 2021, 12:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


#define BOOL			uint8_t
#define TRUE			0xFF
#define FALSE			0x00


uint8_t printHexView(uint8_t *buf, size_t sz) {
	size_t		modulo;
	uint32_t	rows;
	uint8_t		*line;
	uint32_t	i, j;
	
	if(buf == NULL) {
		return 0;
	}
	
	modulo	= sz%16;
	rows		= (uint32_t)(sz/16);
	
	printf("\nAddress\t 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F Dump\n");
	
	line = (uint8_t*)malloc(sizeof(uint8_t)*16);
	for(i=0; i<rows; i++) {
		memcpy(line, buf+(16*i), 16);
		printf("%08X ", i*16);
		
		for(j=0; j<16; j++) {
			printf("%02X ", line[j]);
		}

		for(j=0; j<16; j++) {
			if(line[j] < 0x1F) {
				printf(".");
			} else {
				printf("%c", line[j]);
			}
		}
		
		printf("\n");
	}
	
	if(modulo > 0) {
		line = (uint8_t *)malloc(sizeof(uint8_t)*modulo);

		if((i*16)<=sz) {
			memcpy(line, buf+(16*i), modulo);
			printf("%08X ", i*16);
			
			for(j=0; j<modulo; j++) {
				printf("%02X ", line[j]);
			}

			for(; j<16; j++) {
				printf("   ");
			}

			for(j=0; j<modulo; j++) {
				if(line[j] < 0x1F) {
					printf(".");
				} else {
					printf("%c", line[j]);
				}
			}
		}
		
		printf("\n");
	}
	
	/*
	Debug? Stuff
	
	printf("\n\nFile size\t\t\t= 0x%04zX\t%04zd\n", sz, sz);
	printf("Number of 16 byte blocks\t= 0x%04zX\t%04zd\n", (sz/0x0F), (sz/0x0F));
	printf("Left over bytes\t\t\t= 0x%04zX\t%04zd\n", sz%0x0F, sz%0x0F);
	*/
	
	return 1;
}


/*
 *   main of course
 */
int main(int argc, char** argv) {
	FILE			*fp;
	char			*filename;
	size_t		sz, hashlength;
	uint8_t		*b;
	uint8_t		*hash;
	uint32_t	opt;
	//BOOL			print, verbose;
	
	
	hashlength = 128;
	//print = FALSE;
	
	if(argc == 1) {
		printf("Usage: %s [-fh] [file ...]\n", argv[0]);
		return 1;
	}
	
	while((opt = getopt(argc, argv, "f:pvh")) != -1) {
		switch(opt) {
			case 'f':
				filename = (char *)malloc(sizeof(char)*strlen(optarg));
				strcpy(filename, optarg);
				break;
			case 'h':
			default:
				printf("Usage: %s [-fh] [file ...]\n", argv[0]);
				printf("-f\tFilename\n-h\tHelp\n");
				return 0;
				break;
		}
	}
	
	if((fp = fopen(filename, "r"))==NULL) {
		printf("Error opening file.\n");
		return 0;
	}
	
	fseek(fp, 0, SEEK_END);
	sz = ftell(fp);
	rewind(fp);
	
	/*if(verbose==TRUE) {
		printf("File name\t\t\t= %s\n", filename);
		printf("File size\t\t\t= 0x%04zX\t%04zd\n", sz, sz);
		printf("Number of 16 byte blocks\t= 0x%04zX\t%04zd\n", (sz/0x0F), (sz/0x0F));
		printf("Left over bytes\t\t\t= 0x%04zX\t%04zd\n", sz%0x0F, sz%0x0F);
		
	}*/
	
	if((b = (uint8_t *)malloc(sizeof(uint8_t)*sz)) == NULL) {
		printf("Error allocating %zu bytes.\n", sz);
		fclose(fp);
		return 1;
	}
	
	if((hash = (uint8_t *)malloc(sizeof(uint8_t)*128)) == NULL) {
		printf("Error allocating %zu bytes.\n", hashlength);
		fclose(fp);
		return 1;
	}
	
	if(fread(b, 1, sz, fp) != sz) {
		printf("Error reading file.\n");
		fclose(fp);
		return 0;
	}
	
	//if(print == TRUE) {
	printHexView(b, sz);
	//}
	
	fclose(fp);
	return (EXIT_SUCCESS);
}