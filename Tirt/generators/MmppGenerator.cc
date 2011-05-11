#include <string.h>
#include <omnetpp.h>
#include "Package_m.h"

class MmppGenerator : public cSimpleModule {
	public:
		cMessage *msg;
		Package *package;
		simtime_t delay;
		double offInterval;
		int switchingInterval;
		int index;
		int packetId;
		int state;

	private:
		long numSent;

	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
		virtual Package *generateMessage();
		virtual void updateDisplay();
};

Define_Module(MmppGenerator);

void MmppGenerator::initialize() {
	state = 1;

	// set first send packedId
	packetId = 0;
	index = 0;

	// initialize variables from ned configuration
	delay = poisson(par("lambda1"));
	switchingInterval = par("switchingInterval");
	offInterval = par("offInterval");

    // Initialize packets tracking
    numSent = 0;
    WATCH(numSent);

    int genType = par("genType");

    if(genType == 2){
    	// initialize sending packets
    	msg = new cMessage("Example");
    	scheduleAt(simTime(), msg);
    }
}

void MmppGenerator::handleMessage(cMessage *msg) {
	delay = poisson(par("lambda1"));
	switchingInterval = par("switchingInterval");
	offInterval = par("offInterval");

	if(state!=0 && msg->isSelfMessage()) {
		package = generateMessage();

		if(state == 1) {
			package -> setSize(par("size1"));
		} else {
			package -> setSize(par("size2"));
		}

		send(package,"out");
		EV << "Packet send at: " << simTime() << " packedId: " << packetId << "\n";
		numSent++;
	}

	index++;

	if(index < switchingInterval){
		scheduleAt(simTime() + delay, msg);
	}
	else {
		index = 0;

		double p = uniform(0,1);

		if(p > 0 && p<par("on1").doubleValue()) {
			state = 1;
			EV << "On1 state at: " << simTime() << "\n";
			bubble("generator is on1");
		} else if(p>par("on1").doubleValue() && p<par("on1").doubleValue()+par("on2").doubleValue()) {
			state = 2;
			EV << "On2 state at: " << simTime() << "\n";
			bubble("generator is on2");
		} else {
			state = 0;
			EV << "Off state at: " << simTime() << "\n";
			bubble("generator is off");
		}

		if(state == 0) {
			delay = par("offInterval");
			index = switchingInterval;
		} else if(state == 1) {
			delay = poisson(par("lambda1"));
		} else {
			delay = poisson(par("lambda2"));
		}

		scheduleAt(simTime() + delay, msg);
	}

	// generate bubble with counter
	if (ev.isGUI())
	            updateDisplay();
}

Package *MmppGenerator::generateMessage(){
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
	//return value
		return package;
}

void MmppGenerator::updateDisplay()
{
	// refresh bubble with counter
    char buf[40];
    sprintf(buf, "sent: %ld",  numSent);
    getDisplayString().setTagArg("t",0,buf);
}

