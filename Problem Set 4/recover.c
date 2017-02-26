/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // remember file names
    char *infile = argv[1];

    // open input file card.raw
    FILE *raw = fopen(infile, "r");
    FILE *image;

    if(raw == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];
    char filename[8];

    // check each block of 512 bytes
    int counter = 0;

    while(fread(buffer, 512, 1, raw) == 1)
    {
       if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
       {
           if(counter != 0){
               fclose(image);
           }

           sprintf(filename, "%03i.jpg", counter);
           image = fopen(filename, "w");
           fwrite(buffer, 512, 1, image);
           counter++;
       }

       else if (counter != 0)
       {
           fwrite(buffer, 512, 1, image);
       }
    }


    fclose(raw);

}
