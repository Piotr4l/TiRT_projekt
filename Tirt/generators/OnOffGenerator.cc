#include <string.h>
#include <omnetpp.h>
#include "Package_m.h"

class OnOffGenerator : public cSimpleModule {
	public:
		cMessage *msg;
		Package *package;
		simtime_t delay;
		double offInterval;
		int switchingInterval;
		int index;
		int packetId;

	private:
		long numSent;

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual Package *generateMessage();
		virtual void updateDisplay();
};

Define_Module(OnOffGenerator);

void OnOffGenerator::initialize() {
	// set first send packedId
	packetId = 0;
	index = 0;

	// initialize variables from ned configuration
	delay = par("delay");
	switchingInterval = par("switchingInterval");
	offInterval = par("offInterval");

    // Initialize packets tracking
    numSent = 0;
    WATCH(numSent);

    // initialize sending packets
	msg = new cMessage("Example");
	scheduleAt(simTime(), msg);
}

void OnOffGenerator::handleMessage(cMessage *msg) {
	delay = par("delay");
	switchingInterval = par("switchingInterval");
	offInterval = par("offInterval");

	if( msg->isSelfMessage()) {
		send(generateMessage(),"out");
		EV << "Packet send at: " << simTime() << " packedId: " << packetId << "\n";
		numSent++;
	}

	index++;

	if(index < switchingInterval){
		scheduleAt(simTime() + delay, msg);
	}
	else {
		index = 0;
		EV << "Off state at: " << simTime() << "\n";
		bubble("generator is off");
		scheduleAt(simTime() + delay + offInterval, msg);
	}

	// generate bubble with counter
	if (ev.isGUI())
	            updateDisplay();
}

Package *OnOffGenerator::generateMessage(){
	//create and set values in new message
		Package *package = new Package("");
		package->setSource("source");
		package->setDestination("destination");
		package->setDuration(par("duration"));
		package->setPriority(par("priority"));
		package->setSessionId(par("sessionId"));
		package->setPacketId(packetId++);
	//return value
		return package;
}

void OnOffGenerator::updateDisplay()
{
	// refresh bubble with counter
    char buf[40];
    sprintf(buf, "sent: %ld",  numSent);
    getDisplayString().setTagArg("t",0,buf);
}

