#include <string.h>
#include <omnetpp.h>
#include "Package_m.h"

class PoissonGenerator : public cSimpleModule {
	public:
		cMessage *msg;
		Package *package;
		simtime_t delay;
		long numSent;
		int lambda;
		int packetId;
		int state;

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual Package *generateMessage();
		virtual void updateDisplay();
};

Define_Module(PoissonGenerator);

void PoissonGenerator::initialize() {
	// set first send packedId
	packetId = 0;

	// initialize variables from ned configuration
	delay = par("delay");
	lambda = par("lambda");

    // Initialize packets tracking
    numSent = 0;
    WATCH(numSent);

    // initialize sending packets
	msg = new cMessage("Example");
	scheduleAt(simTime(), msg);
}

void PoissonGenerator::handleMessage(cMessage *msg) {
	delay = par("delay");
	lambda = par("lambda");
	if(msg->isSelfMessage()) {
		//send message
		send(generateMessage(),"out");
		numSent++;

		//put info in console
		EV << "Packet send at: " << simTime() << " packedId: " << packetId << "\n";
		
		// set poisson delay time
		int temp = poisson(lambda);
		scheduleAt(simTime() + delay + temp, msg);

		// generate bubble with counter
		if (ev.isGUI())
		            updateDisplay();
	}
	else
	{
		bubble("Somethings wrong message lost");
	}
}

Package *PoissonGenerator::generateMessage(){
	//create and set values in new message
		Package *package = new Package("");
		package->setSource(1000);
		package->setDestination(1001);
		package->setDuration(par("duration"));
		package->setPriority(par("priority"));
		package->setSessionId(par("sessionId"));
		package->setPacketId(packetId++);
		package->setSize(par("size"));
	//return value
		return package;
}

void PoissonGenerator::updateDisplay()
{
	// refresh bubble with counter
    char buf[40];
    sprintf(buf, "sent: %ld",  numSent);
    getDisplayString().setTagArg("t",0,buf);
}

