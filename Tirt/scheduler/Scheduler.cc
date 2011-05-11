#include <omnetpp.h>
#include <Package_m.h>

class Scheduler: public cSimpleModule {

private:
	// variables
	int RRcount;
	int WRRcount;
	int W1;
	int W2;
	int W3;
	int W4;
	SimTime timescope;

	// scheduler types
	virtual void handleRoundRobin(Package *pk);
	virtual void handleWeightedRoundRobin(Package *pk);
	virtual void handleRandom(Package *pk);
	virtual void handleWeightedRandom(Package *pk);

public:
	Scheduler();
	virtual ~Scheduler();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
};
Define_Module(Scheduler);

Scheduler::Scheduler(){}

Scheduler::~Scheduler(){}

void Scheduler::initialize()
{
    RRcount = 0;
    WRRcount = 0;
    W1 = 1;
    W2 = 2;
    W3 = 3;
    W4 = 4;
}

void Scheduler::handleMessage(cMessage *msg)
{
	int type = par("type");
	Package *pk = check_and_cast<Package *> (msg);

	switch(type){
	case 1:
		handleRoundRobin(pk);
		break;
	case 2:
		handleWeightedRoundRobin(pk);
		break;
	case 3:
		handleRandom(pk);
		break;
	case 4:
		handleWeightedRandom(pk);
		break;
	default:
		handleRandom(pk);
		break;
	}
}

void Scheduler::handleRoundRobin(Package *pk)
{
	if(RRcount==0) send(pk, "out0");
	else if (RRcount==1) send(pk, "out1");
	else if (RRcount==2) send(pk, "out2");
	else send(pk, "out3");
	RRcount = (RRcount+1)%4;
}

void Scheduler::handleWeightedRoundRobin(Package *pk)
{
	if(WRRcount < W1) send(pk, "out0");
	else if(WRRcount < (W1+W2)) send(pk, "out1");
	else if(WRRcount < (W1+W2+W3)) send(pk, "out2");
	else if(WRRcount < (W1+W2+W3+W4)) send(pk, "out3");
	WRRcount = (WRRcount+1)%(W1+W2+W3+W4);
}

void Scheduler::handleRandom(Package *pk)
{
	int rand = (int)intrand(4);
	if(rand == 0) send(pk, "out0");
	else if(rand == 1) send(pk, "out1");
	else if(rand == 2) send(pk, "out2");
	else if(rand == 3) send(pk, "out3");
}

void Scheduler::handleWeightedRandom(Package *pk)
{
	int rand = (int)intrand(W1+W2+W3+W4);
	if(rand < W1) send(pk, "out0");
	else if(rand < (W1+W2)) send(pk, "out1");
	else if(rand < (W1+W2+W3)) send(pk, "out2");
	else if(rand < (W1+W2+W3+W4)) send(pk, "out3");
}
