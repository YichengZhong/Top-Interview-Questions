#include <event.h>

#include <iostream>

struct event ev;
struct timeval tv;

using namespace std;

void time_cb(int fd, short event, void *argc)
{
    cout << "timer wakeup" << endl;
    event_add(&ev, &tv);
}

int main()
{
    struct event_base *base = event_init();

    tv.tv_sec = 10;
    tv.tv_usec = 0;
    evtimer_set(&ev, time_cb, NULL);
    event_add(&ev, &tv);
    event_base_dispatch(base);

    return 0;
}
