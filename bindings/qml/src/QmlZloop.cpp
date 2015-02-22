/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZloop.h"


///
//  Register socket reader with the reactor. When the reader has messages, 
//  the reactor will call the handler, passing the arg. Returns 0 if OK, -1
//  if there was an error. If you register the same socket more than once, 
//  each instance will invoke its corresponding handler.                   
int QmlZloop::reader (zsock_t *sock, zloop_reader_fn handler, void *arg) {
    return zloop_reader (self, sock, handler, arg);
};

///
//  Cancel a socket reader from the reactor. If multiple readers exist for
//  same socket, cancels ALL of them.                                     
void QmlZloop::readerEnd (zsock_t *sock) {
    zloop_reader_end (self, sock);
};

///
//  Configure a registered reader to ignore errors. If you do not set this,
//  then readers that have errors are removed from the reactor silently.   
void QmlZloop::readerSetTolerant (zsock_t *sock) {
    zloop_reader_set_tolerant (self, sock);
};

///
//  Register low-level libzmq pollitem with the reactor. When the pollitem  
//  is ready, will call the handler, passing the arg. Returns 0 if OK, -1   
//  if there was an error. If you register the pollitem more than once, each
//  instance will invoke its corresponding handler. A pollitem with         
//  socket=NULL and fd=0 means 'poll on FD zero'.                           
int QmlZloop::poller (zmq_pollitem_t *item, zloop_fn handler, void *arg) {
    return zloop_poller (self, item, handler, arg);
};

///
//  Cancel a pollitem from the reactor, specified by socket or FD. If both
//  are specified, uses only socket. If multiple poll items exist for same
//  socket/FD, cancels ALL of them.                                       
void QmlZloop::pollerEnd (zmq_pollitem_t *item) {
    zloop_poller_end (self, item);
};

///
//  Configure a registered poller to ignore errors. If you do not set this,
//  then poller that have errors are removed from the reactor silently.    
void QmlZloop::pollerSetTolerant (zmq_pollitem_t *item) {
    zloop_poller_set_tolerant (self, item);
};

///
//  Register a timer that expires after some delay and repeats some number of
//  times. At each expiry, will call the handler, passing the arg. To run a  
//  timer forever, use 0 times. Returns a timer_id that is used to cancel the
//  timer in the future. Returns -1 if there was an error.                   
int QmlZloop::timer (size_t delay, size_t times, zloop_timer_fn handler, void *arg) {
    return zloop_timer (self, delay, times, handler, arg);
};

///
//  Cancel a specific timer identified by a specific timer_id (as returned by
//  zloop_timer).                                                            
int QmlZloop::timerEnd (int timerId) {
    return zloop_timer_end (self, timerId);
};

///
//  Register a ticket timer. Ticket timers are very fast in the case where   
//  you use a lot of timers (thousands), and frequently remove and add them. 
//  The main use case is expiry timers for servers that handle many clients, 
//  and which reset the expiry timer for each message received from a client.
//  Whereas normal timers perform poorly as the number of clients grows, the 
//  cost of ticket timers is constant, no matter the number of clients. You  
//  must set the ticket delay using zloop_set_ticket_delay before creating a 
//  ticket. Returns a handle to the timer that you should use in             
//  zloop_ticket_reset and zloop_ticket_delete.                              
void *QmlZloop::ticket (zloop_timer_fn handler, void *arg) {
    return zloop_ticket (self, handler, arg);
};

///
//  Reset a ticket timer, which moves it to the end of the ticket list and
//  resets its execution time. This is a very fast operation.             
void QmlZloop::ticketReset (void *handle) {
    zloop_ticket_reset (self, handle);
};

///
//  Delete a ticket timer. We do not actually delete the ticket here, as    
//  other code may still refer to the ticket. We mark as deleted, and remove
//  later and safely.                                                       
void QmlZloop::ticketDelete (void *handle) {
    zloop_ticket_delete (self, handle);
};

///
//  Set the ticket delay, which applies to all tickets. If you lower the   
//  delay and there are already tickets created, the results are undefined.
void QmlZloop::setTicketDelay (size_t ticketDelay) {
    zloop_set_ticket_delay (self, ticketDelay);
};

///
//  Set hard limit on number of timers allowed. Setting more than a small  
//  number of timers (10-100) can have a dramatic impact on the performance
//  of the reactor. For high-volume cases, use ticket timers. If the hard  
//  limit is reached, the reactor stops creating new timers and logs an    
//  error.                                                                 
void QmlZloop::setMaxTimers (size_t maxTimers) {
    zloop_set_max_timers (self, maxTimers);
};

///
//  Set verbose tracing of reactor on/off
void QmlZloop::setVerbose (bool verbose) {
    zloop_set_verbose (self, verbose);
};

///
//  Start the reactor. Takes control of the thread and returns when the 0MQ  
//  context is terminated or the process is interrupted, or any event handler
//  returns -1. Event handlers may register new sockets and timers, and      
//  cancel sockets. Returns 0 if interrupted, -1 if cancelled by a handler.  
int QmlZloop::start () {
    return zloop_start (self);
};

///
//  Ignore zsys_interrupted flag in this loop. By default, a zloop_start will 
//  exit as soon as it detects zsys_interrupted is set to something other than
//  zero. Calling zloop_ignore_interrupts will supress this behavior.         
void QmlZloop::ignoreInterrupts () {
    zloop_ignore_interrupts (self);
};


QObject* QmlZloop::qmlAttachedProperties(QObject* object) {
    return new QmlZloopAttached(object);
}


///
//  Self test of this class
void QmlZloopAttached::test (bool verbose) {
    zloop_test (verbose);
};

///
//  Create a new zloop reactor
QmlZloop *QmlZloopAttached::construct () {
    QmlZloop *qmlSelf = new QmlZloop ();
    qmlSelf->self = zloop_new ();
    return qmlSelf;
};

///
//  Destroy a reactor
void QmlZloopAttached::destruct (QmlZloop *qmlSelf) {
    zloop_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/