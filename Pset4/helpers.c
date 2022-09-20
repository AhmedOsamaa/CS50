#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}



//FILE *f = fopen(filename, "r");
//fread(data, size, number, inptr);
//sprintf(filename, "%03i.jpg", 2);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //RGBTRIPLE temp;

            tmp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtRed = tmp;

            tmp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtBlue = tmp;

            tmp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtGreen = tmp;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imgCopy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int w = 0; w < width; w++)
        {
            imgCopy[row][w].rgbtRed = image[row][w].rgbtRed;
            imgCopy[row][w].rgbtGreen = image[row][w].rgbtGreen;
            imgCopy[row][w].rgbtBlue = image[row][w].rgbtBlue;
        }
    }
    for (int hh = 0; hh < height; hh++)
    {
        for (int ww = 0; ww < width; ww++)
        {
            //avrg(i,j, height, width,imgCopy,image);

            float avg_red = 0, avg_green = 0, avg_blue = 0, cell = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if ((hh + i) < 0 || (hh + i) >= height || (ww + j) < 0 || (ww + j) >= width)
                    {
                        continue;
                    }
                    avg_red += (imgCopy[hh + i][ww + j].rgbtRed);
                    avg_blue += (imgCopy[hh + i][ww + j].rgbtBlue);
                    avg_green += (imgCopy[hh + i][ww + j].rgbtGreen);
                    cell++;
                }
            }
            if (cell != 0)
            {
                avg_red /= cell;
                avg_blue /= cell;
                avg_green /= cell;
                image[hh][ww].rgbtRed = round(avg_red);
                image[hh][ww].rgbtBlue = round(avg_blue);
                image[hh][ww].rgbtGreen = round(avg_green);
            }
        }
    }
    return;
}

/*void avrg(int height, int width,int max_height,int max_width, RGBTRIPLE image[max_height][max_width], RGBTRIPLE image_edited[max_height][max_width])
{
    int avg_red = 0, avg_green = 0, avg_blue = 0, cell = 0;
    for(int i = -1 ; i <= 1 ; i++ )
    {
        for(int j = -1 ; j <= 1 ; j++)
        {
            if((height + i) < 0 || (height + i) > max_height || (width + j) < 0 || (width + i) > max_width)
            {
                break;
            }
            avg_red += (image[height + i][width + j].rgbtRed);
            avg_blue += (image[height + i][width + j].rgbtBlue);
            avg_green += (image[height + i][width + j].rgbtGreen);
            cell++;
        }
    }
    if(cell != 0)
    {
        avg_red/=cell;
        avg_blue/=cell;
        avg_green/=cell;
        image_edited[height][width].rgbtRed = avg_red;
        image_edited[height][width].rgbtBlue = avg_blue;
        image_edited[height][width].rgbtGreen = avg_green;
    }
    else
    {
        return;
    }
}*/

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imgCopy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int w = 0; w < width; w++)
        {
            imgCopy[row][w].rgbtRed = image[row][w].rgbtRed;
            imgCopy[row][w].rgbtGreen = image[row][w].rgbtGreen;
            imgCopy[row][w].rgbtBlue = image[row][w].rgbtBlue;
        }
    }
    for (int hh = 0; hh < height; hh++)
    {
        for (int ww = 0; ww < width; ww++)
        {
            //detect_edge(i,j, height, width,imgCopy,image);

            int Gx_red = 0, Gx_green = 0, Gx_blue = 0, Gy_red = 0, Gy_green = 0, Gy_blue = 0, cell = 0;
            int Gx_matrix[]/*[3][3]*/ = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
            int Gy_matrix[]/*[3][3]*/ = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++, cell++)
                {
                    //cell++;
                    if ((hh + i) < 0 || (hh + i) >= height || (ww + j) < 0 || (ww + j) >= width)
                    {

                        continue;
                    }
                    Gx_red += Gx_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtRed);
                    Gx_blue += Gx_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtBlue);
                    Gx_green += Gx_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtGreen);

                    Gy_red += Gy_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtRed);
                    Gy_blue += Gy_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtBlue);
                    Gy_green += Gy_matrix[cell] * (imgCopy[hh + i][ww + j].rgbtGreen);


                }
            }

            float r = sqrt((Gx_red)*Gx_red + (Gy_red)*Gy_red);
            float b = (sqrt((Gx_blue)*Gx_blue + (Gy_blue)*Gy_blue));
            float g = (sqrt((Gx_green)*Gx_green + (Gy_green)*Gy_green));
            int red = round(r);
            int green = round(g);
            int blue = round(b);
            if (red > 255)
            {
                red = 255;
            }
            /*            else if(red < 0)
                        {
                            red = 0;
                        }*/
            if (blue > 255)
            {
                blue = 255;
            }
            /*            else if(blue < 0)
                        {
                            blue = 0;
                        }*/
            if (green > 255)
            {
                green = 255;
            }
            /*            else if(green < 0)
                        {
                            green = 0;
                        }*/

            image[hh][ww].rgbtRed = red;
            image[hh][ww].rgbtBlue = blue;
            image[hh][ww].rgbtGreen = green;
        }
    }



    return;
}

/*void detect_edge(int height, int width,int max_height,int max_width, RGBTRIPLE image[max_height][max_width], RGBTRIPLE image_edited[max_height][max_width])
{
    int Gx_red = 0, Gx_green = 0, Gx_blue = 0,Gy_red = 0, Gy_green = 0, Gy_blue = 0, cell = 0;
    int Gx_matrix[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_matrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for(int i = -1 ; i <= 1 ; i++ )
    {
        for(int j = -1 ; j <= 1 ; j++)
        {
            if((height + i) < 0 || (height + i) > max_height || (width + j) < 0 || (width + i) > max_width)
            {
                break;
            }
            Gx_red += Gx_matrix[i][j] * (image[height + i][width + j].rgbtRed);
            Gx_blue += Gx_matrix[i][j] * (image[height + i][width + j].rgbtBlue);
            Gx_green += Gx_matrix[i][j] * (image[height + i][width + j].rgbtGreen);

            Gy_red += Gy_matrix[i][j] * (image[height + i][width + j].rgbtRed);
            Gy_blue += Gy_matrix[i][j] * (image[height + i][width + j].rgbtBlue);
            Gy_green += Gy_matrix[i][j] * (image[height + i][width + j].rgbtGreen);

            cell++;
        }
    }
    if(cell != 0)
    {
        //avg_red/=cell;
        //avg_blue/=cell;
        //avg_green/=cell;
        int red = round(sqrt((Gx_red)^2 + (Gy_red)^2));
        int blue = round(sqrt((Gx_blue)^2 + (Gy_blue)^2));
        int green = round(sqrt((Gx_green)^2 + (Gy_green)^2));
        if(red > 255)
        {
            red = 255;
        }
        if(blue > 255)
        {
            blue = 255;
        }
        if(green > 255)
        {
            green = 255;
        }

        image_edited[height][width].rgbtRed = red;
        image_edited[height][width].rgbtBlue = blue;
        image_edited[height][width].rgbtGreen = green;
    }
    else
    {
        return;
    }
}*/