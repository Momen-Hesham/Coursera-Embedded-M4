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
 * @file Stats.c
 * @brief This code is used to get some statistics of giiven array of unsigned char like: its max,
 *        min,mean, and median.it also used to print all the elements of that array and sort it. 
 * 
 * This file is included as a part of assement in Embedded systems software development Course
 * at Coursera.
 *
 * @author Mo'men Hesham
 * @date 20/6/2020
 *
 */


#include <stdint.h>
#include <stdio.h>
#include "../include/common/platform.h"
#include "../include/common/stats.h"
#include <stdlib.h>
/* Size of the Data Set */
#define SIZE (40)


void print_array(unsigned char ptr[],int length)
{
	for(int i=0;i<length;i++)
	{
		PRINTF("%d : %d \n",(i+1),*(ptr+i));
	}
}

unsigned char find_mean(unsigned char ptr[],int length)
{
	int Sum=0;
	for(int i=0;i<length;i++)
		Sum=Sum+ptr[i];
	return (unsigned char)(Sum/length);
}

unsigned char find_median(unsigned char ptr[],int length)
{
	unsigned char *temp_arr;
	temp_arr=(unsigned char *)(malloc(length*sizeof(unsigned char)));
	if(temp_arr==NULL)
	{
		printf("Memory can't be allocated");
		return 0;
	}	

	for(int i=0;i<length;i++)
		temp_arr[i]=ptr[i];
	sort_array(temp_arr,length);
	
	if((length%2)==1)
	{
		unsigned char temp=temp_arr[(length/2)];
		free(temp_arr);
		return temp;
	}
	else
	{
		unsigned char temp=temp_arr[(length/2)]+temp_arr[(length/2)-1] ;
		free(temp_arr);
		return temp/2;
	}

}


unsigned char find_maximum(unsigned char ptr[],int length)
{
	unsigned char max=ptr[0];
	for(int i=1;i<length;i++)
		if(ptr[i]>max)
			max=ptr[i];

	return max;
}

unsigned char find_minimum(unsigned char ptr[],int length)
{
	unsigned char min=ptr[0];
	for(int i=1;i<length;i++)
		if(ptr[i]<min)
			min=ptr[i];

	return min;
}

void print_statistics(unsigned char ptr[],int length)
{
	unsigned char max,min,mean,median;
	max=find_maximum(ptr,length);
	min=find_minimum(ptr,length);
	mean=find_mean(ptr,length);
	median=find_median(ptr,length);
	printf("The Maximum of The Array equal = %d \n",max);
	printf("The Minimum of The Array equal = %d \n",min);
	printf("The Mean of The Array equal = %d \n",mean);
	printf("The Median of The Array equal = %d \n",median);
}

void sort_array(unsigned char ptr[],int length)
{
	for(int i=0;i<length;i++)
	{
		int max_index=i;
		unsigned char max=ptr[i];
		for(int j=i+1;j<length;j++)
		{
			if(ptr[j]>max)
			{
				max=ptr[j];
				max_index=j;
			}
		}
		unsigned char temp=ptr[max_index];
		ptr[max_index]=ptr[i];
		ptr[i]=temp;
	}
}

