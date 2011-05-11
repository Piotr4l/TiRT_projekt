#include <omnetpp.h>
#include <Package_m.h>

class TrafficShaper : public cSimpleModule
{
private:
	cMessage *event;

	double delay; //predkosc naplywania zetonow / predkosc wysylania pakietow / predkosc zmniejszania licznika
	cQueue queue; //kolejka uzywana przez tokenBucket, i leakyBucket

	//tokenBucket
	int limit; //maksymalna liczba pakietów oczekuj¹cych równoczeœnie na przydzia³ ¿etonu
	int tokens; //aktualna liczba zetonow
	int maxTokens;

	//leakyBucket
	int queueMaxSize;

	//leakyBucket2
	int counter;
	int threshold;

	//int borderPriority;

protected:
	void initialize();
	void handleMessage(cMessage *msg);
	void updateDisplay();

	void addPackage(Package *pk);
	void leakyBucket();

	void decrementCounter();
	void incrementCounter(Package *pk);

	void tokenBucket(Package *pk);
	void addToken();
	void sendPackages();
};

Define_Module(TrafficShaper);

void TrafficShaper::initialize() {
	event = new cMessage();

	delay = 5; //	delay = 15;

	limit = 10;// limit by 5
	maxTokens = 50;
    tokens = maxTokens;

    queueMaxSize = 8; //queueMaxSize = 5;

    counter = 0;
    threshold = 10;

    scheduleAt(simTime()+delay, event);
}

void TrafficShaper::handleMessage(cMessage *msg) {

	if(msg->isSelfMessage()) {

		addToken();
		//leakyBucket();
		//decrementCounter();

	} else {

		Package *pk = check_and_cast<Package *>(msg);

		tokenBucket(pk);
		//addPackage(pk);
		//incrementCounter(pk);

	}

	if (ev.isGUI()) updateDisplay();
}

void TrafficShaper::updateDisplay() {
    char string[40];
    sprintf(string, "queueSize: %d\ntokens: %d\ncounter: %d", queue.length(), tokens, counter);

    getDisplayString().setTagArg("t", 0, string);
}

void TrafficShaper::addPackage(Package *pk) {
	if(queue.length()<queueMaxSize) {
		queue.insert(pk);
	} else {
		send(pk, "out2");
	}
}

void TrafficShaper::leakyBucket() {
	scheduleAt(simTime()+delay, event);

	if(!queue.empty()) {
		send((cMessage *)(queue.pop()), "out1");
	}
}

void TrafficShaper::decrementCounter() {
	scheduleAt(simTime()+delay, event);
	if(counter > 0) counter--;
}
void TrafficShaper::incrementCounter(Package *pk) {
	if(counter < threshold) {
		send(pk, "out1");
		counter++;
	} else {
		send(pk, "out2");
	}
}

void TrafficShaper::tokenBucket(Package *pk) {
	//int size = pk->getSize();

	if(queue.length()<queueMaxSize) {
		queue.insert(pk);
		sendPackages();
	} else {
		//send((cMessage *)(queue.pop()), "out2");
		//queue.insert(pk);
		send(pk, "out2");
	}

	/*if(tokens >= size) {
		send(pk, "out1");
		tokens -= size;
	} else {
		send(pk, "out2");
	}*/
}
void TrafficShaper::addToken() {
	scheduleAt(simTime()+delay, event);

	sendPackages();

	if(tokens < maxTokens) tokens++;
}

void TrafficShaper::sendPackages() {
	while(!queue.empty() && tokens >= check_and_cast<Package *>(queue.front())->getSize()) {
		tokens -= check_and_cast<Package *>(queue.front())->getSize();
		send((cMessage *)(queue.pop()), "out1");
	}
}
