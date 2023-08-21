/**
 * @file    : queue_ds.c
 * @brief   : Queue Implementation
 * @date    : 21 AUG 2023
 * @details : This file contains the defintion of Queue DS based on array functions.
 * @author  : Ahmed Hani Atef
*/

/*************** Start of Files Includes section ***************/
#include "queue_ds.h"
/*************** Start of Files Includes section ***************/

/*********** Start of Functions Declaration section ************/

/**
 *  @brief  checks if queue is full
 *  @param  queue a pointer to the queue
 *  @retval returns a queue_ds_status_t to show its status
 */
static queue_ds_status_t queue_full(queue_ds_t *queue)
{
    queue_ds_status_t status = QUEUE_NOK;

    if (queue->max_elem == queue->elem_count)
    {
        status = QUEUE_FULL;
    }
    else
    {
    }

    return status;
}

/**
 *  @brief  checks if queue is empty
 *  @param  queue a pointer to the queue
 *  @retval returns a queue_ds_status_t to show its status
 */
static queue_ds_status_t queue_empty(queue_ds_t *queue)
{
    queue_ds_status_t status = QUEUE_NOK;

    if (ZERO == queue->elem_count)
    {
        status = QUEUE_EMPTY;
    }
    else
    {
    }

    return status;
}

/**
 *  @brief  creates a queue based on array with "size" elements in the memory
 *  @param  size variable of number of elements of the array of the queue
 *  @param  status a pointer to a variable of queue_ds_status_t to return status of the function
 *  @retval returns a pointer to the created queue in the memory
 */
queue_ds_t *create_queue(uint32_t size, queue_ds_status_t *status)
{
    queue_ds_t *queue = NULL;
    if (NULL == status)
    {
        printf("Error due to the NULL pointer !!\n");
    }
    else
    {
        queue = (queue_ds_t *)calloc(1, sizeof(queue_ds_t));
        if (NULL == queue)
        {
            *status = QUEUE_NOK;
        }
        else
        {
            queue->data = (void **)calloc(size, sizeof(void **));
            if (NULL == queue->data)
            {
                *status = QUEUE_NOK;
            }
            else
            {
                queue->elem_count = 0;
                queue->front = -1;
                queue->rear = -1;
                queue->max_elem = size;

                *status = QUEUE_OK;
            }
        }
    }
    return queue;
}

/**
 *  @brief  reallocates a new queue in memory with a new size equal to new_elem+max_element
 *  @param  queue a pointer to the queue want to be reallocated in the memory
 *  @param  new_elem variable of number of elements wanted to be added to the queue
 *  @param  status a pointer to a variable of queue_ds_status_t to return status of the function
 *  @retval returns a pointer to the reallocated queue in the memory
 */
queue_ds_t *add_elem_queue(queue_ds_t *queue, uint32_t new_elem, queue_ds_status_t *status)
{
    if (NULL == status)
    {
        printf("Error due to the NULL pointer !!\n");
    }
    else
    {
        if (NULL == queue)
        {
            *status = QUEUE_NULL_POINTER;
        }
        else
        {
            queue->data = (void **)realloc((queue->data), new_elem * sizeof(void **));
            if (NULL == queue->data)
            {
                *status = QUEUE_NULL_POINTER;
            }
            else
            {

                queue->max_elem = new_elem;

                *status = QUEUE_OK;
            }
        }
    }
    return queue;
}

/**
 *  @brief  destroys the queue in the memory to free it so it can be used again in different application
 *  @param  queue a pointer to the queue wanted to be destroyed
 *  @retval returns the status of the function
 */
queue_ds_status_t destroy_queue(queue_ds_t *queue)
{
    queue_ds_status_t status = QUEUE_NOK;
    if (NULL == queue)
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        free(queue->data);
        free(queue);
        status = QUEUE_OK;
    }
    return status;
}

/**
 *  @brief  enqueue an element to the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the element
 *  @retval returns the status of the function
 */
queue_ds_status_t enqueue(queue_ds_t *queue, void *elem)
{
    queue_ds_status_t status = QUEUE_NOK;
    if ((NULL == queue) || (NULL == elem))
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        if (queue_full(queue) == QUEUE_FULL)
        {
            status = QUEUE_FULL;
        }
        else
        {
            queue->rear++;
            if (ZERO == queue->elem_count)
            {
                queue->front = ZERO;
            }
            else if (queue->max_elem == queue->rear)
            {
                queue->rear = ZERO;
            }
            else
            { /*Nothing*/
            }
            queue->elem_count++;
            queue->data[queue->rear] = elem;
            status = QUEUE_OK;
        }
    }
    return status;
}

/**
 *  @brief  dequeue an element from the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the dequeued element
 *  @retval returns the status of the function
 */
void *dequeue(queue_ds_t *queue, queue_ds_status_t *status)
{
    void *element = NULL;
    if (NULL == status)
    {
        printf("Error due to the NULL pointer !!\n");
    }
    else
    {
        if (NULL == queue)
        {
            *status = QUEUE_NULL_POINTER;
        }
        else
        {
            if (queue_empty(queue) == QUEUE_EMPTY)
            {
                *status = QUEUE_EMPTY;
            }
            else
            {
                element = queue->data[queue->front];
                queue->elem_count--;
                queue->front++;
                *status = QUEUE_OK;
                if (ZERO == queue->elem_count)
                {
                    queue->front = -1;
                    queue->rear = -1;
                }
                else if (queue->max_elem == queue->front)
                {
                    queue->front = ZERO;
                }
                else
                { /*Nothing*/
                }
            }
        }
    }
    return element;
}

/**
 *  @brief  find the front of the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the front of the queue
 *  @retval returns the status of the function
 */
void *queue_front(queue_ds_t *queue, queue_ds_status_t *status)
{
    void *element = NULL;
    if (NULL == status)
    {
        printf("Error due to the NULL pointer !!\n");
    }
    else
    {
        if (NULL == queue)
        {
            *status = QUEUE_NULL_POINTER;
        }
        else
        {
            if (queue_empty(queue) == QUEUE_EMPTY)
            {
                *status = QUEUE_EMPTY;
            }
            else
            {
                element = queue->data[queue->front];
                *status = QUEUE_OK;
            }
        }
    }
    return element;
}

/**
 *  @brief  find the rear of the queue
 *  @param  queue a pointer to the queue
 *  @param  elem a pointer to the destination which will stores the address of the rear of the queue
 *  @retval returns the status of the function
 */
void *queue_rear(queue_ds_t *queue, queue_ds_status_t *status)
{
    void *element = NULL;
    if (NULL == status)
    {
        printf("Error due to the NULL pointer !!\n");
    }
    else
    {
        if (NULL == queue)
        {
            *status = QUEUE_NULL_POINTER;
        }
        else
        {
            if (queue_empty(queue) == QUEUE_EMPTY)
            {
                *status = QUEUE_EMPTY;
            }
            else
            {
                element = queue->data[queue->rear];
                *status = QUEUE_OK;
            }
        }
    }
    return element;
}


/************ End of Functions Declaration section *************/

/*====================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   --------------------------------------------------------------
    21 AUG 2023     Ahmed Hani Atef     Creating of queue_ds.c file and implementing all the functions

======================================================================================================*/