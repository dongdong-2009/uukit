// a single header file is required
#include <ev.h>

#include <stdio.h> // for puts


ev_io stdin_watcher;
ev_timer timeout_watcher;


static void
stdin_cb (EV_P_ ev_io *w, int revents)
{
  puts ("stdin ready");

  ev_io_stop (EV_A_ w);


  ev_break (EV_A_ EVBREAK_ALL);
}


static void
timeout_cb (EV_P_ ev_timer *w, int revents)
{
  puts ("timeout");
 
  ev_break (EV_A_ EVBREAK_ONE);
}

int
main (void)
{
  // use the default event loop unless you have special needs
  struct ev_loop *loop = EV_DEFAULT;

  // initialise an io watcher, then start it
  // this one will watch for stdin to become readable
  ev_io_init (&stdin_watcher, stdin_cb, /*STDIN_FILENO*/ 0, EV_READ);
  ev_io_start (loop, &stdin_watcher);

  // initialise a timer watcher, then start it
  // simple non-repeating 5.5 second timeout
  ev_timer_init (&timeout_watcher, timeout_cb, 5.5, 0.);
  ev_timer_start (loop, &timeout_watcher);

  // now wait for events to arrive
  ev_run (loop, 0);

  // break was called, so exit
  return 0;
}