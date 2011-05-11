#include <omnetpp.h>
#include <Package_m.h>

class AdmissionControl: public cSimpleModule {

private:

	// admission control algorithms
	virtual bool algPriorityBased(Package *pk);
	virtual bool algRED(Package *pk);
	virtual bool algWeightedRED(Package *pk);
	virtual bool algLongTail(Package *pk);

	int count;
	int prevCount;
	SimTime timescope;

public:
	AdmissionControl();
	virtual ~AdmissionControl();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);

};

Define_Module(AdmissionControl);

AdmissionControl::AdmissionControl() {
}

AdmissionControl::~AdmissionControl() {
}

void AdmissionControl::initialize()
{
	count = 0;
	prevCount = 0;
	timescope = simTime();
}


void AdmissionControl::handleMessage(cMessage *msg)
{
	// get the type of admission control
	int type = par("type");

	// cast package
	Package *pk = check_and_cast<Package *> (msg);

	bool isAccepted;

	// chose selected algorithm
	switch(type)
	{
		case 1:
			isAccepted = algPriorityBased(pk);
			break;
		case 2:
			isAccepted = algRED(pk);
			break;
		case 3:
			isAccepted = algWeightedRED(pk);
			break;
		case 4:
			isAccepted = algLongTail(pk);
			break;
		default:
			isAccepted = true;
	}

	// if accepted then send message accepted
	if (isAccepted) {
		pk->setIsAccepted(true);
		send(pk, "out1");
	}
	else
	{
		send(pk, "out2");
	}

}

bool AdmissionControl::algPriorityBased(Package *pk)
{

	// get min priority to get the package
	int minPrio = par("minPrority");

	// get priroty and chose if allow  access
	int packetPriority = pk->getPriority();

	if (packetPriority > minPrio)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AdmissionControl::algRED(Package *pk)
{

	int timeRange = 10;
	int tresholds[] = {3,10,20};
	int probabilities[] = {10,20,30,40};

	if(timescope+timeRange>simTime()){
		count++;
	}
	else{
		prevCount = count;
		count = 0;
		timescope = simTime();
	}

	int rnda = uniform(0, 100);

	if(prevCount<tresholds[0])
	{
		if(rnda>probabilities[0])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(prevCount>=tresholds[0] && prevCount < tresholds[1])
	{
		if(rnda>probabilities[1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(prevCount>=tresholds[1] && prevCount <tresholds[2])
	{
		if(rnda>probabilities[2])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(rnda>probabilities[3])
	{
	    return true;
	}
	else
	{
		return false;
	}
}

bool AdmissionControl::algWeightedRED(Package *pk)
{
	return true;
}

bool AdmissionControl::algLongTail(Package *pk){

	int timeRange = 10;
	int treshold = 5;
	if(timescope+timeRange>simTime()){
		count++;
	}
	else{
		prevCount = count;
		count = 0;
		timescope = simTime();
	}

	if(prevCount>treshold) return false;
	else return true;
}

