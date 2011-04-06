#include <string.h>
#include <omnetpp.h>
#include "Package_m.h"

class Receiver : public cSimpleModule {
	private:
		simtime_t lastArrival;
		long numRecv;

	    // statistics
	    cDoubleHistogram iaTimeHistogram;
	    cOutVector arrivalsVector;
	    cOutVector sizesVector;

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual void updateDisplay();
		virtual void finish();
};

Define_Module(Receiver);

void Receiver::initialize() {
	lastArrival = 0.0;
	numRecv = 0;
    iaTimeHistogram.setName("interarrival times");
    arrivalsVector.setName("arrivals");
    sizesVector.setName("sizes");
    arrivalsVector.setInterpolationMode(cOutVector::NONE);
}

void Receiver::handleMessage(cMessage *msg) {
	// count interval;
	simtime_t interval = simTime() - lastArrival;
	EV << "Package arrived at " << simTime() << " interval between previous and actual: " << interval << "\n";

	// take message
	Package *package = check_and_cast<Package*>(msg);
	numRecv++;

	// store data in vector
	iaTimeHistogram.collect(interval);
	arrivalsVector.record(interval);
	sizesVector.record(package -> getSize());

	delete msg;

	//set last arrival time
	lastArrival = simTime();

	// generate bubble with counter
	if (ev.isGUI())
	            updateDisplay();
}

void Receiver::updateDisplay()
{
	// refresh bubble with counter
    char buf[40];
    sprintf(buf, "received: %ld", numRecv);
    getDisplayString().setTagArg("t",0,buf);
}

void Receiver::finish()
{
    recordStatistic(&iaTimeHistogram);
}
