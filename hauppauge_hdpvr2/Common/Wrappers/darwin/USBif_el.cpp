#include "USBif.h"

void* USBWrapper_t::eventLoopCallback(void *ctx) {
	USBWrapper_t *usb = (USBWrapper_t*)ctx;
	IOReturn r;
	CFRunLoopRef runloop;

//	pthread_setname_np ("org.AVcap.usbEventLoop");
//	objc_registerThreadWithCollector();

	CFRunLoopSourceRef n_cfsource;

	runloop = CFRunLoopGetCurrent();
	CFRetain(runloop);

	r = (*usb->m_interfaceI)->CreateInterfaceAsyncEventSource(usb->m_interfaceI, &n_cfsource);
	CFRunLoopAddSource(runloop, n_cfsource, kCFRunLoopDefaultMode);

	pthread_mutex_lock(&usb->eventLoopMutex);
	usb->eventLoopObj = runloop;
	pthread_cond_signal(&usb->eventLoopCond);
	pthread_mutex_unlock(&usb->eventLoopMutex);

	CFRunLoopRun();

	CFRunLoopRemoveSource(runloop, n_cfsource, kCFRunLoopDefaultMode);

	usb->eventLoopObj = NULL;
	CFRelease(runloop);
	pthread_exit(NULL);
}

void USBWrapper_t::startEventLoop() {
	if(eventLoopObj) return;
	pthread_mutex_init(&eventLoopMutex, NULL);
	pthread_cond_init(&eventLoopCond, NULL);
	pthread_create(&eventLoop, NULL, eventLoopCallback, (void*)this);

	pthread_mutex_lock(&eventLoopMutex);
	while(!eventLoopObj) pthread_cond_wait(&eventLoopCond, &eventLoopMutex);
	pthread_mutex_unlock(&eventLoopMutex);
}

void USBWrapper_t::stopEventLoop() {
	if(!eventLoopObj) return;
	CFRunLoopStop(eventLoopObj);
	pthread_join(eventLoop, NULL);
	pthread_cond_destroy(&eventLoopCond);
	pthread_mutex_destroy(&eventLoopMutex);
}
