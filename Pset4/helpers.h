#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

//void avrg(int height, int width, int max_height, int max_width, RGBTRIPLE image[height][width], RGBTRIPLE image_edited[height][width]);

//void detect_edge(int height, int width,int max_height,int max_width, RGBTRIPLE image[max_height][max_width], RGBTRIPLE image_edited[max_height][max_width]);
