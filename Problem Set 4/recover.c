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
    FILE *raw_file = fopen(infile, "r");
    if(raw_file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // repeat until end of card
        // read 512 bytes into a buffer
        // malloc 512 bytes for one block
        char buffer[512];
        while(buffer.length )
        {
            fread(buffer, 1, 512, raw_file);
        }




    if(buffer[0] == 0xff &&
       buffer[1] == 0xd8 &&
       buffer[2] == 0xff &&
       buffer[3] & 0xf0 == 0xe0)
    {
        // name new image files 000.jpg
        // with sprintf %03i: set field width to 3, padding with 0
        sprintf(filename, "%03i.jpg", 0);
        FILE *image = fopen(filename, "w");

        while(){
        fwrite(buffer, 512, 1, filename);
        }

    }
    else
    {
        // read next buffer
    }
}
