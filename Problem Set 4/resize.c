/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Created large.bmp out of small.bmp
 * by resizing the latter by a factor of n (i.e., by multiplying both its width and its height by n
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // factor
    int n;

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // convert argument string to an int n
    n = atoi(argv[1]);
    if (n < 0 || n > 100)
    {
        printf("Usage: n must be a postive number, equal to or smaller than 100");
        return 2;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file (at this point outptr can write only - cannot read from outptr)
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);


    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int inptr_biWidth = bi.biWidth;
    int inptr_biHeight = bi.biHeight;
    int inptr_padding =  (4 - (inptr_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // resized width and height
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;
    int new_biWidth = bi.biWidth;
    int new_biHeight = bi.biHeight;

     // resized padding for scanlines
    int outptr_padding = (4 - (new_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update header info
    bi.biSizeImage = new_biWidth * abs(new_biHeight) * sizeof(RGBTRIPLE) + outptr_padding * abs(new_biHeight);
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // for each infile row
        // for each pixel
            // write to array n times
        // for n times
            // write array to outfile
            // write outfile padding
        // skip over infile paading

    // repeat next row


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inptr_biHeight); i < biHeight; i++)
    {
        RGBTRIPLE triple;

         for(int copyScanline = 0; copyScanline < n; copyScanline++) {

          // iterate each pixel of line j from infile
          for(int j = 0; j < inptr_biWidth; j++)
          {
              // read each pixel from infile
              fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

              // fwrite n time of pixel to outfile
              for(int k = 0; k < n; k++)
              {
                  fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
              }

          }

            // outfile scanline add padding
            for(int l = 0; l < outptr_padding; l++)
            {
                fputc(0x00, outptr);
            }

        if(copyScanline != (n-1)){
          // infile line back to beginning
          fseek(inptr, -(inptr_biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }

     }

      // infile scanline skip padding
        fseek(inptr, inptr_padding, SEEK_CUR);

    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
