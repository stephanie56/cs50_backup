/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // remember file names
    char* infile = argv[1];

    // open input file card.raw
    FILE* raw_file = fopen(infile, "r");
    if(raw_file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // malloc 512 bytes for one block
    char buffer[512];
    fread(buffer, 512, 1, raw_file);
    if(buffer[0] == 0xff &&
       buffer[1] == 0xd8 &&
       buffer[2] == 0xff &&
       buffer[3] & 0xf0 == 0xe0)
    {
        // found new JPEG - fwrite new file
        FILE* new_image = fopen("000.jpg", "w");
        fwrite(buffer);

    }
    else
    {
        // read next buffer
    }
}
