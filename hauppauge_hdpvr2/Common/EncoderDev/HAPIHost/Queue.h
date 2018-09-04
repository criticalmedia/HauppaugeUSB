//=============================================================================
//  File Name: Queue.h
//
//  Copyright 2009 Magnum Semiconductor Inc. All rights reserved.
//
//  Description:
//      HAPI message queue definitions.
//
//  Modification History:
//      $Id: $
//      $Log: $
//
//=============================================================================

#ifndef QUEUE_H
#define QUEUE_H

typedef void * QueueHandle;
typedef void * QueueItem;
typedef int (*compareFunc)(QueueItem item, int target);

QueueHandle HAPICreateQueue(int size, const char* nameStr);
int HAPIEnQueue(QueueHandle handle, QueueItem item);
int HAPIDeQueue(QueueHandle handle, QueueItem *item );
int HAPIPeekQueue(QueueHandle handle, QueueItem *item );
int HAPISearchQueue(QueueHandle handle,QueueItem *item, compareFunc function, int target);

//int HAPIGetQueueSize(QueueHandle handle);
//int HAPIGetQueueItemCount(QueueHandle handle);
int HAPIIsQueueEmpty(QueueHandle handle);

int HAPIFlushQueue(QueueHandle handle);
int HAPIDestroyQueue(QueueHandle handle);

#endif
