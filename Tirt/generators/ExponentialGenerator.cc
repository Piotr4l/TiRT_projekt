#include <string.h>
#include <omnetpp.h>
#include "Package_m.h"

class ExponentialGenerator : public cSimpleModule {
	public:
		cMessage *msg;
		simtime_t delay;
		int packetId;
		double alfa;

	private:
		long numSent;

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual Package *generateMessage();
		virtual void updateDisplay();
};

Define_Module(ExponentialGenerator);

void ExponentialGenerator::initialize() {

	// set first send packedId
	packetId = 0;

	// initialize variables from ned configuration
	delay = par("delay");
	alfa = par("alfa");

    // Initialize packets tracking
    numSent = 0;
    WATCH(numSent);

    int genType = par("genType");

    if(genType == 1){
    	// initialize sending packets
    	msg = new cMessage("Example");
    	scheduleAt(simTime(), msg);
    }
}

void ExponentialGenerator::handleMessage(cMessage *msg) {

	delay = par("delay");
	alfa = par("alfa");

	if(msg->isSelfMessage()) {
		//send message
		send(generateMessage(),"out");
		numSent++;

		//put info in console
		EV << "Packet send at: " << simTime() << " packedId: " << packetId << "\n";
		
		// set expotential delay time
		int temp = exponential(alfa);
		scheduleAt(simTime() + delay + temp, msg);
		
		// generate bubble with counter
		if (ev.isGUI())
		{
			updateDisplay();
		}

	} else {
		bubble("Somethings wrong message lost");
	}
}

Package *ExponentialGenerator::generateMessage(){
	//create and set values in new message
		Package *package = new Package("");
		package->setSource(1001);
		package->setDestination(1002);
		package->setDuration(par("duration"));
		package->setSessionId(par("sessionId"));
		package->setPacketId(packetId++);
		package->setIsAccepted(false);
		package->setPriority(intuniform(par("minPrio"),par("maxPrio")));
		package->setSize(intuniform(par("minSize"),par("maxSize")));

		return package;
}

void ExponentialGenerator::updateDisplay()
{
	// refresh bubble with counter
    char buf[40];
    sprintf(buf, "sent: %ld",  numSent);
    getDisplayString().setTagArg("t",0,buf);
}
