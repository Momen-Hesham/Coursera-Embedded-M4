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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move memory elemnts from src to dst 
 *
 * this function move memory elemnts with saving the value of the src even if the both src &dst are overlapped
 * @param src Pointer to the source memory
 * @param dst Pointer to the destination memory
 * @param length The length of the memory elements needed to be moved
 *
 * @return Pointer to destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy memory elemnts from src to dst 
 *
 * this function copy memory elemnts without saving the value of the src so its not the best function if the dst and src are overlapped 
 * @param src Pointer to the source memory
 * @param dst Pointer to the destination memory
 * @param length The length of the memory elements needed to be copied
 *
 * @return Pointer to destination.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set memory elemnts to a specific value 
 *
 * This function is used to Set the input memory elements to a certain value 
 * @param src Pointer to the source memory
 * @param value The value which is wanted to be assigned to all elements of the input memory
 * @param length The length of the memory elements needed to be set
 *
 * @return Pointer to Input memory elememts.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Set memory elemnts to Zero
 *
 * This function is used to Set the input memory elements to Zero 
 * @param src Pointer to the source memory.
 * @param length The length of the memory elements needed to be set
 *
 * @return Pointer to Input memory elememts.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the Memory elemnts
 *
 * This function is used to reverse the memory elements So the value at last index become the first element in the memory
 * @param src Pointer to the source memory
 * @param length The length of the memory elements needed to be reversed.
 *
 * @return Pointer to Input memory elememts.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserve Amount of memory its elements length is equal to word size
 *
 * This function is used to reserve specific amout of memory elements each element length is equal to the word length which is 32bit. 
 * @param length The length of the memory elements needed to be reserved.
 *
 * @return Pointer to reserved memory elements.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free or Deallocate Amount of memory its elements length is equal to word size
 *
 * This function is used to free input memory elements each element length is equal to the word length which is 32bit. 
 * @param src Pointer to the memory needed to be free.
 *
 * @return Void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
