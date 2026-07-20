#ifndef EVENTS_H
#define EVENTS_H

void attachEvent(void (*userFunc)(void), int interval);

void startEvents();

#endif