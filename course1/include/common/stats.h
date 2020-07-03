/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Stats.h 
 * @brief Stats.h include the protoype of functions used in Stats.c
 *
 * its a header file used in assessment in Embedded systems course on Coursera
 * in ststs we make some operations on a given data set "Array in our case" to 
 * get its maximum,minimum,mean.and middle also used to sort the array and print its elements. 
 *
 * @author Mo'men Hesham
 * @date 20/6/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__



/**
 * @brief This function is used to print all elements of the array of type unsigned char
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function doesn't return anything as it print the array's elemnts to the screen
 */
void print_array(unsigned char ptr[],int length);


/**
 * @brief This function is used to get the mean of an array of type unsigned char
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function return the mean value as an unsigned char value
 */
unsigned char find_mean(unsigned char ptr[],int length);


/**
 * @brief This function is used to get the median of an array of type unsigned char
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function return the median value as an unsigned char value
 */
unsigned char find_median(unsigned char ptr[],int length);



/**
 * @brief This function is used to get the maximum of an array of type unsigned char
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function return the maximum value as an unsigned char value
 */
unsigned char find_maximum(unsigned char ptr[],int length);


/**
 * @brief This function is used to get the minimum of an array of type unsigned char
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function return the minimum value as an unsigned char value
 */
unsigned char find_minimum(unsigned char ptr[],int length);
/**
 * @brief This function is used to Sorting the array elements
 *
 * After Sorting process The biggest value will be exist at index 0 and smaalest one exists at the
 * end of the array
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function doesn't return anything as it take the array by refernce and apply the 
 *         The sorting alforithm on it without returning anything else 
*/
void sort_array(unsigned char ptr[],int length);


/**
 * @brief This function is used to print ststistics of the array to the scrren like the max,min
 *        mean, and median
 *
 * @param ptr it's represent the array pointer
 * @param length it's represent the length of the given array 
 *
 * @return This function doesn't return anything as it print the array's statistics to the screen
 */
void print_statistics(unsigned char ptr[],int length);


#endif /* __STATS_H__ */
