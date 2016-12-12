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
    int inptr_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // resized width and height
    newbiWidth = n * bi.biWidth;
    newbiHeight = n * bi.biHeight;

     // resized padding for scanlines
    int outptr_padding = (4 - (newbiWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update header info
    bi.biSizeImage = newbiWidth * abs(newbiHeight) * sizeof(RGBTRIPLE) + outptr_padding * abs(newbiHeight);
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



    // for each infile row
    for(int i = 0, biHeight = abs(newbiHeight); i < biHeight; i++)
    {

        //RGBTRIPLE triple;
        RGBTRIPLE triple_arr[bi.biWidth * n];

        // for each pixel
        for(int j = 0; j < bi.biWidth; j++)
        {

            // write to array n times
            for(int k = 0; k < n; k++)
            {
                fread(&triple_arr[0], sizeof(RGBTRIPLE), 1, inptr);
            }


        }



        // for n times
        for(int l = 0; l < n; l++)
        {
            fwrite(triple_arr, sizeof(RGBTRIPLE), 1, outptr);
            for(int m = 0; m < outptr_padding; m++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over infile paading
        fseek(inptr, inptr_padding, SEEK_CUR);

    }



    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);



    // that's all folks
    return 0;
}



   /**

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        RGBTRIPLE triple;

      // iterate each pixel of line 1 from infile
      for(int j = 0; j < bi.biWidth; j++)
      {

          // read each pixel from infile
          fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

          // fwrite n time of pixel 1 to outfile
          for(int k = 0; k < n; k++)
          {
              fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
          }

      }

    // infile skip line 1 padding
    fseek(inptr, inptr_padding, SEEK_CUR);


    // outfile cursor jump back to beginning of scanline
    fseek(outptr, n * bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);

    // fread the whole scanline from outfile
    fread(&triple, sizeof(RGBTRIPLE), n * bi.biWidth, outptr);

    // outfile scanline 1 add padding
    for(int l = 0; l < outptr_padding; l++)
    {
        fputc(0x00, outptr);
    }

    // fwrite n-1 time of scanline 1
    for(int m = 1; m < n; m++)
    {
        fwrite(&triple, sizeof(RGBTRIPLE), n * bi.biWidth, outptr);

        // outfile add padding
        for(int l = 0; l < outptr_padding; l++){

            fputc(0x00, outptr);

        }

    }


    } // iterate each line (bi.Height) of scanline


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

**/








    
