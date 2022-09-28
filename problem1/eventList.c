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
    Event *crntEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (crntEvent != NULL)
        {
            if (strcmp(name, crntEvent->eventName)==0)
            return crntEvent;
            crntEvent = crntEvent->next;
        }
    }
    crntEvent = NULL;
    return crntEvent;
}

void AddEvent(EventList *this, Event *event)
{    
     Event *crntEvent = this->head;
     while (crntEvent != NULL)
     {
         if(strcmp(event->eventName, crntEvent->eventName) == 0)
         {
            return;
         }
         crntEvent = crntEvent->next;
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
         Event *crntEvent = this->head->next;
         Event *lstEvent = this->head;
         if(strcmp(name, lstEvent->eventName)==0)
         {
              if(lstEvent->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(lstEvent);
              }
              else
              {
                    this->head=crntEvent;
                    DestroyEvent(lstEvent);
              }
         }
         while (crntEvent != NULL)
         {
              if(strcmp(name, crntEvent->eventName)==0)
              {
                   lstEvent->next = crntEvent->next;
                   if (this->last->next == NULL)
                   {
                        this->last = lstEvent;
                        DestroyEvent(crntEvent);
                   }
              }
              lstEvent = crntEvent;
              crntEvent = crntEvent->next;
         }
    }
}

void ListEvents(EventList *this)
{
    if (this->isEmpty == 0)
    {
        Event *crntEvent = this->head;
        while (crntEvent != NULL)
        {
            printf("%s\n", crntEvent->eventName);
            crntEvent = crntEvent->next;
        }       
    }
    else
    {
        printf("empty\n");
    }
}