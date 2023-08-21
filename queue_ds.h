/**
 * @file    : queue_ds.h
 * @brief   : Queue Implementation
 * @date    : 21 AUG 2023
 * @details : This file contains the declaration of Queue DS based on array.
 * @author  : Ahmed Hani Atef
*/

#ifndef QUEUE_DS_H
#define QUEUE_DS_H

/************** Start of Library Includes section **************/
#include <stdlib.h>
#include <stdio.h>
/************** End of Library Includes section ****************/

/*************** Start of Files Includes section ***************/
#include "platform_types.h"
/*************** End of Files Includes section *****************/

/******************* Start of Types section ********************/
typedef enum queue_check
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NOT_FULL,
    QUEUE_NULL_POINTER
} queue_ds_status_t;

typedef struct queue_ds
{
    void **data;
    sint32_t front;
    sint32_t rear;
    uint32_t max_elem;
    uint32_t elem_count;
} queue_ds_t;
/******************** End of Types section *********************/

/*********** Start of Functions Declaration section ************/

/**
 *  @brief  creates a queue based on array with "size" elements in the memory
 *  @param  size variable of number of elements of the array of the queue
 *  @param  status a pointer to a variable of queue_ds_status_t to return status of the function
 *  @retval returns a pointer to the created queue in the memory
 */
queue_ds_t *create_queue(uint32_t size, queue_ds_status_t *status);

/**
 *  @brief  reallocates a new queue in memory with a new size equal to new_elem+max_element
 *  @param  new_elem variable of number of elements wanted to be added to the queue
 *  @param  status a pointer to a variable of queue_ds_status_t to return status of the function
 *  @retval returns a pointer to the reallocated queue in the memory
 */
queue_ds_t *add_elem_queue(queue_ds_t *queue, uint32_t new_elem, queue_ds_status_t *status);

/**
 *  @brief  destroys the queue in the memory to free it so it can be used again in different application
 *  @param  queue a pointer to the queue wanted to be destroyed
 *  @retval returns the status of the function
 */
queue_ds_status_t destroy_queue(queue_ds_t *queue);

/**
 *  @brief  enqueue an element to the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the element  
 *  @retval returns the status of the function
 */
queue_ds_status_t enqueue(queue_ds_t *queue , void *elem);

/**
 *  @brief  dequeue an element from the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the dequeued element  
 *  @retval returns the status of the function
 */
void *dequeue(queue_ds_t *queue , queue_ds_status_t *status);

/**
 *  @brief  find the front of the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the front of the queue 
 *  @retval returns the status of the function
 */
void *queue_front(queue_ds_t *queue , queue_ds_status_t *status);

/**
 *  @brief  find the rear of the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the rear of the queue 
 *  @retval returns the status of the function
 */
void *queue_rear(queue_ds_t *queue , queue_ds_status_t *status);

/************ End of Functions Declaration section *************/

#endif //QUEUE_DS_H

/*==========================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   --------------------------------------------------------------------
    21 AUG 2023     Ahmed Hani Atef     Creating of queue_ds.h file and writing the definitions of functions

============================================================================================================*/