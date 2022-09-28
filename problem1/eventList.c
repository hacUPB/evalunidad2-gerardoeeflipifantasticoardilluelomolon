#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 1;
    return eventList;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *createEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (createEvent != NULL)
        {
            if (strcmp(name, createEvent->eventName)==0)
                return createEvent;
            createEvent = createEvent->next;
        }
    }
    createEvent = NULL;
    return createEvent;
}

void AddEvent(EventList *this, Event *event)
{    
     Event *createEvent = this->head;
     while (createEvent != NULL)
     {
         if(strcmp(event->eventName, createEvent->eventName) == 0)
         {
            return;
         }
         createEvent = createEvent->next;
     }

     if(this->isEmpty == 0)
     {
          this->last->next = event;
          this->last=event;
     }
     else
     {
         this->head = event;
         this->last = event;
         this->isEmpty = 0;    
     }
}

void RemoveEvent(EventList *this, char *name)
{
    if (this->isEmpty == 0)
    {
         Event *createEvent = this->head->next;
         Event *lastEvent = this->head;
         if(strcmp(name, lastEvent->eventName)==0)
         {
              if(lastEvent->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(lastEvent);
              }
              else
              {
                    this->head=createEvent;
                    DestroyEvent(lastEvent);
              }
         }
         while (createEvent != NULL)
         {
              if(strcmp(name, createEvent->eventName)==0)
              {
                   lastEvent->next = createEvent->next;
                   if (this->last->next == NULL)
                   {
                        this->last = lastEvent;
                        DestroyEvent(createEvent);
                   }
              }
              lastEvent = createEvent;
              createEvent = createEvent->next;
         }
    }
}


